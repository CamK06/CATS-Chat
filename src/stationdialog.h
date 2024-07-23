#pragma once

#include <QDialog>

#include "./ui_stationdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StationDialog; }
QT_END_NAMESPACE

class StationDialog : public QDialog
{
    Q_OBJECT

public:
    StationDialog(QWidget *parent = nullptr);
    Ui::StationDialog *ui;
};