#include <QDialog>
#include <QSettings>

#include "stationdialog.h"
#include "./ui_stationdialog.h"

StationDialog::StationDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StationDialog)
{
    ui->setupUi(this);
    setModal(true);

    reset_inputs();
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &StationDialog::save);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &StationDialog::reset_inputs);
}

void StationDialog::save()
{
    settings.setValue("station/callsign", ui->callsign->text());
    settings.setValue("station/antGain", ui->antGain->value());
    settings.setValue("station/antHeight", ui->antHeight->value());
    settings.setValue("station/txPower", ui->txPower->value());
    settings.sync();
}

void StationDialog::reset_inputs()
{
    ui->callsign->setText(settings.value("station/callsign").toString());
    ui->antGain->setValue(settings.value("station/antGain").toDouble());
    ui->antHeight->setValue(settings.value("station/antHeight").toInt());
    ui->txPower->setValue(settings.value("station/txPower").toDouble());
}