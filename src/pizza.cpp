#include "pizza.h"
#include <iostream>

Pizza::Pizza(const std::string &nume, const float &pret){
    this->nume = nume;
    this->pret = pret;
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
std::ostream &operator<<(std::ostream &out, Pizza &p) {
    out << p.nume;
    out << p.pret;
    return out;
}
const std::string &Pizza::getnume() const {
    return nume;
}
const float &Pizza::getpret() const {
    return pret;
}
bool operator==(const Pizza &a,const Pizza &b){
    return a.nume==b.nume && a.pret==b.pret;
}
