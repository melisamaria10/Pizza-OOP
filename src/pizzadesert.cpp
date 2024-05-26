#include "pizzadesert.h"
#include <iostream>
#include <utility>


PizzaDesert::PizzaDesert() : Pizza("", 0.0) {}

 PizzaDesert::PizzaDesert(const std::string &nume,const double &pret, std::string ingredient_special): Pizza(nume,pret), ingredient_special(std::move(ingredient_special)){}

[[maybe_unused]] PizzaDesert::PizzaDesert(const PizzaDesert &aux) = default;

void PizzaDesert::afisare(std::ostream &out) const{
    out<<"Pizza Desert: "<<getnume()<<" ,Pret: "<<getpret()<<" , Ingredient special: "<<ingredient_special;
}

const std::string &PizzaDesert::getIngredientSpecial() const {
    return ingredient_special;
}

void PizzaDesert::citire(std::istream &in){
    Pizza::citire(in);
    in.ignore();
    std::cout<<"Introduceti ingredientul special: ";
    in >> ingredient_special;
}

std::istream &operator>>(std::istream &in, PizzaDesert &p) {
    p.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const PizzaDesert &p) {
    p.afisare(out);
    return out;
}

PizzaDesert::~PizzaDesert()=default;
