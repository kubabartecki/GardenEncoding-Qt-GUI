#include "fileread.h"

FileRead::FileRead()
{
    dir.setCurrent(".");
    //create directory
    if (!dir.exists(sample_path)){
        dir.mkdir(sample_path);
    }

    dir.cd(sample_path);
    current_file = dir.absolutePath() + "/sample_code.txt";
    QFile file(current_file);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file);
    out << "2 #1011";
    file.close();

    current_file = dir.absolutePath() + "/sample_field.txt";
    file.setFileName(current_file);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out2(&file);
    out2 << "2\n"
           "1100\n"
           "1100\n"
           "1111\n"
           "1111";
    file.close();
}

void FileRead::readField(Array *array, QWidget *parent){
    QFile file(current_file);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(parent, "Warning", "Błąd z plikiem do odczytu");
        return;
    }

    QTextStream in(&file);
    int power = in.readLine(1).toInt();
    if((power > 15) || (power < 1)){
        QMessageBox::warning(parent, "Ostrzeżenie", "Nieodpowiednia potęga");
        file.close();
        throw std::exception();
    }

    int side = pow(2, power);

    in.readLine(); // to skip 1 line
    for(int i = 0; i < side; i++){
        QString row = in.readLine();
        for(int j = 0; j < side; j++){
            if('0' == row[j]){
                array->set_value(i, j, false);
            }
            else if('1' == row[j]){
                array->set_value(i, j, true);
            }
            else{
                QMessageBox::warning(parent, "Ostrzeżenie", "W polu znaki różne od '1', '0'");
                file.close();
                throw std::exception();
            }
        }
    }
    file.close();
}

QString FileRead::readCode(){
    QFile file(current_file);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(nullptr, "Warning", "Błąd z plikiem do odczytu");
        return "";
    }
    QTextStream in(&file);
    QString code = in.readLine();
    file.close();
    return code;
}

void FileRead::getName(QWidget *parent){
    QString fileName = QFileDialog::getOpenFileName(parent, "Wybierz plik", "", "Pliki tekstowe (*.txt)");
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(parent, "Ostrzeżenie", "Nie wybrano pliku do odczytu");
        return;
    }
    current_file = fileName;
    file.close();
}

int FileRead::powerRead(QWidget *parent){

    QFile file(current_file);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(parent, "Warning", "Błąd z plikiem do odczytu");
        return 0;
    }

    QTextStream in(&file);
    QString power = in.readLine().split(" ")[0];

    file.close();

    return power.toInt();
}

void FileRead::readMultiField(QString dest_file, QWidget *parent)
{
    QFile file(current_file);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(parent, "Warning", "Błąd z plikiem do odczytu");
        return;
    }

    QTextStream in(&file);

    FileSave fileSave;
    fileSave.set_current_file(dest_file);
    //delete content first
    fileSave.cleanFile();

    while(!in.atEnd()){        
        int power = in.readLine().toInt();
        if((power > 15) || (power < 1)){
            QMessageBox::warning(parent, "Ostrzeżenie", "Nieodpowiednia potęga");
            file.close();
            throw std::exception();
        }
        int side = pow(2, power);

        Array * arr = new BoolArray(power);
        for(int i = 0; i < side; i++){
            QString row = in.readLine();
            for(int j = 0; j < side; j++){
                if('0' == row[j]){
                    arr->set_value(i, j, false);
                }
                else if('1' == row[j]){
                    arr->set_value(i, j, true);
                }
                else{
                    QMessageBox::warning(parent, "Ostrzeżenie", "W polu znaki różne od '1', '0'");
                    delete arr;
                    file.close();
                    throw std::exception();
                }
            }
        }
        Coding *coding = new Coding(arr);
        QString result_of_coding = coding->startCoding();
        delete coding;

        fileSave.saveMultiCode(result_of_coding);
        delete arr;
        in.readLine();// to skip \n
    }
    file.close();
}

void FileRead::readMultiCode(QString dest_file, QWidget *parent){
    QFile file(current_file);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(parent, "Warning", "Błąd z plikiem do odczytu");
        return;
    }
    QTextStream in(&file);

    //delete content first
    FileSave fileSave;
    fileSave.set_current_file(dest_file);
    fileSave.cleanFile();

    while(!in.atEnd()){
        QString code = in.readLine();
        int power = code.split(" ")[0].toInt();
        if((power > 15) || (power < 1)){
            QMessageBox::warning(parent, "Ostrzeżenie", "Nieodpowiednia potęga");
            file.close();
            throw std::exception();
        }

        Array * arr = new BoolArray(power);
        Coding *coding = new Coding(arr, code.split(" ").last());// to skip spaces
        coding->startDecoding(parent);
        delete coding;

        fileSave.saveMultiField(arr);
        delete arr;
    }
    file.close();
}
