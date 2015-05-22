#include "cadastrarestado.h"
#include "ui_cadastrarestado.h"
#include "filecontrol.h"
#include <QMessageBox>
#include "cadastrocidade.h"

CadastrarEstado::CadastrarEstado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarEstado)
{
    ui->setupUi(this);
}

CadastrarEstado::~CadastrarEstado()
{
    delete ui;
}

void CadastrarEstado::on_btnAddEstado_clicked()
{

    CadastroCidade control;
    control.setNewEstado(this->ui->lineAddEstado->text());
}

QString CadastrarEstado::upperEstado(QString estado){ //transforma todos os chars em maiúsculas

    return estado.toUpper();
}

void CadastrarEstado::on_lineAddEstado_textChanged(const QString &arg1)
{
    ui->lineAddEstado->setText(upperEstado(ui->lineAddEstado->text()));
}
