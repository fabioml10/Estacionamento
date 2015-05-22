#ifndef CARROMODEL_H
#define CARROMODEL_H

#include <iostream>

class CarroModel
{
public:
    CarroModel();
    std::string placa;
    std::string uf;
    std::string cidade;
    std::string cor;
    std::string marca;
    std::string modelo;

    bool validarCarro(std::string placa, std::string uf, std::string cidade, std::string cor, std::string marca, std::string modelo);
    bool encontrarCarro(std::string placa);
    bool salvarEntrada(std::string placa);
    bool salvarSaida(std::string placa);
    bool salvarCarro(CarroModel newCarro);
    bool salvarNewUf(std::string newUf);
    bool salvarNewCidade(std::string newCidade);
    bool salvarNewCor(std::string newCor);
    bool salvarNewMarca(std::string newMarca);
    bool salvarNewModelo(std::string newModelo);
};

#endif // CARROMODEL_H
