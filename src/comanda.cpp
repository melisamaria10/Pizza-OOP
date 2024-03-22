#include <comanda.h>
#include <iostream>

void Comanda::adaugaInCos(const Pizza& pizza, int cant){
    bool pizza_exista=false;
    for(Pizza &p: comanda){
        if(p.getnume()==pizza.getnume()){
            for(int i=0; i<cant;i++){
                comanda.push_back(p);
            }
            pizza_exista=true;
            break;
        }
    }
    if(!pizza_exista) {
        for (int i = 0; i < cant; i++) {
            comanda.push_back(pizza);
        }
    }
}
void Comanda::eliminaDinCos(size_t index){
    if(index < comanda.size()){
        std::cout<< "Pizza " << comanda[index].getnume()<< " a fost eliminata din cos.\n";
        comanda.erase(comanda.begin()+index);
    }
    else {
        std::cout<<"Index invalid. Pizza nu a fost eliminata din cos.\n";
    }
}
void Comanda::afiseazaComanda() const{
    Pizza currentPizza = comanda[0];
    int count = 1;
    float totalCost = currentPizza.getpret();
    for (size_t i = 1; i < comanda.size(); ++i) {
        if (comanda[i] == currentPizza) {
            count++;
            totalCost += currentPizza.getpret();
        } else {
            std::cout << count << "x " << currentPizza.getnume() << " - Pret: " << totalCost << " RON\n";
            currentPizza = comanda[i];
            count = 1;
            totalCost = currentPizza.getpret();
        }
    }
    std::cout << count << "x " << currentPizza.getnume() << " - Pret: " << totalCost << " RON\n";
}
float Comanda::Total() const{
    float total=0.0;
    for(const auto& pizza : comanda){
        total=total + pizza.getpret();
    }
    return total;
}
size_t Comanda::size() const {
    return comanda.size();
}
Comanda::~Comanda()=default;
