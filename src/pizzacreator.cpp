#include "pizzacreator.h"

Pizza* PizzaClasicaCreator::createPizza(const std::string &nume, double pret, const std::string &extra) const {
    return new PizzaClasica(nume, pret, extra);
}

Pizza* PizzaDesertCreator::createPizza(const std::string &nume, double pret, const std::string &extra) const {
    return new PizzaDesert(nume, pret, extra);
}
