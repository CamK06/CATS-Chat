#include <QDialog>

#include "radiodialog.h"
#include "./ui_radiodialog.h"

RadioDialog::RadioDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RadioDialog)
{
    ui->setupUi(this);
    setModal(true);
}