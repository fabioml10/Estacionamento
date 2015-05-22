#ifndef FILECONTROL_H
#define FILECONTROL_H

#include <QtCore>
#include <iostream>

class FileControl
{
public:
    FileControl();
/*
    QString arfCidade = ":/csv/cidades.csv";
    QString arfModelo = ":/csv/modelos.csv";
    QString arfCor = ":/csv/cores.csv";
    QString arfUsuario = ":/csv/usuarios.csv";
    QString arfCarro = ":/csv/carros.csv";
    QString arfPatio = ":csv/patio.csv";
*/
    QString arfCidade = "../SansCar/cidades.csv";
    QString arfModelo = "../SansCar/modelos.csv";
    QString arfCor = "../SansCar/cores.csv";
    QString arfUsuario = "../SansCar/usuarios.csv";
    QString arfCarro = "../SansCar/carros.csv";
    QString arfPatio = "../SansCar/patio.csv";

    QStringList lerArquivo (QString nomeArquivo);
    bool gravaArquivo(QString nomeArquivo, QString conteudo);
    QStringList getUfs(); //retorna lista de estados
    bool setUf(QString uf); //grava novo estado
    QStringList getCores(); //retorna lista de cores
    bool setCor(QString cor); //grava nova cor
    QStringList getCidades();
    bool setCidade (QString cidade);
    QStringList getMarcas();
    bool setMarca(QString marca);
    QStringList getModelos();
    bool setModelo (QString modelo);
    QStringList getUsuarios();
    bool setUsuario(QString usuario);
    QStringList getPatio();
    bool updateArquivo(QString arfUp,QString pk,QString item);
    QStringList getCarros(int coluna);
    QStringList getPatio2();
    void gravaEntrada(QString placa);
    QStringList findCarro(QString placa);
};

#endif // FILECONTROL_H
