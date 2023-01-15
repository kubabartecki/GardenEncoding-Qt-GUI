#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>

//my modules
#include"file.h"
#include"fileread.h"
#include"filesave.h"
#include"mylabel.h"
#include"array"
#include"boolarray.h"
#include"mylabelarray.h"
#include"coding.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int get_side_file();

protected:
    void addLabelsToGrid();
    void setLabelNameFromFile(QLabel *label, File *file);
    void readCodeSave(Array * arr);
    QString serviceEncoding(Array * arr);
    void serviceDecoding(Array * arr, QString code_original);
    void multiFiles(bool kod);

private slots:
    void on_spinBoxPotega_valueChanged(int arg1);

    void on_pushButtonOpenFile_clicked();

    void on_pushButtonSaveFile_clicked();

    void on_radioButtonKod_clicked();

    void on_radioButtonDekod_clicked();

    void on_pushButtonKodDekod_clicked(bool checked);

private:
    Ui::MainWindow *ui;

    int power_file;
    int power_manual;
    int power_initial;
    int current_power;

    int current_side;
    int side_file;
    int side_manual;
    int side_initial;
    Array *array;

    //Files
    File *file;
    FileRead fileRead;
    FileSave fileSave;

    //Coding
    Coding * coding;
};
#endif // MAINWINDOW_H
