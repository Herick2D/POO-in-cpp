// Estudo de polimorfismo em C++

#include <iostream>
using namespace std;

// Classe abstrata Animal
class Animal {
public:
    virtual void fazerSom() = 0; // Método virtual puro
};

// Classe derivada Cachorro
class Cachorro : public Animal {
public:
    void fazerSom() override { // Implementação do método virtual
        cout << "O cachorro faz au au!" << endl;
    }
};

// Classe derivada Gato
class Gato : public Animal {
public:
    void fazerSom() override { // Implementação do método virtual
        cout << "O gato faz miau!" << endl;
    }
};

int main() {
    // Cria um ponteiro para Animal e duas instâncias de classes derivadas
    Animal *animal;
    Cachorro cachorro;
    Gato gato;
    
    // Atribui o ponteiro para a instância de Cachorro e chama o método fazerSom()
    animal = &cachorro;
    animal->fazerSom();
    
    // Atribui o ponteiro para a instância de Gato e chama o método fazerSom()
    animal = &gato;
    animal->fazerSom();
    
    return 0;
}
// g++ -o animal Animal.cpp - como os métodos se resolvem rápido visivelmente o terminal abre e fecha