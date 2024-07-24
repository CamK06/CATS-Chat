#include <QDialog>
#include <QSettings>
#include <QSerialPortInfo>

#include "radiodialog.h"
#include "./ui_radiodialog.h"

RadioDialog::RadioDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RadioDialog)
{
    ui->setupUi(this);
    setModal(true);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &RadioDialog::save);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &RadioDialog::reset_inputs);

    const auto serial_ports = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &port_info : serial_ports) {
        ui->serialPort->addItem(port_info.systemLocation());
    }

    reset_inputs();
}

void RadioDialog::save()
{
    settings.setValue("radio/serialPort", ui->serialPort->currentText());
    settings.setValue("radio/baudRate", ui->baudRate->currentText());
    settings.sync();
}

void RadioDialog::reset_inputs()
{
    ui->serialPort->setCurrentText(settings.value("radio/serialPort").toString());
    ui->baudRate->setCurrentText(settings.value("radio/baudRate").toString());
}