#ifndef CADASTRARMARCA_H
#define CADASTRARMARCA_H

#include <QDialog>

namespace Ui {
class CadastrarMarca;
}

class CadastrarMarca : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarMarca(QWidget *parent = 0);
    ~CadastrarMarca();

private slots:
    void on_btnAddMarca_clicked();

private:
    Ui::CadastrarMarca *ui;
};

#endif // CADASTRARMARCA_H
