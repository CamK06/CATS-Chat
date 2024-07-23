#pragma once

#include <QDialog>
#include <QSettings>

#include "./ui_radiodialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RadioDialog; }
QT_END_NAMESPACE

class RadioDialog : public QDialog
{
    Q_OBJECT

public:
    RadioDialog(QWidget *parent = nullptr);

    void save();
    void reset_inputs();

    Ui::RadioDialog *ui;
    QSettings settings;
};