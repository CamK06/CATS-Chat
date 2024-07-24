#include <QDialog>

#include "messagedialog.h"
#include "mainwindow.h"
#include "./ui_messagedialog.h"

MessageDialog::MessageDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
    setModal(true);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &MessageDialog::ok);
}

void MessageDialog::ok()
{
    QString callsign = ui->toCall->text();
    ui->toCall->clear();
    ((MainWindow*)this->parent())->new_conversation(callsign, ui->requireACK->isChecked());
}