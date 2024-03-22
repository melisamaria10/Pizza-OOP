#include <meniu.h>
#include <iostream>
#include <vector>

const std::vector<Pizza>& Meniu::getPizzas() const {
    return pizzas;
}

void Meniu::adaugaPizza(const Pizza& pizza) {
    pizzas.push_back(pizza);
}

void Meniu::afisareMeniu() const{
    std::cout << "Meniu:\n";
    for(const auto& pizza:pizzas){
        std::cout <<pizza.getnume()<< " - Pret: "<<pizza.getpret()<<" RON\n";
    }
}
Meniu::~Meniu()=default;
