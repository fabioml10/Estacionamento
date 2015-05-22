#include "cadastrarmarca.h"
#include "ui_cadastrarmarca.h"
#include "cadastrarmodelo.h"

CadastrarMarca::CadastrarMarca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarMarca)
{
    ui->setupUi(this);
}

CadastrarMarca::~CadastrarMarca()
{
    delete ui;
}

void CadastrarMarca::on_btnAddMarca_clicked()
{
    CadastrarModelo control;
    control.setNewMarca(this->ui->lineAddMarca->text());
}
