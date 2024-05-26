
#ifndef OOP_PLATA_H
#define OOP_PLATA_H

#include <iostream>

template<typename T>
class Plata {
public:
    virtual ~Plata() = default;
    virtual void procesarePlata(double amount) const = 0;
};

class PlataCard : public Plata<PlataCard> {
public:
    void procesarePlata(double pret) const override;
};

class PlataLivrare : public Plata<PlataLivrare> {
public:
    void procesarePlata(double pret) const override;
};

template<typename T>
void makePayment(double price);

#endif //OOP_PLATA_H
