#include "cadastrocidade.h"
#include "ui_cadastrocidade.h"
#include "cadastrarestado.h"
#include "cadastrarcarro.h"

CadastroCidade::CadastroCidade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastroCidade)
{
    ui->setupUi(this);
}

CadastroCidade::~CadastroCidade()
{
    delete ui;
}

void CadastroCidade::on_cmdAddEstado_clicked()
{
    CadastrarEstado estado;
    estado.setModal(true);
    estado.exec();
}

bool CadastroCidade::setNewEstado(QString newEstado){
    this->ui->cBoxAddEstado->addItem(newEstado);
    this->close();
    this->exec();
}

void CadastroCidade::on_btnAddCidade_clicked()
{
    CadastrarCarro control;
    control.setNewCidade(this->ui->lineAddCidade->text(),this->ui->cBoxAddEstado->currentText());
}
