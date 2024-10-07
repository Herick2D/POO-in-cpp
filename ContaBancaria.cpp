// Estudo de Herança C++

#include <iostream>
using namespace std;

// classe base
class ContaBancaria {
  protected:
    double saldo;
  
  public:
    ContaBancaria(double s) {
      saldo = s;
    }

    virtual void depositar(double valor) {
      saldo += valor;
      cout << "Depósito de R$" << valor << " realizado. Novo saldo: R$" << saldo << endl;
    }

    virtual void sacar(double valor) {
      if (saldo >= valor) {
        saldo -= valor;
        cout << "Saque de R$" << valor << " realizado. Novo saldo: R$" << saldo << endl;
      } else {
        cout << "Saldo insuficiente para realizar o saque." << endl;
      }
    }
};

// classe derivada
class ContaPoupanca : public ContaBancaria {
  private:
    double taxaJuros;

  public:
    ContaPoupanca(double s, double tj) : ContaBancaria(s) {
      taxaJuros = tj;
    }

    void depositar(double valor) override {
      saldo += valor;
      cout << "Depósito de R$" << valor << " realizado na conta poupança. Novo saldo: R$" << saldo << endl;
      saldo += saldo * taxaJuros;
      cout << "Juros de R$" << saldo*taxaJuros << " adicionados à conta poupança. Novo saldo: R$" << saldo << endl;
    }
};

int main() {
  ContaBancaria* conta1 = new ContaBancaria(5000);
  ContaPoupanca* conta2 = new ContaPoupanca(2000, 0.05);

  conta1->depositar(1000);
  conta2->depositar(500);

  conta1->sacar(2000);
  conta2->sacar(10000);

  delete conta1;
  delete conta2;

  return 0;
}

// g++ -o conta ContaBancaria.cpp - como os métodos se resolvem rápido visivelmente o terminal abre e fecha