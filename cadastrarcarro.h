#ifndef CADASTRARCARRO_H
#define CADASTRARCARRO_H

#include <QDialog>

namespace Ui {
class CadastrarCarro;
}

class CadastrarCarro : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarCarro(QWidget *parent = 0);
    ~CadastrarCarro();
    bool verificarNulo(QString campo);
    bool verificarPlaca(QString campo);
    bool setNewCidade(QString cidade, QString uf);
    void setNewModelo(QString modelo, QString marca);

private slots:
    void on_btnCor_clicked();

    void on_btnUf_clicked();

    void on_btnCidade_clicked();

    void on_btnMarca_clicked();

    void on_btnModelo_clicked();

    void on_pushCadastrar_clicked();

private:
    Ui::CadastrarCarro *ui;
};

#endif // CADASTRARCARRO_H
