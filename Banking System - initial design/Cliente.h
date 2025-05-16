#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

class Cliente
{

private:
    // atributos privados da classe cliente
    std::string nome;
    std::string cpf;

public:
    // Construtor padrão da classe cliente
    Cliente();
    ~Cliente();
    // Construtor parâmetrizado
    Cliente(std::string nome, std::string cpf);
    // definição dos métodos getters
    std::string getNome();
    std::string getCpf();
};

#endif // CLIENTE_H_INCLUDED