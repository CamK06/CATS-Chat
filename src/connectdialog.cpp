#include <QDialog>

#include "connectdialog.h"
#include "./ui_connectdialog.h"

ConnectDialog::ConnectDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
    setModal(true);
    show();
}