#include "pizza.h"
#include <iostream>


int Pizza::nrTotalPizza=0;

Pizza::Pizza(const std::string &nume, const double &pret){
    this->nume = nume;
    this->pret = pret;
    nrTotalPizza++;
}

Pizza::Pizza(const Pizza& aux){
    this->nume=aux.nume;
    this->pret=aux.pret;
}

Pizza::~Pizza()= default;

std::istream &operator>>(std::istream &in, Pizza &p) {
    std::getline(in,p.nume,'\n');
    in>>p.pret;
    return in;
}

std::ostream &operator<<(std::ostream &out,const Pizza &p) {
    out << p.nume;
    out << p.pret;
    return out;
}

const std::string &Pizza::getnume() const {
    return nume;
}

const double &Pizza::getpret() const {
    return pret;
}

int Pizza::getnrTotalPizza() {
    return nrTotalPizza;
}

void Pizza::citire(std::istream &in){
    std::cout << "Introduceti numele pizzei: ";
    std::getline(in, nume, '\n');
    std::cout << "Introduceti pretul: ";
    in >> pret;
};

bool operator==(const Pizza &a,const Pizza &b){
    return a.nume==b.nume && a.pret==b.pret;
}

Pizza& Pizza::operator=(const Pizza& other) {
    if (this != &other) {
        nume = other.nume;
        pret = other.pret;
    }
    return *this;
}
