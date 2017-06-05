#include "my_dialog.h"
#include "ui_my_dialog.h"

my_dialog::my_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::my_dialog)
{
    ui->setupUi(this);
}

my_dialog::~my_dialog()
{
    delete ui;
}
