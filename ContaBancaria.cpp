#include <iostream>
#include "ContaBancaria.h"

using namespace std;

// implementação do construtor parâmetrizado da classe ContaBancaria
ContaBancaria::ContaBancaria(int numero, Cliente &titular, double saldo)
{
    this->numero = numero;
    this->titular = titular;
    // verifica se o valor inicial informado na nova instância é maior ou igual a 0, eliminando a possibilidade de criar uma conta com saldo negativo.
    if (saldo >= 0)
    {
        this->saldo = saldo;
    }
    else
    {
        this->saldo = 0;
    }
}
// método para classificar a validade do valor inserido em qualquer uma das operações anteriores
bool ContaBancaria::verificarValor(double valor)
{
    // caso o valor informado for maior que 0 e menor que o saldo atual da conta, esta quantia será válida para as operações de tranferência e saque de valores.
    if ((valor > 0) && (valor <= this->saldo))
    {
        return true;
    }
    else
    {
        cout << "Valor indisponivel. Verifique novamente a operação e tente novamente." << endl;
        return false;
    }
}
// método para para depositar valor em uma determinada conta
void ContaBancaria::depositar(double valor)
{
    // verifica se o valor a ser depositado é maior que 0. Caso não, não deposita
    if (valor > 0)
    {
        this->saldo += valor;
    }
    else
    {
        cout << "Nao e possivel depositar valores negativos. Corrija o valor do deposito e tente novamente." << endl;
    }
}
// método para sacar valor de uma determinada conta
void ContaBancaria::sacar(double valor)
{
    // verifica se o valor a ser sacado é coerente com a situação atual do saldo da conta. Caso não, não saca
    if (verificarValor(valor))
    {
        this->saldo -= valor;
    }
}
// método para tranferência de valor para uma conta específica
void ContaBancaria::transferir(double valor, ContaBancaria &destino)
{
    // verificando o valor informado antes da operação
    if (verificarValor(valor))
    {
        sacar(valor);
        destino.depositar(valor);
        cout << "Transferido: R$ " << valor << " da conta " << this->numero << " para a conta " << destino.getNumero() << endl;
    }
}
// método para tranferência de valores para duas contas distintas
void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2)
{
    // verificando o valor informado antes da operação
    if (verificarValor(valor))
    {
        sacar(valor);
        destino1.depositar(valor / 2);
        destino2.depositar(valor / 2);
        cout << "Transferido: R$ " << valor / 2 << " para cada conta (" << destino1.getNumero() << " e " << destino2.getNumero() << ") da conta " << this->numero << endl;
    }
}
// método para visualizar o saldo de determinada conta
void ContaBancaria::exibirSaldo()
{
    cout << "Saldo atual da conta " << this->numero << ":" << " R$ " << this->saldo << endl;
}
// Exibe as informações do proprietário, o número e o saldo de determinada conta
void ContaBancaria::exibirInformacoes()
{
    cout << "Titular: " << titular.getNome() << ", " << "CPF: " << titular.getCpf() << endl;
    cout << "Numero da conta: " << this->numero << ", " << "Saldo: " << "R$ " << this->saldo << endl;
}
// método get para retorno do número da conta
int ContaBancaria::getNumero()
{
    return this->numero;
}

ContaBancaria::~ContaBancaria()
{
}
