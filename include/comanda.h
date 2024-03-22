
#ifndef OOP_COMANDA_H
#define OOP_COMANDA_H

#include <vector>
#include <meniu.h>
#include <pizza.h>

class Comanda{
private:
    std::vector<Pizza> comanda;
public:
    void adaugaInCos(const Pizza& pizza, int cant);
    void eliminaDinCos(size_t index);
    void afiseazaComanda() const;
    [[nodiscard]]double Total() const;
    [[nodiscard]]size_t size() const;
    ~Comanda();
};

#endif //OOP_COMANDA_H
