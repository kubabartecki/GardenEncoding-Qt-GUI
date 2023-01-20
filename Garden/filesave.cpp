#include "filesave.h"

FileSave::FileSave()
{
    dir.setCurrent(".");
    dir.cd(sample_path);
    current_file = dir.absolutePath() + "/sample_output.txt";
    QFile file(current_file);
    file.open(QFile::WriteOnly | QFile::Text);
    file.close();
}

void FileSave::getName(QWidget *parent){
    QString fileName = QFileDialog::getSaveFileName(parent, "Zapisz do", "", "Pliki tekstowe (*.txt)");
    QFile file(fileName);

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(parent, "Ostrzeżenie", "Nie wybrano pliku do zapisu");
        return;
    }
    current_file = fileName;
    file.close();
}

void FileSave::saveCode(QString code){
    QFile file(current_file);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(nullptr, "Warning", "Błąd z plikiem do zapisu");
        return;
    }

    QTextStream out(&file);
    out << code;

    file.close();
}

void FileSave::saveField(Array *array)
{
    QFile file(current_file);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(nullptr, "Warning", "Błąd z plikiem do zapisu");
        return;
    }

    QTextStream out(&file);
    out << QString::number(array->get_power());
    int side = array->get_side();
    out << "\n";

    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            if(array->get_bool_value(i, j)) out << "1";
            else out << "0";
        }
        out << "\n";
    }
    file.close();
}

void FileSave::saveMultiCode(QString code)
{
    QFile file(current_file);
    if(!file.open(QFile::WriteOnly | QIODevice::Append | QFile::Text)){
        QMessageBox::warning(nullptr, "Warning", "Błąd z plikiem do zapisu");
        return;
    }

    QTextStream out(&file);
    out << code << "\n";

    file.close();
}

void FileSave::saveMultiField(Array *array)
{
    QFile file(current_file);
    if(!file.open(QFile::WriteOnly | QIODevice::Append | QFile::Text)){
        QMessageBox::warning(nullptr, "Warning", "Błąd z plikiem do zapisu");
        return;
    }

    QTextStream out(&file);
    out << QString::number(array->get_power());
    int side = array->get_side();
    out << "\n";

    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            if(array->get_bool_value(i, j)) out << "1";
            else out << "0";
        }
        out << "\n";
    }
    out << "\n";
    file.close();
}

void FileSave::cleanFile(){
    QFile file(current_file);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(nullptr, "Warning", "Błąd z plikiem do zapisu");
        return;
    }
    file.close();
}
