#pragma once

#include <QDialog>

#include "./ui_messagedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MessageDialog; }
QT_END_NAMESPACE

class MessageDialog : public QDialog
{
    Q_OBJECT

public:
    MessageDialog(QWidget *parent = nullptr);
    Ui::MessageDialog *ui;
};