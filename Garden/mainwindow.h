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
#include"descriptions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

///
/// \brief The MainWindow class
///
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ///
    /// \brief MainWindow
    /// \param parent
    ///
    MainWindow(QWidget *parent = nullptr);

    ///
    ///
    ///
    ~MainWindow();

    ///
    /// \brief get_side_file
    /// \return
    ///
    int get_side_file();

protected:
    ///
    /// \brief addLabelsToGrid
    ///
    void addLabelsToGrid();
    ///
    /// \brief setLabelNameFromFile
    /// \param label
    /// \param file
    ///
    void setLabelNameFromFile(QLabel *label, File *file);
    ///
    /// \brief readCodeSave
    /// \param arr
    ///
    void readCodeSave(Array * arr);
    ///
    /// \brief serviceEncoding
    /// \param arr
    /// \return
    ///
    QString serviceEncoding(Array * arr);
    ///
    /// \brief serviceDecoding
    /// \param arr
    /// \param code_original
    ///
    void serviceDecoding(Array * arr, QString code_original);
    ///
    /// \brief multiFiles
    /// \param kod
    ///
    void multiFiles(bool kod);

private slots:
    ///
    /// \brief on_spinBoxPotega_valueChanged
    /// \param arg1
    ///
    void on_spinBoxPotega_valueChanged(int arg1);
    ///
    /// \brief on_pushButtonOpenFile_clicked
    ///
    void on_pushButtonOpenFile_clicked();
    ///
    /// \brief on_pushButtonSaveFile_clicked
    ///
    void on_pushButtonSaveFile_clicked();
    ///
    /// \brief on_radioButtonKod_clicked
    ///
    void on_radioButtonKod_clicked();
    ///
    /// \brief on_radioButtonDekod_clicked
    ///
    void on_radioButtonDekod_clicked();
    ///
    /// \brief on_pushButtonKodDekod_clicked
    /// \param checked
    ///
    void on_pushButtonKodDekod_clicked(bool checked);

    void on_tabWidget_currentChanged(int index);

    void on_checkBox_multi_stateChanged(int arg1);

private:
    ///
    /// \brief ui
    ///
    Ui::MainWindow *ui;
    ///
    /// \brief power_file
    ///
    int power_file;
    ///
    /// \brief power_manual
    ///
    int power_manual;
    ///
    /// \brief power_initial
    ///
    int power_initial;
    ///
    /// \brief current_power
    ///
    int current_power;

    ///
    /// \brief current_side
    ///
    int current_side;
    ///
    /// \brief side_file
    ///
    int side_file;
    ///
    /// \brief side_manual
    ///
    int side_manual;
    ///
    /// \brief side_initial
    ///
    int side_initial;
    ///
    /// \brief array
    ///
    Array *array;

    //Files
    ///
    /// \brief file
    ///
    File *file;
    ///
    /// \brief fileRead
    ///
    FileRead fileRead;
    ///
    /// \brief fileSave
    ///
    FileSave fileSave;

    //Coding
    ///
    /// \brief coding
    ///
    Coding * coding;

    Descriptions desc;
};
#endif // MAINWINDOW_H
