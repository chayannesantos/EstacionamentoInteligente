#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(auto& item : QSerialPortInfo::availablePorts()) {
        ui->comboBoxPorta->addItem(item.portName());
    }
    for(auto& item : QSerialPortInfo::standardBaudRates()){
        ui->comboBoxVelo->addItem(QString::number(item));
    }
    quantDispo=0;

    connect(&serial,SIGNAL(readyRead()),this,SLOT(dadosRecebidos()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dadosRecebidos()
{
    auto data = serial.readAll();
    auto dados = QJsonDocument::fromJson(data).object().toVariantMap();

   // qDebug()<<dados;

    if(dados.contains("VAGA1")) {
        if(dados["VAGA1"].toBool()) {
            ui->status_vaga1->setText("OCUPADO");
            ui->status_vaga1->setStyleSheet("color:rgb(255, 0, 0)");
        } else {
            ui->status_vaga1->setText("DISPONÍVEL");
            ui->status_vaga1->setStyleSheet("color:rgb(0, 230, 0)");
        }
    }

    if(dados.contains("VAGA2")) {
        if(dados["VAGA2"].toBool()) {
            ui->status_vaga2->setText("OCUPADO");
            ui->status_vaga2->setStyleSheet("color:rgb(255, 0, 0)");
        } else {
            ui->status_vaga2->setText("DISPONÍVEL");
            ui->status_vaga2->setStyleSheet("color:rgb(0, 230, 0)");
        }
    }

    if(dados.contains("VAGA3")) {
        if(dados["VAGA3"].toBool()) {
            ui->status_vaga3->setText("OCUPADO");
            ui->status_vaga3->setStyleSheet("color:rgb(255, 0, 0)");
        } else {
            ui->status_vaga3->setText("DISPONÍVEL");
            ui->status_vaga3->setStyleSheet("color:rgb(0, 230, 0)");
        }
    }

    if(dados.contains("QUANT")) {
        quantDispo=3-dados["QUANT"].toInt();
        if(quantDispo==0) {
            ui->quant_vagas->setText("             Estacionamento Lotado");
            ui->quant_vagas->setStyleSheet("color:rgb(255, 0, 0)");
        } else {
            ui->quant_vagas->setText("Quant. Vagas Disponíveis:   "+QString::number(quantDispo));
            ui->quant_vagas->setStyleSheet("color:rgb(0, 0, 0)");
        }
    }

    if(dados.contains("CANCELA")) {
        if(dados["CANCELA"].toBool()) {
            ui->status_cancela->setText("ABERTA");
            ui->status_cancela->setStyleSheet("color:rgb(0, 230, 0)");
        } else {
            ui->status_cancela->setText("FECHADA");
            ui->status_cancela->setStyleSheet("color:rgb(255, 0, 0)");
        }
    }
}
void MainWindow::enviardados(){
    QNetworkRequest request((QUrl("http://estacionalegal.herokuapp.com/upload")));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QJsonObject json;
    json.insert("VAGAS",quantDispo);
    QNetworkAccessManager Vagas;
    QNetworkReply *reply = Vagas.post(request,QJsonDocument(json).toJson());

        while(!reply->isFinished())
              qApp->processEvents();


}
void MainWindow::on_ButtonAbrir_clicked()
{
    serial.setPortName(ui->comboBoxPorta->currentText());
    serial.setBaudRate(ui->comboBoxVelo->currentText().toInt());

    if(serial.open(QIODevice::ReadWrite)) {
        ui->label_conexao->setText("Status:  Conectado");
    }
}




void MainWindow::on_ButtonFechar_clicked()
{
    serial.close();
    ui->label_conexao->setText("Status:  Desconectado");
}

void MainWindow::on_Button_entrada_clicked()
{
    serial.write("{\"CANCELA\": +}");

}

void MainWindow::on_Button_saida_clicked()
{
    serial.write("{\"CANCELA\": -}");
}



