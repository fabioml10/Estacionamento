#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include "window.h"
#include "filecontrol.h"
#include <iostream>

using namespace std;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

/*Verifica usuario e senha*/
void Login::on_btnEntrar_clicked()
{
    FileControl listaUsuario;
    QStringList usuarios = listaUsuario.getUsuarios();

    foreach (QString usuario, usuarios) {

        QStringList user = usuario.split(",");

        if(ui->lineUsuario->text().toStdString() == user[0].toStdString() && user[1].compare(ui->lineSenha->text()) == 1){
        QMessageBox::information(NULL,"BEM VINDO","LOGADO COM SUCESSO!\nBEM VINDO!");
        this->close();
        Window janelaPrincipal;
        janelaPrincipal.setModal(true);
        janelaPrincipal.exec();
        return;
        }

    }
    if(ui->lineUsuario->text().isEmpty() || ui->lineSenha->text().isEmpty()){
        QMessageBox::warning(NULL,"INVÁLIDO","CAMPOS USUÁRIO OU SENHA ESTÃO EM BRANCO.");
    }else{
        QMessageBox::critical(NULL,"ERRO","USUÁRIO OU SENHA INCORRETOS!");
    }
}
