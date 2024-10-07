// Estudo de métodos virtuais em C++

#include <iostream>
#include <string>

using namespace std;

// Classe base Conta
class Conta {
protected:
    string titular;
    double saldo;

public:
    Conta(string nome, double saldo_inicial) {
        titular = nome;
        saldo = saldo_inicial;
    }

    virtual void depositar(double valor) {
        saldo += valor;
    }

    virtual void sacar(double valor) {
        saldo -= valor;
    }

    virtual void mostrarSaldo() {
        cout << "Saldo atual: " << saldo << endl;
    }
};

// Classe derivada ContaCorrente
class ContaCorrente : public Conta {
public:
    ContaCorrente(string nome, double saldo_inicial) : Conta(nome, saldo_inicial) {}

    virtual void sacar(double valor) {
        saldo -= valor + 0.10;
    }
};

// Classe derivada ContaPoupanca
class ContaPoupanca : public Conta {
public:
    ContaPoupanca(string nome, double saldo_inicial) : Conta(nome, saldo_inicial) {}

    virtual void depositar(double valor) {
        saldo += valor * 1.05;
    }
};

int main() {
    // Cria uma ContaCorrente e faz algumas operações
    ContaCorrente contaCorrente("João", 5000);
    contaCorrente.mostrarSaldo();
    contaCorrente.sacar(500);
    contaCorrente.mostrarSaldo();

    // Cria uma ContaPoupanca e faz algumas operações
    ContaPoupanca contaPoupanca("Maria", 2000);
    contaPoupanca.mostrarSaldo();
    contaPoupanca.depositar(1000);
    contaPoupanca.mostrarSaldo();

    return 0;
}

// g++ -o conta Conta.cpp - como os métodos se resolvem rápido visivelmente o terminal abre e fecha