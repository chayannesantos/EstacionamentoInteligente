#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSerialPort serial;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ButtonAbrir_clicked();

    void on_ButtonFechar_clicked();

    void dadosRecebidos();

    void on_Button_entrada_clicked();

    void on_Button_saida_clicked();

    void enviardados();
private:
    Ui::MainWindow *ui;
    int quantDispo;
};

#endif // MAINWINDOW_H
