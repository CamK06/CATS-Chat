#include <QMainWindow>
#include <QSizePolicy>
#include <QPushButton>
#include <QTabBar>
#include <QLabel>
#include <iostream>

#include "mainwindow.h"
#include "connectdialog.h"
#include "./ui_mainwindow.h"
#include "./ui_connectdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , connect_dialog(new ConnectDialog(this))
    , message_dialog(new MessageDialog(this))
{
    connect_dialog->close();
    message_dialog->close();
    ui->setupUi(this);

    connect(ui->fileExit, &QAction::triggered, this, &MainWindow::file_exit);
    connect(ui->radioConnect, &QAction::triggered, connect_dialog, &ConnectDialog::show);
    connect(ui->messageSendTo, &QAction::triggered, message_dialog, &MessageDialog::show);
    connect(ui->tabWidget->tabBar(), &QTabBar::tabCloseRequested, this, &MainWindow::tab_close);

    // Outgoing messagebox
    send_message_button = new QPushButton("Send");
    message_box = new QLineEdit();
    message_box->setPlaceholderText("Type a message...");
    ui->msgBoxLayout->addWidget(message_box);
    ui->msgBoxLayout->addWidget(send_message_button);

    // Default UI state (no radio connected or no messages to display)
    default_layout = new QVBoxLayout(ui->tabWidget);
    default_label = new QLabel();
    default_button = new QPushButton();
    default_layout->addStretch();
    default_layout->addWidget(default_label, 0, Qt::AlignCenter);
    default_layout->addWidget(default_button, 0, Qt::AlignCenter);
    default_layout->addStretch();
    ui_set_state(UIState::AWAITING_MSG);
}

void MainWindow::ui_set_state(enum UIState state)
{
    // Show/hide UI items
    if(state != UIState::CONVERSATION) {
        default_label->setVisible(true);
        default_button->setVisible(true);
        send_message_button->setVisible(false);
        message_box->setVisible(false);
    }
    else {
        default_label->setVisible(false);
        default_button->setVisible(false);
        send_message_button->setVisible(true);
        message_box->setVisible(true);
    }

    // Set label + button text
    if(state == UIState::AWAITING_RADIO) {
        default_label->setText("No CATS radio connected!");
        default_button->setText("Connect...");
        disconnect(default_button, &QPushButton::pressed, message_dialog, &MessageDialog::show);
        connect(default_button, &QPushButton::pressed, connect_dialog, &ConnectDialog::show);
        ui->messageSendTo->setEnabled(false);
        ui->radioConnect->setText("Connect");
    }
    else if(state == UIState::AWAITING_MSG) {
        default_label->setText("No ongoing conversations!");
        default_button->setText("Send a message...");
        disconnect(default_button, &QPushButton::pressed, connect_dialog, &ConnectDialog::show);
        connect(default_button, &QPushButton::pressed, message_dialog, &MessageDialog::show);
        ui->messageSendTo->setEnabled(true);
        ui->radioConnect->setText("Disconnect");
    }
    this->ui_state = state;
}

void MainWindow::tab_close(int index)
{
    ui->tabWidget->tabBar()->removeTab(index);
}

void MainWindow::file_exit()
{
    std::exit(0);
}