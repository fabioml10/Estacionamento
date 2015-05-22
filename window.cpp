#include "window.h"
#include "ui_window.h"
#include "cadastrarcarro.h"
#include <QDate>
#include <QTime>
#include "filecontrol.h"
#include <QTreeWidget>
#include "pagamento.h"
#include <QMessageBox>
#include <iostream>
#include "filecontrol.h"
#include "pagamento.h"

using namespace std;

Window::Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    this->loadCarrosNoPatio();

    }

Window::~Window()
{
    delete ui;
}

void Window::on_btnCadCarro_clicked()
{
    CadastrarCarro cadCarro;
    cadCarro.setModal(true);
    cadCarro.exec();
}

float Window::verificaValor(float valorHora, QString dataHora){

    float valor = 0;
    QStringList data = dataHora.split(" ");//retira o espaço que vem por padrão na QString dataHora e grava os dois "segmentos" numa lista

    //pega data atual
    /*int anoRetirada = QDate::currentDate().year();
    int mesRetirada = QDate::currentDate().month();
    int diaRetirada = QDate::currentDate().day();*/

    //pega hora atual
    int horaRetirada = QTime::currentTime().hour();
    int minutoRetirada = QTime::currentTime().minute();

    //split do dia, mes e ano
    /*QStringList dataSplit = data[0].split("-");
    int anoEstacionado = dataSplit[2].toInt();
    int mesEstacionado = dataSplit[1].toInt();
    int diaEstacionado = dataSplit[0].toInt();*/

    //split da hora e minuto
    QStringList horaSplit = data[1].split(":");
    int horaEstacionado = horaSplit[0].toInt();
    int minutoEstacionado = horaSplit[1].toInt();

    int totalHoras = horaRetirada - horaEstacionado;
    int totalMinutos = minutoRetirada - minutoEstacionado;

    if(totalHoras > 0){
        valor+= totalHoras * valorHora;
            }
    if(totalMinutos > 0){
        valor+= totalMinutos * (valorHora/60);
    }
    return valor;
}

void Window::loadCarrosNoPatio(){
    FileControl carro;
    QStringList carros = carro.getPatio();

    this->ui->lblCarrosEstc->setText("Estacionados: "+QString::number(carros.length()));

    foreach(QString itemCarro,carros){
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->twListagem);

        QStringList carroFatiado = itemCarro.split(",");

        item->setText(0,carroFatiado[0]);
        item->setText(1,carroFatiado[1]);
        item->setText(2,carroFatiado[2]);
        item->setText(3,carroFatiado[3]);
        item->setText(4,carroFatiado[4]);
        item->setText(5,carroFatiado[5]);
        item->setText(6,carroFatiado[6]);

        ui->twListagem->addTopLevelItem(item);
    }
}

void Window::on_btnSaida_clicked()
{
    /*Pagamento telaPagamento;
    telaPagamento.setModal(true);
    telaPagamento.exec();
    QTreeWidgetItem *item = ui->twListagem->currentItem();
    if(this->pagamento(item)){
    delete item;
    }*/
}

bool Window::pagamento(QTreeWidgetItem item){
        /*FileControl pagamento;
        if(pagamento.updateArquivo(pagamento.arfPatio,item[0],item))
            return true;
        return false;*/
    }

void Window::setNewCarro(QString placa, QString estado, QString cidade, QString cor, QString marca, QString modelo){

    FileControl controle;

    if(!placa.isNull() && !estado.isNull() && !cidade.isNull() && !cor.isNull() && !marca.isNull() && !modelo.isNull()){

        QString conteudo = placa.trimmed()+","+estado.trimmed()+","+cidade.trimmed()+","+cor.trimmed()+","+marca.trimmed()+","+modelo.trimmed();
        //cout << conteudo.toStdString() << endl;
        controle.gravaArquivo(controle.arfCarro, conteudo);
        return;
    }
    QMessageBox::critical(NULL,"ERRO","Erro ao tentar cadastrar carro.\nFavor, preencer todos os campos");
}

bool Window::procurarPlaca(QString placa){

    FileControl listaDePlacas, listaPatio;
    //QStringList placas = listaDePlacas.getCarros(); //em carro
    QStringList patios = listaPatio.getPatio2(); //em patio
    int i = 0;
    bool resultado = false;

    foreach (QString var, patios) {
        if(placa == patios[i]){
            resultado = true;
            //cout << "deu 0" << endl;
        }
            i++;
    }
return resultado;

}

bool Window::procurarPlacaCarros(QString placa){

    FileControl listaDePlacas;
    QStringList placas = listaDePlacas.getCarros(0); //em carro
    int i = 0;
    bool resultado = false;

    foreach (QString var, placas) {
        if(placa == placas[i]){
            resultado = true;
            //cout << "deu 0" << endl;
        }
            i++;
    }
return resultado;

}

void Window::on_btnProcPlaca_clicked()
{


    if(procurarPlaca(ui->lineBuscaPlaca->text())){
        Pagamento pagar;
        pagar.setModal(true);
        pagar.exec();
        return;

    }else if(procurarPlacaCarros(ui->lineBuscaPlaca->text())){

        FileControl gravarNoPatio;
        gravarNoPatio.gravaEntrada(ui->lineBuscaPlaca->text());

        QStringList carro = gravarNoPatio.findCarro(ui->lineBuscaPlaca->text());
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->twListagem);

        QString dateTime = QString::number(QDate::currentDate().day())+"-"+QString::number(QDate::currentDate().month())+"-"+QString::number(QDate::currentDate().year())+" "+QString::number(QTime::currentTime().hour())+":"+QString::number(QTime::currentTime().minute());

        item->setText(0,carro[0]);
        item->setText(1,carro[1]);
        item->setText(2,carro[2]);
        item->setText(3,carro[3]);
        item->setText(4,carro[4]);
        item->setText(5,carro[5]);
        item->setText(6,dateTime);

        ui->twListagem->addTopLevelItem(item);

        return;

    }else{
        CadastrarCarro cadCarro;
        cadCarro.setModal(true);
        cadCarro.exec();
        return;
    }
}
