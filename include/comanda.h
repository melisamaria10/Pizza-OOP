
#ifndef OOP_COMANDA_H
#define OOP_COMANDA_H

#include <vector>
#include <meniu.h>
#include <pizza.h>

class Comanda{
private:
    std::vector<Pizza*> comanda;
    static int nrPizzaComandate;

public:
    void adaugaInCos(Pizza *pizza, int cant);

    void eliminaDinCos(size_t index);

    void afiseazaComanda() const;

    [[nodiscard]]double Total() const;

    [[nodiscard]]size_t size() const;

    static int getnrPizzaComandate();

    ~Comanda();
};

#endif //OOP_COMANDA_H
