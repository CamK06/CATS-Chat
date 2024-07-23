#pragma once

#include <QDialog>

#include "./ui_connectdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ConnectDialog; }
QT_END_NAMESPACE

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    ConnectDialog(QWidget *parent = nullptr);
    Ui::ConnectDialog *ui;
};