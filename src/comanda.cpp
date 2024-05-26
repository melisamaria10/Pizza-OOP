#include "comanda.h"
#include "pizzaclasica.h"
#include "pizzadesert.h"
#include <iostream>
#include <algorithm>


int Comanda::nrPizzaComandate=0;

Comanda::Comanda(PricingStrategy* pricingStrategy) : pricingStrategy_(pricingStrategy) {}

void Comanda::adaugaInCos(Pizza *pizza, int cant){
    for (int i = 0; i < cant; i++) {
        comanda.push_back(pizza);
        nrPizzaComandate++;
    }
}

void Comanda::eliminaDinCos(size_t index) {

    std::vector<Pizza*> comanda_sortata = comanda;
    std::sort(comanda_sortata.begin(), comanda_sortata.end(), [](Pizza* a, Pizza* b) {
        return a->getnume() < b->getnume();
    });

    if (index < comanda_sortata.size()) {
        Pizza* pizzaDeEliminat = comanda_sortata[index];
        auto it = std::find(comanda.begin(), comanda.end(), pizzaDeEliminat);
        if (it != comanda.end()) {
            std::cout << "Pizza " << (*it)->getnume() << " a fost eliminata din cos.\n";
            comanda.erase(it);
            nrPizzaComandate--;
        }
    } else {
        throw std::out_of_range("Index invalid. Pizza nu a fost eliminata din cos.\n");
    }
}

void Comanda::afiseazaComanda() const {
    std::vector<Pizza*> comanda_sortata = comanda;
    std::sort(comanda_sortata.begin(), comanda_sortata.end(), [](Pizza* a, Pizza* b) {
        return a->getnume() < b->getnume();
    });

    Pizza* currentPizza = comanda_sortata[0];
    int count = 1;
    double totalCost = currentPizza->getpret();
    for (size_t i = 1; i < comanda_sortata.size(); ++i) {
        if (comanda_sortata[i] == currentPizza) {
            count++;
            double price = currentPizza->getpret();
            totalCost += price;
        } else {
            std::cout << count << "x " << currentPizza->getnume() << " - Pret: " << totalCost << " RON";

            auto* pizzaClasica = dynamic_cast<PizzaClasica*>(currentPizza);
            if (pizzaClasica != nullptr) {
                std::cout << " - Tip crusta: " << pizzaClasica->getTipCrusta();
            }

            auto* pizzaDesert = dynamic_cast<PizzaDesert*>(currentPizza);
            if (pizzaDesert != nullptr) {
                std::cout << " - Ingredient special: " << pizzaDesert->getIngredientSpecial();
            }
            std::cout << std::endl;

            currentPizza = comanda_sortata[i];
            count = 1;
            totalCost = currentPizza->getpret();
        }
    }

    std::cout << count << "x " << currentPizza->getnume() << " - Pret: " << totalCost << " RON";

    auto* pizzaClasica = dynamic_cast<PizzaClasica*>(currentPizza);
    if (pizzaClasica != nullptr) {
        std::cout << " - Tip crusta: " << pizzaClasica->getTipCrusta();
    }

    auto* pizzaDesert = dynamic_cast<PizzaDesert*>(currentPizza);
    if (pizzaDesert != nullptr) {
        std::cout << " - Ingredient special: " << pizzaDesert->getIngredientSpecial();
    }
    std::cout << std::endl;
}

double Comanda::Total() const{
    double total=0.0;
    for(const auto& pizza : comanda){
        total=total + pizza->getpret();
    }
    total= pricingStrategy_->calculatePrice(total);
    return total;
}

size_t Comanda::size() const {
    return comanda.size();
}

int Comanda::getnrPizzaComandate() {
    return nrPizzaComandate;
}

Comanda::~Comanda()=default;
