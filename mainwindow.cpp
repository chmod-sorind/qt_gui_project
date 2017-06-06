#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_dialog.h"
#include <QDebug>
#include <QDir>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Window_triggered()
{
    my_dialog mDialog;
    mDialog.setModal(true);
    mDialog.exec();
}

void MainWindow::on_actionNew_Modalless_Window_triggered()
{
    mDialog = new my_dialog(this);
    mDialog->show();
}


void MainWindow::on_pushButton_OK_clicked()
{
    if ( ui->lineEdit_Name->text() == NULL ) {

        ui->label_Name->setText("<font color=red>Name:</font>");
    }
    else {
        QString name=ui->lineEdit_Name->text();
        QString name_label=ui->label_Name->accessibleName();
        QString text=name_label + " " + name;
        ui->plainTextEdit->appendPlainText(name);
        qDebug() << text;
    }
}

void MainWindow::on_pushButton_close_clicked()
{
    qDebug() << "Application Quitt.";
}

void MainWindow::on_pushButton_get_dir_clicked()
{
    ui->plainTextEdit->appendPlainText("Drives on this computer:");

    QDir drives;
    foreach (QFileInfo mItm, drives.drives())
    {
        QString drive = mItm.absoluteFilePath();
        ui->plainTextEdit->appendPlainText(drive);
        ui->listWidget->addItem(drive);

        if ( drive == "D:/" )
        {
            QDir directories(drive);
            foreach (QFileInfo mitm, directories.entryInfoList())
            {
                QString directory = mitm.absoluteFilePath();
                ui->plainTextEdit->appendPlainText(directory);
                ui->listWidget->addItem(directory);
            }
        }
    }

}
