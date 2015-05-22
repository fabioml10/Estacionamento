#include "cadastrarcarro.h"
#include "ui_cadastrarcarro.h"
#include "cadastrarcor.h"
#include "cadastrarestado.h"
#include "cadastrocidade.h"
#include "cadastrarmarca.h"
#include "cadastrarmodelo.h"
#include <QMessageBox>
#include "filecontrol.h"
#include <iostream>
#include "window.h"

using namespace std;

CadastrarCarro::CadastrarCarro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarCarro)
{
    ui->setupUi(this);
    ui->linePlaca->setMaxLength(7);
    FileControl listaUf, listaCidade, listaCor, listaModelo, listaMarca;
    ui->cBoxUf->addItems(listaUf.getUfs());
    ui->cBoxCidade->addItems(listaCidade.getCidades());
    ui->cBoxCor->addItems(listaCor.getCores());
    ui->cBoxModelo->addItems(listaModelo.getModelos());
    ui->cBoxMarca->addItems(listaMarca.getMarcas());
}

CadastrarCarro::~CadastrarCarro()
{
    delete ui;
}

void CadastrarCarro::on_btnCor_clicked()
{
    CadastrarCor cor;
    cor.setModal(true);
    cor.exec();
}

void CadastrarCarro::on_btnUf_clicked()
{
    CadastrarEstado estado;
    estado.setModal(true);
    estado.exec();
}

void CadastrarCarro::on_btnCidade_clicked()
{
    CadastroCidade cidade;
    cidade.setModal(true);
    cidade.exec();
}

void CadastrarCarro::on_btnMarca_clicked()
{
    CadastrarMarca marca;
    marca.setModal(true);
    marca.exec();
}

void CadastrarCarro::on_btnModelo_clicked()
{
    CadastrarModelo modelo;
    modelo.setModal(true);
    modelo.exec();
}

void CadastrarCarro::on_pushCadastrar_clicked()
{
    if(verificarNulo(this->ui->linePlaca->text()) || verificarPlaca(ui->linePlaca->text())){

        QMessageBox::critical(NULL,"ERRO","Atenção: O campo placa deve conter 7 caracteres!");

    }else{

        Window cadastrar;
        //QString conteudo = ui->linePlaca->text().trimmed()+","+ui->cBoxUf->currentText().trimmed()+","+ui->cBoxCidade->currentText().trimmed()+","+ui->cBoxCor->currentText().trimmed()+","+ui->cBoxMarca->currentText().trimmed()+","+ui->cBoxModelo->currentText().trimmed();
        cadastrar.setNewCarro(ui->linePlaca->text(),ui->cBoxUf->currentText(),ui->cBoxCidade->currentText(),ui->cBoxCor->currentText(),ui->cBoxMarca->currentText(),ui->cBoxModelo->currentText());
        //cadastrar.setNewCarro(conteudo);
    }
}

bool CadastrarCarro::verificarNulo(QString campo){
    if(campo.isNull() || campo.isEmpty()){
        return true;
    }else{
        return false;
    }
}

bool CadastrarCarro::verificarPlaca(QString campo){
    if(campo.length() < 7){
        return true;
    }else{
        return false;
    }
}

bool CadastrarCarro::setNewCidade(QString cidade, QString uf){

    if(!cidade.isEmpty()){
        this->ui->cBoxCidade->addItem(cidade);
    }
    if(!uf.isEmpty()){
        this->ui->cBoxUf->addItem(uf);
    }

    this->close();

    if(!cidade.isEmpty() && !uf.isEmpty()){
        QString conteudo = cidade+","+uf;
        FileControl file;
        file.gravaArquivo(file.arfCidade,conteudo);
    }

    this->exec();
}

void CadastrarCarro::setNewModelo(QString modelo, QString marca){
    if(!modelo.isEmpty()){
        this->ui->cBoxModelo->addItem(modelo);
    }
    if(!marca.isEmpty()){
        this->ui->cBoxMarca->addItem(marca);
    }

    this->close();

    if(!modelo.isEmpty() && !marca.isEmpty()){
        QString conteudo = marca+","+modelo;
        FileControl file;
        file.gravaArquivo(file.arfModelo,conteudo);
    }

    this->exec();
}
