// Estudo de atributo em C++

#include <iostream>
using namespace std;

class Carro {
  private:
    string marca;
    string modelo;
    int ano;

  public:
    Carro(string m, string mod, int a) {
      marca = m;
      modelo = mod;
      ano = a;
    }

    void imprimirDados() {
      cout << "Marca: " << marca << endl;
      cout << "Modelo: " << modelo << endl;
      cout << "Ano: " << ano << endl;
    }

    void setMarca(string m) {
      marca = m;
    }

    void setModelo(string mod) {
      modelo = mod;
    }

    void setAno(int a) {
      ano = a;
    }
};

int main() {
  Carro meuCarro("Fiat", "Uno", 2010);
  meuCarro.imprimirDados();
  meuCarro.setMarca("Chevrolet");
  meuCarro.setModelo("Onix");
  meuCarro.setAno(2021);
  meuCarro.imprimirDados();
  return 0;
}

// g++ -o carro Carro.cpp - como os métodos se resolvem rápido visivelmente o terminal abre e fecha