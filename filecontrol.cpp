#include "filecontrol.h"
#include <QtCore>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include "QDate"
#include "QTime"

using namespace std;

FileControl::FileControl()
{
}

QStringList FileControl::lerArquivo(QString nomeArquivo){

    QFile meuArquivo(nomeArquivo);

    if(!meuArquivo.exists()){
        QMessageBox::critical(NULL,"ERRO CRÍTICO","arquivo: "+nomeArquivo+" não encontrado.");
    }
    if(!meuArquivo.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::critical(NULL,"ERRO CRÍTICO","Erro na tentativa de abrir "+nomeArquivo+".");
    }
    QStringList listaDoConteudodoArquivo;
    while (!meuArquivo.atEnd()){
        QString linha = meuArquivo.readLine();
        listaDoConteudodoArquivo.append(linha);
    }
    return listaDoConteudodoArquivo;
}

bool FileControl::gravaArquivo(QString nomeArquivo, QString conteudo){

    QFile meuArquivo(nomeArquivo);

    if(!meuArquivo.open(QFile::Append|QFile::Text)){
        QMessageBox::critical(NULL,"ERROR","Ocorreu um erro na tentativa de gravar o arquivo "+nomeArquivo);
        return 0;
    }else if(!meuArquivo.isOpen()){
        QMessageBox::critical(NULL,"ERROR","Ocorreu um erro na tentativa de abrir o arquivo "+nomeArquivo);
        return 0;
    }else{
        QTextStream out(&meuArquivo);
        out << conteudo << endl;
        meuArquivo.flush();
        meuArquivo.close();
        QMessageBox::information(NULL,"OK","Gravado com sucesso");
    }
    return 1;
}

bool FileControl::updateArquivo(QString arfUp,QString pk,QString item){

    QStringList contem = this->lerArquivo(arfUp);
    QString novoConteudo;

    foreach (QString conteudo, contem) {
        QStringList fatiaConteudo = conteudo.split(",");
        int qtConteudoNaLinha = fatiaConteudo.length();
        for(int i=0; i<=qtConteudoNaLinha; i++){
            if(pk == fatiaConteudo[i]){
                novoConteudo += ","+item;
            }else{
                novoConteudo += ","+conteudo;
            }
        }
    }
    this->gravaArquivo(arfUp,novoConteudo);
}

QStringList FileControl::getUfs(){

    QStringList ufs = this->lerArquivo(this->arfCidade);
    QStringList uf;
    foreach (QString var, ufs) {
        QStringList listaUfLinha = var.split(",");
        uf.append(listaUfLinha[1]);
    }
    uf.removeDuplicates();
    return uf;
}

bool FileControl::setUf(QString uf){

    foreach (QString var, getUfs()) {
        if(var == uf){
            return 1;
        }else{
            return 0;
        }
    }
}

QStringList FileControl::getCidades(){

    QStringList cidades = this->lerArquivo(this->arfCidade);
    QStringList cidade;
    foreach (QString var, cidades) {
        QStringList listaUfLinha = var.split(",");
        cidade.append(listaUfLinha[0]);
    }
    cidade.removeDuplicates();
    return cidade;
}

bool FileControl::setCidade(QString cidade){
    foreach (QString var, getCidades()) {
        if(var == cidade){
            return 1;
        }else{
            return 0;
        }
    }
}

QStringList FileControl::getCores(){

    QStringList cores = this->lerArquivo(this->arfCor);
    cores.removeDuplicates();
    return cores;
}

bool FileControl::setCor(QString cor){
    foreach (QString var, getCores()) {
        if(var == cor){
            return 1;
        }else{
            return 0;
        }
    }
}

QStringList FileControl::getMarcas(){

    QStringList marcas = this->lerArquivo(this->arfModelo);
    QStringList marca;
    foreach (QString var, marcas) {
        QStringList listaUfLinha = var.split(",");
        marca.append(listaUfLinha[0]);
    }
        marca.removeDuplicates();
    return marca;
}

bool FileControl::setMarca(QString marca){
    foreach (QString var, getMarcas()) {
        if(var == marca){
            return 1;
        }else{
            return 0;
        }
    }
}

QStringList FileControl::getModelos(){

    QStringList modelos = this->lerArquivo(this->arfModelo);
    QStringList modelo;
    foreach (QString var, modelos) {
        QStringList listaUfLinha = var.split(",");
        modelo.append(listaUfLinha[1]);
    }
    modelo.removeDuplicates();
    return modelo;
}

bool FileControl::setModelo(QString modelo){
    foreach (QString var, getModelos()) {
        if(var == modelo){
            return 1;
        }else{
            return 0;
        }
    }
}

QStringList FileControl::getUsuarios(){

    QStringList usuarios = this->lerArquivo(this->arfUsuario);

    return usuarios;
}

bool FileControl::setUsuario(QString usuario){
    foreach (QString var, getUsuarios()) {
        if(var == usuario){
            return 1;
        }else{
            return 0;
        }
    }
}

QStringList FileControl::getPatio(){

    QStringList patioCarros = this->lerArquivo(this->arfPatio);
    QStringList soOsEmAberto;

    foreach(QString carro, patioCarros){
        QStringList resultadoDaCarros = carro.split(",");
        if(resultadoDaCarros[7].isEmpty()){
            soOsEmAberto.append(resultadoDaCarros[0]
                    +","+resultadoDaCarros[1]
                    +","+resultadoDaCarros[2]
                    +","+resultadoDaCarros[3]
                    +","+resultadoDaCarros[4]
                    +","+resultadoDaCarros[5]
                    +","+resultadoDaCarros[6]);
        }
    }

    soOsEmAberto.removeDuplicates();
    return soOsEmAberto;
}

//retorna a coluna placa do arquivo carro
QStringList FileControl::getCarros(int coluna){

    QStringList carros = this->lerArquivo(this->arfCarro);
    QStringList carro;
    foreach (QString var, carros) {
        QStringList listaCarroLinha = var.split(",");
        carro.append(listaCarroLinha[coluna]);
    }
    //modelo.removeDuplicates();
    return carro;
}

//retorna a coluna placa do arquivo patio
QStringList FileControl::getPatio2(){

    QStringList patios = this->lerArquivo(this->arfPatio);
    QStringList patio;
    foreach(QString var, patios) {
        QStringList listaPatioLinha = var.split(",");
        patio.append(listaPatioLinha[0]);
    }
    //modelo.removeDuplicates();
    return patio;
}

void FileControl::gravaEntrada(QString placa){

        QStringList carro = this->findCarro(placa);
        QString conteudo;

        foreach (QString var, carro) {
        conteudo += var.trimmed()+",";

        }

        //conteudo +=",";
        QString dateTime = QString::number(QDate::currentDate().day())+"-"+QString::number(QDate::currentDate().month())+"-"+QString::number(QDate::currentDate().year())+" "+QString::number(QTime::currentTime().hour())+":"+QString::number(QTime::currentTime().minute());
        conteudo += dateTime+",,";
        this->gravaArquivo(this->arfPatio,conteudo);
}

QStringList FileControl::findCarro(QString placa){

    QStringList carrosNoArquivo = this->lerArquivo(arfCarro);

    foreach(QString var, carrosNoArquivo){ //var é a linha inteira
        QStringList linha = var.split(",");
        if(linha[0] == placa){
            return linha;
        }
    }
    //return;
}
