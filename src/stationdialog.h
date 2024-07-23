#pragma once

#include <QDialog>
#include <QSettings>

#include "./ui_stationdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StationDialog; }
QT_END_NAMESPACE

class StationDialog : public QDialog
{
    Q_OBJECT

public:
    StationDialog(QWidget *parent = nullptr);

private:
    void save();
    void reset_inputs();

    Ui::StationDialog *ui;
    QSettings settings;
};