
#ifndef OOP_PIZZACREATOR_H
#define OOP_PIZZACREATOR_H

#include "pizza.h"
#include "pizzaclasica.h"
#include "pizzadesert.h"

class PizzaCreator {
public:
    virtual ~PizzaCreator() = default;
    [[nodiscard]] virtual Pizza* createPizza(const std::string &nume, double pret, const std::string &extra) const = 0;
};

class PizzaClasicaCreator : public PizzaCreator {
public:
    [[nodiscard]] Pizza* createPizza(const std::string &nume, double pret, const std::string &extra) const override;
};

class PizzaDesertCreator : public PizzaCreator {
public:
    [[nodiscard]] Pizza* createPizza(const std::string &nume, double pret, const std::string &extra) const override;
};

#endif //OOP_PIZZACREATOR_H
