#include "cadastrarmodelo.h"
#include "ui_cadastrarmodelo.h"
#include "cadastrarmarca.h"
#include "cadastrarcarro.h"

CadastrarModelo::CadastrarModelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarModelo)
{
    ui->setupUi(this);
}

CadastrarModelo::~CadastrarModelo()
{
    delete ui;
}

void CadastrarModelo::on_cmdCadMarca_clicked()
{
    CadastrarMarca marca;
    marca.setModal(true);
    marca.exec();
}

bool CadastrarModelo::setNewMarca(QString newMarca){
    this->ui->cBoxCadMarca->addItem(newMarca);
    this->close();
    this->exec();
}

void CadastrarModelo::on_btnAddModelo_clicked()
{
    CadastrarCarro control;
    control.setNewModelo(this->ui->cBoxCadMarca->currentText(),this->ui->lineAddModelo->text());
}
