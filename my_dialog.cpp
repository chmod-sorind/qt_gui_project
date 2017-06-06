#include "my_dialog.h"
#include "ui_my_dialog.h"
#include <QDebug>

my_dialog::my_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::my_dialog)
{
    ui->setupUi(this);
    ui->label_new_win->setText("NEW WINDOW !!! ");
}

my_dialog::~my_dialog()
{
    delete ui;
}
