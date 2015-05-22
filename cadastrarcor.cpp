#include "cadastrarcor.h"
#include "ui_cadastrarcor.h"

CadastrarCor::CadastrarCor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarCor)
{
    ui->setupUi(this);
}

CadastrarCor::~CadastrarCor()
{
    delete ui;
}
