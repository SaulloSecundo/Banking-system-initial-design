#include <iostream>
#include "Cliente.h"

using namespace std;

// implementação do construtor padrão da classe cliente
Cliente::Cliente()
{
    this->nome = " ";
    this->cpf = " ";
}
// implementação do construtor parâmetrizado da classe cliente
Cliente::Cliente(string nome, string cpf)
{
    this->nome = nome;
    this->cpf = cpf;
}
// implementação dos métodos getters da classe cliente
string Cliente::getNome()
{
    return this->nome;
}

string Cliente::getCpf()
{
    return this->cpf;
}

Cliente::~Cliente()
{
}