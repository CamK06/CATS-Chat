#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QMetaObject>
#include <QSettings>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>

#include "radiodialog.h"
#include "messagedialog.h"
#include "stationdialog.h"
#include "./ui_radiodialog.h"
#include "./ui_messagedialog.h"
#include "./ui_stationdialog.h"

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
    void radio_connect();

    enum UIState ui_state = UIState::AWAITING_RADIO;

    Ui::MainWindow *ui;
    RadioDialog *radio_dialog;
    MessageDialog *message_dialog;
    StationDialog *station_dialog;
    QPushButton *send_message_button;
    QLineEdit *message_box;
    QVBoxLayout *default_layout;
    QLabel *default_label;
    QPushButton *default_button;
    QMetaObject::Connection *default_button_connection;
    QSettings settings;
};