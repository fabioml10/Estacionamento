#include "carromodel.h"
#include "cadastrarcarro.h"
#include <QMessageBox>

CarroModel::CarroModel()
{
}

bool CarroModel::validarCarro(std::string placa, std::string uf, std::string cidade, std::string cor, std::string marca, std::string modelo){

    QStringList erros;

    if(placa.empty() || placa.length() < 7){
        erros.append("Placa");
    }

    if(uf.empty() || uf.length() != 2){
        erros.append("Uf");
    }

    if(cidade.empty() || cidade.length() < 3){
        erros.append("Cidade");
    }

    if(cor.empty() || cor.length() < 4){
        erros.append("Cor");
    }

    if(marca.empty() || marca.length() < 4){
        erros.append("Marca");
    }

    if(modelo.empty() || modelo.length() < 2){
        erros.append("Modelo");
    }

    if(erros.isEmpty()){
        QString erro = "Campos inválidos:\n", er;
        foreach(er, erros){ //roda independente do número final, o "er" faz a vez do "i" no "for"
            erro = erro+"\n"+er;
        }

        QMessageBox::critical(NULL,"ERROS",erro);
    }
}
