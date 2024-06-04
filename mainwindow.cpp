#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    QGridLayout *gridLayout = new QGridLayout;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            buttons[row][col] = new QPushButton("");
            buttons[row][col]->setFixedSize(100, 100);
            gridLayout->addWidget(buttons[row][col], row, col);

            connect(buttons[row][col], &QPushButton::clicked, [=]() {
                handleButtonClick(row, col);
            });

            board[row][col] = ' ';
        }
    }

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(gridLayout);
    setCentralWidget(centralWidget);
    QMessageBox::information(this, "Tutorial", "Player: X starts the game");
}

MainWindow::~MainWindow() {
    delete ui;
}
