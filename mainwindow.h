#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "my_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_Window_triggered();
    void on_actionNew_Modalless_Window_triggered();
    void on_pushButton_OK_clicked();
    void on_pushButton_close_clicked();

    void on_pushButton_get_dir_clicked();

public:
    Ui::MainWindow *ui;
    my_dialog *mDialog;
};

#endif // MAINWINDOW_H
