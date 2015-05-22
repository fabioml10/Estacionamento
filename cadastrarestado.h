#ifndef CADASTRARESTADO_H
#define CADASTRARESTADO_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class CadastrarEstado;
}

class CadastrarEstado : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarEstado(QWidget *parent = 0);
    ~CadastrarEstado();
    QString upperEstado(QString estado);

private slots:
    void on_btnAddEstado_clicked();

    void on_lineAddEstado_textChanged(const QString &arg1);

private:
    Ui::CadastrarEstado *ui;    
};

#endif // CADASTRARESTADO_H
