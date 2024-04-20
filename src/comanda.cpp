#include <comanda.h>
#include <iostream>


int Comanda::nrPizzaComandate=0;

void Comanda::adaugaInCos(Pizza *pizza, int cant){
    for (int i = 0; i < cant; i++) {
        comanda.push_back(pizza);
        nrPizzaComandate++;
    }
}

void Comanda::eliminaDinCos(size_t index){
    if(index < comanda.size()){
        std::cout<< "Pizza " << comanda[index]->getnume()<< " a fost eliminata din cos.\n";
        comanda.erase(comanda.begin()+index);
    }
    else {
        throw std::out_of_range("Index invalid. Pizza nu a fost eliminata din cos.\n");
    }
}

void Comanda::afiseazaComanda() const{
    Pizza* currentPizza = comanda[0];
    int count = 1;
    double totalCost = currentPizza->getpret();
    for (size_t i = 1; i < comanda.size(); ++i) {
        if (comanda[i] == currentPizza) {
            count++;
            totalCost += currentPizza->getpret();
        } else {
            std::cout << count << "x " << currentPizza->getnume() << " - Pret: " << totalCost << " RON\n";
            currentPizza = comanda[i];
            count = 1;
            totalCost = currentPizza->getpret();
        }
    }
    std::cout << count << "x " << currentPizza->getnume() << " - Pret: " << totalCost << " RON\n";
}

double Comanda::Total() const{
    double total=0.0;
    for(const auto& pizza : comanda){
        total=total + pizza->getpret();
    }
    return total;
}

size_t Comanda::size() const {
    return comanda.size();
}

int Comanda::getnrPizzaComandate() {
    return nrPizzaComandate;
}

Comanda::~Comanda()=default;
