
#ifndef OOP_MENIU_H
#define OOP_MENIU_H

#include <vector>
#include <pizza.h>

class Meniu {
private:
    std::vector<Pizza> pizzas;
public:
    void adaugaPizza(const Pizza& pizza);
    void afisareMeniu() const;
    [[nodiscard]]const std::vector<Pizza>& getPizzas() const;
    ~Meniu();
};

#endif //OOP_MENIU_H
