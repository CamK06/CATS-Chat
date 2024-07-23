#include <QDialog>

#include "stationdialog.h"
#include "./ui_stationdialog.h"

StationDialog::StationDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StationDialog)
{
    ui->setupUi(this);
    setModal(true);
}