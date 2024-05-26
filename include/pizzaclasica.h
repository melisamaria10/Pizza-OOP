
#ifndef OOP_PIZZACLASICA_H
#define OOP_PIZZACLASICA_H

#include "pizza.h"

class PizzaClasica: public Pizza{
private:
    std::string tip_crusta;

public:

    PizzaClasica();

    PizzaClasica(const std::string &,const double &,std::string );

    [[maybe_unused]] PizzaClasica(const PizzaClasica &);

    void afisare(std::ostream &out) const override;

    //int timpPreparare();

    [[nodiscard]] const std::string &getTipCrusta() const;

    void citire(std::istream &in) override;

    friend std::istream &operator>>(std::istream &, PizzaClasica &);

    friend std::ostream &operator<<(std::ostream &,const PizzaClasica &);

    ~PizzaClasica() override;

};

#endif //OOP_PIZZACLASICA_H
