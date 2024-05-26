
#ifndef OOP_PIZZADESERT_H
#define OOP_PIZZADESERT_H

#include "pizza.h"

class PizzaDesert: public Pizza{
private:
    std::string ingredient_special;

public:

    PizzaDesert();

    PizzaDesert(const std::string &, const double &, std::string );

    PizzaDesert(const PizzaDesert &);

    void afisare(std::ostream &out) const override;

    [[nodiscard]] const std::string &getIngredientSpecial() const;

    void citire(std::istream &in) override;

    friend std::istream &operator>>(std::istream &, PizzaDesert &);

    friend std::ostream &operator<<(std::ostream &,const PizzaDesert &);

    ~PizzaDesert() override;
};

#endif //OOP_PIZZADESERT_H
