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
    /// \brief Sets up window design,
    /// initial tabs, buttons and labels
    /// \param parent
    /// Sets initail values, creates early array
    /// and displays it
    MainWindow(QWidget *parent = nullptr);

    /// Clean memory
    ~MainWindow();

protected:
    /// Adds MyLabels form MyLabelsArray to grid
    void addLabelsToGrid();
    /// Sets Label's name from current file
    /// \param label
    /// \param file
    ///
    void setLabelNameFromFile(QLabel *label, File *file);
    ///
    /// \brief Wrap of code and functions to
    /// read single field/code from file encode/decode
    /// and save, output result
    /// \param arr Array on which we should operate
    ///
    void readCodeSave(Array * arr);
    ///
    /// \brief Services encoding on given array
    /// \param arr Array
    /// \return result of encoding
    ///
    QString serviceEncoding(Array * arr);
    ///
    /// \brief Services decoding on given code
    /// \param arr Array
    /// \param code_original
    ///
    /// Function fills in array from given code
    void serviceDecoding(Array * arr, QString code_original);
    ///
    /// \brief Services multi field/code option
    /// \param kod bool value that decides about encoding or decoding
    ///
    void multiFiles(bool kod);

private slots:
    ///
    /// \brief Calculates new side, display array with new size
    /// \param arg1 power
    ///
    void on_spinBoxPotega_valueChanged(int arg1);
    ///
    /// \brief Chooses new file to read from
    /// opens Dialog Window
    ///
    void on_pushButtonOpenFile_clicked();
    ///
    /// \brief Chooses new file to save result to
    /// opens Dialog Window
    ///
    void on_pushButtonSaveFile_clicked();
    ///
    /// \brief Sets the text on main button to "Kodowanie"
    ///
    void on_radioButtonKod_clicked();
    ///
    /// \brief Sets the text on main button to "Dekodowanie"
    ///
    void on_radioButtonDekod_clicked();
    ///
    /// \brief Chooses which coding mode to use and run it
    /// \param checked
    ///
    void on_pushButtonKodDekod_clicked(bool checked);
    ///
    /// \brief Based on selected options displays instrucitons
    /// \param index Index of the current tab
    ///
    void on_tabWidget_currentChanged(int index);
    ///
    /// \brief Updates description with multi or simple field option
    ///
    void on_checkBox_multi_stateChanged();

private:
    ///
    /// \brief ui MainWindow pointer
    ///
    Ui::MainWindow *ui;

    // it is possible to go without those ints below,
    // but leaved just in case and better appearance
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

protected:
    ///
    /// \brief Array pointer to current array
    ///
    Array *array;

    ///
    /// \brief File pointer to current file
    ///
    File *file;
    ///
    /// \brief Current file to read data from
    ///
    FileRead fileRead;
    ///
    /// \brief Current file to save data to
    ///
    FileSave fileSave;

    ///
    /// \brief Pointer to Coding object
    ///
    Coding * coding;
    ///
    /// \brief Contains descriptions
    ///
    Descriptions desc;
};
#endif // MAINWINDOW_H
