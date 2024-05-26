#include "pizzaclasica.h"
#include <iostream>

PizzaClasica::PizzaClasica() : Pizza("", 0.0), tip_crusta("") {};

PizzaClasica::PizzaClasica(const std::string &nume, const double &pret, const std::string &tip_crusta): Pizza(nume,pret), tip_crusta(tip_crusta){};

PizzaClasica::PizzaClasica(const PizzaClasica &aux):Pizza(aux), tip_crusta(aux.tip_crusta){};

void PizzaClasica::afisare(std::ostream &out) const {
    out << "Pizza Clasica: " << getnume() << ", Pret: " << getpret() << ", Tip de crusta: " << tip_crusta;
}

int PizzaClasica::timpPreparare() {
    int x=30;
    return x;
}

const std::string &PizzaClasica::getTipCrusta() const {
    return tip_crusta;
}

void PizzaClasica::citire(std::istream &in) {
    Pizza::citire(in);
    in.ignore();
    std::cout << "Introduceti tipul de crusta: ";
    in >> tip_crusta;
}

std::istream &operator>>(std::istream &in, PizzaClasica &p) {
    p.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const PizzaClasica &p) {
    p.afisare(out);
    return out;
}

PizzaClasica::~PizzaClasica()=default;


