#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick(int row, int col);

private:
    Ui::MainWindow *ui;
    QPushButton *buttons[3][3];
    char board[3][3];
    char currentPlayer = 'X';

    void checkForWinner();
    void resetGame();
};
#endif // MAINWINDOW_H
