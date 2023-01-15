#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //nazwa i ikona aplikacji
    setWindowTitle("Ogródek Królewny");
    setWindowIcon(QIcon("://img/img/rad-cut.png"));

    //staly roziar
    setFixedSize(size());

    //select tab and radioButton
    ui->radioButtonKod->setChecked(1);
    ui->tabWidget->setCurrentIndex(0);

    //
    power_file = 0;
    power_manual = 2;
    current_power = power_initial = 2;
    side_file = 1;
    side_manual = 4;

    //initial grid
    side_initial = 4;
    current_side = side_initial;

    //tu konstrutkor
    array = new MyLabelArray(power_initial);

    addLabelsToGrid();

    // grid design
    ui->gridLayout->setSpacing(2);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete array;
}

int MainWindow::get_side_file(){
    return side_file;
}

void MainWindow::addLabelsToGrid(){

    for(int i = 0; i < array->get_side(); i++){
        for(int j = 0; j < array->get_side(); j++){
            ui->gridLayout->addWidget(array->get_array_pointer()[i][j], i, j);
        }
    }
}

void MainWindow::setLabelNameFromFile(QLabel *label, File *file){
    QString last_str = file->get_current_file().split("/").last();
    label->setText(last_str);
}

void MainWindow::readCodeSave(Array * arr)
{
    bool kod = ui->radioButtonKod->isChecked();
    bool dekod = ui->radioButtonDekod->isChecked();


        if(kod){
            //to da do click i zmieni obraz labeli
            try{
                fileRead.readField(arr, this);

                //encoding :)       //free from exception
                QString result = serviceEncoding(arr);

                //zapis do pliku
                fileSave.saveCode(result);
            }catch(const std::exception &er){
                QMessageBox::warning(this, "Błąd", "Podano nieodpowiednie dane\nWzór: <potęga><enter><pole z wartościami>");
                throw;
            }
        }
        else if(dekod){
            QString code_original = fileRead.readCode();
            ui->plainTextEdit->setPlainText(code_original);
            try{
                serviceDecoding(arr, code_original);
                fileSave.saveField(arr);
            }catch(const std::exception &er){
                QMessageBox::warning(this, "Błąd", "Podano nieodpowiednie dane\nWzór: <liczba(od 1 do 6)><spacja><kod ze znaków \"#01\">");
                throw;
            }
        }
}

QString MainWindow::serviceEncoding(Array * arr)
{
    //encoding :)
    coding = new Coding(arr);
    QString result_of_coding = coding->startCoding();
    ui->plainTextEdit->setPlainText(result_of_coding);

    delete coding;
    return result_of_coding;
}

void MainWindow::serviceDecoding(Array *arr, QString code_original)
{   try{
        QStringList list = code_original.split("\n")[0].split(" "); //power and code

        if(list.count() == 1){
            QMessageBox::warning(this, "Błąd", "Podano nieodpowiednie dane: brak spacji");
            throw std::invalid_argument( "Otrzymano błędny ciąg znaków" );
        }

        QString code = list[1].split("\n")[0]; // extract only code

        //decoding :)
        coding = new Coding(arr, code);
        coding->startDecoding(this);

        QString code_final = (QString)list[0][0] + " " + code + "\nIlość rzodkiewek: " + QString::number(arr->get_number_of_radishes());
        ui->plainTextEdit->setPlainText(code_final);
    }catch(const std::invalid_argument& e ){
        throw;
     }catch(const std::exception &er){
        delete coding;
        throw;
     }

    delete coding;
}

void MainWindow::multiFiles(bool kod)
{
    if(kod)
        fileRead.readMultiField(fileSave.get_current_file(), this);
    else
        fileRead.readMultiCode(fileSave.get_current_file(), this);
}


void MainWindow::on_spinBoxPotega_valueChanged(int arg1)
{
    side_manual = pow(2, arg1);
    ui->label_bok->setText(QString::number(side_manual));
    current_side = side_manual = arg1;

    current_power = arg1;
    delete array;
    array = new MyLabelArray(current_power);
    addLabelsToGrid();
}

void MainWindow::on_pushButtonOpenFile_clicked()
{
    file = &fileRead;
    file->getName(this);
    setLabelNameFromFile(ui->label_open_file, file);
}


void MainWindow::on_pushButtonSaveFile_clicked()
{
    file = &fileSave;
    file->getName(this);
    setLabelNameFromFile(ui->label_save_file, file);
}


void MainWindow::on_radioButtonKod_clicked()
{
    ui->pushButtonKodDekod->setText("Koduj");
}


void MainWindow::on_radioButtonDekod_clicked()
{
    ui->pushButtonKodDekod->setText("Dekoduj");
}


void MainWindow::on_pushButtonKodDekod_clicked(bool checked)
{
    // 0 - first tab(file) , 1 - second tab(manual)
    int tab_index = ui->tabWidget->currentIndex();

    bool kod = ui->radioButtonKod->isChecked();
    bool dekod = ui->radioButtonDekod->isChecked();

    if(!kod && !dekod){
        QMessageBox::warning(this, "Ostrzeżenie", "Nie wybrano opcji kodowania");
        return;
    }

    //do opcji 0-file
    if(0 == tab_index){
        if(fileRead.get_current_file() == ""){
            QMessageBox::warning(this, "Ostrzeżenie", "Nie wybrano pliku do odczytu");
            return;
        }
        else if(fileSave.get_current_file() == ""){
            QMessageBox::warning(this, "Ostrzeżenie", "Nie wybrano pliku do zapisu");
            return;
        }

        //tu opcja z wieloma plikami
        if(ui->checkBox_multi->isChecked()){
            try{
                multiFiles(kod);
                QMessageBox::information(this, "Zapis w pliku", "Wynik zostanie zapisany w wybranym pliku");
            }catch(std::exception &er){
                QMessageBox::warning(this, "Błąd", "Podano nieodpowiednie dane");
            }
            return;
        }

        current_power = power_file = fileRead.powerRead(this);

        if( (current_power < 7) && (current_power > 0) ){

            delete array;
            array = new MyLabelArray(current_power);

            addLabelsToGrid();
            try{
                readCodeSave(array);
            }catch(const std::exception &er){}
        }
        else if ((current_power < 16) && (current_power > 0)){
            //tu gdy 16 > pow >= 7
            //to samo do pliku tylko z tablica bool
            Array * arr = new BoolArray(current_power);
            //try catch here to not pop messageBox after error
            try{
                readCodeSave(arr);
                QMessageBox::information(this, "Zapis w pliku", "Za duży rozmiar pola, wynik zostanie zapisany w wybranym pliku");
            }catch(const std::exception &er){}

            delete arr;
        }
        else if(current_power >= 16){
            QMessageBox::warning(this, "Odmowa dostępu", "Za duży rozmiar pola");
            return;
        }
        else{
            QMessageBox::warning(this, "Odmowa dostępu", "Niepoprawne dane w pliku");
            return;
        }
    }
    // do opcji 1-manual
    else if(1 == tab_index){
        if(kod){
            //zbierz info z array // code z array //zapisz wynik do polatxt i nie usuwaj array
            serviceEncoding(array);
        }
        else if(dekod){
            //zbierz info z polatxt
            QString code_original = ui->plainTextEdit->toPlainText();

            //change QChar to int ('0' = 48)
            int p = QVariant(code_original[0]).toInt() - 48;
            if( (p < 7) && (p > 0) ){
                ui->spinBoxPotega->setValue(p);
            try{
                serviceDecoding(array, code_original);
            }catch(const std::exception &er){
                    QMessageBox::warning(this, "Błąd", "Podano nieodpowiednie dane\nWzór: <liczba(od 1 do 6)><spacja><kod ze znaków \"#01\">");
             }
            }
            else{
                QMessageBox::information(this, "Odmowa dostępu", "Za duży rozmiar pola lub złe dane: potęga");
            }
        }
    }
}
