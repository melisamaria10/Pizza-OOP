#include "pizzadesert.h"
#include <iostream>


PizzaDesert::PizzaDesert() : Pizza("", 0.0), ingredient_special("") {}

 PizzaDesert::PizzaDesert(const std::string &nume,const double &pret, const std::string &ingredient_special): Pizza(nume,pret), ingredient_special(ingredient_special){}

[[maybe_unused]] PizzaDesert::PizzaDesert(const PizzaDesert &aux): Pizza(aux), ingredient_special(aux.ingredient_special){};

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
