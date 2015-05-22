#ifndef CADASTROCIDADE_H
#define CADASTROCIDADE_H

#include <QDialog>

namespace Ui {
class CadastroCidade;
}

class CadastroCidade : public QDialog
{
    Q_OBJECT

public:
    explicit CadastroCidade(QWidget *parent = 0);
    ~CadastroCidade();
    void loadEstado();
    bool setNewEstado(QString newEstado);

private slots:
    void on_cmdAddEstado_clicked();

    void on_btnAddCidade_clicked();

private:
    Ui::CadastroCidade *ui;
};

#endif // CADASTROCIDADE_H
