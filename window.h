#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QTreeWidget>

namespace Ui {
class Window;
}

class Window : public QDialog
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    void loadCarrosNoPatio();
    bool pagamento(QTreeWidgetItem item);
    void setNewCarro(QString placa, QString estado, QString cidade, QString cor, QString marca, QString modelo);
    bool procurarPlaca(QString placa);
    bool procurarPlacaCarros(QString placa);

private slots:
    void on_btnCadCarro_clicked();

    void on_btnSaida_clicked();

    void on_btnProcPlaca_clicked();

private:
    Ui::Window *ui;
    float verificaValor(float valorHora, QString dataHora);
};

#endif // WINDOW_H
