#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QMetaObject>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>

#include "connectdialog.h"
#include "messagedialog.h"
#include "./ui_connectdialog.h"
#include "./ui_messagedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum UIState
{
    AWAITING_RADIO,
    AWAITING_MSG,
    CONVERSATION
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    void ui_set_state(enum UIState state);
    void tab_close(int index);
    void file_exit();

    enum UIState ui_state = UIState::AWAITING_RADIO;

    Ui::MainWindow *ui;
    ConnectDialog *connect_dialog;
    MessageDialog *message_dialog;
    QPushButton *send_message_button;
    QLineEdit *message_box;
    QVBoxLayout *default_layout;
    QLabel *default_label;
    QPushButton *default_button;
    QMetaObject::Connection *default_button_connection;
};