#ifndef CONTABANCARIA_H_INCLUDED
#define CONTABANCARIA_H_INCLUDED

#include "Cliente.h"

class ContaBancaria
{
private:
    int numero;
    Cliente titular;
    double saldo;

public:
    ContaBancaria(int numero, Cliente &titular, double saldo = 0);
    void depositar(double valor);
    void sacar(double valor);
    void transferir(double valor, ContaBancaria &destino);
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2);
    void exibirSaldo();
    void exibirInformacoes();
    int getNumero();
    bool verificarValor(double valor);
    // destrutor
    ~ContaBancaria();
};

#endif // CONTABANCARIA_H_INCLUDED