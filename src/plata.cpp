#include "plata.h"

void PlataCard::procesarePlata(double pret) const {
    std::cout << "Plata cu cardul pentru suma de " << pret << " RON.\n";
    std::string numarCard;
    std::string dataExpirare;
    int cvv;
    std::cout << "Introduceti numarul cardului: ";
    std::cin >> numarCard;
    std::cout << "Introduceti data expirarii (MM/YY): ";
    std::cin >> dataExpirare;
    std::cout << "Introduceti codul CVV: ";
    std::cin >> cvv;
    std::cout << "Trimitere la serviciul de procesare a platilor...\n";
    std::cout << "Plata cu cardul a fost procesata cu succes pentru suma de " << pret << " RON.\n";
    std::cout << "Multumim pentru comanda!\n";
}

void PlataLivrare::procesarePlata(double pret) const {
    std::cout << "Plata la livrare pentru suma de " << pret << " RON.\n";
    std::string confirmation;
    std::cout << "Confirmati suma de plata (da/nu): ";
    std::cin >> confirmation;
    if (confirmation == "da") {
        std::cout << "Va rugam sa pregatiti suma exacta in numerar pentru curier.\n";
        std::cout << "Multumim pentru comanda!\n";
    } else {
        std::cout << "Plata la livrare nu a fost confirmata. Comanda a fost anulata.\n";
    }
}

template<typename T>
void makePayment(double price) {
    T metodaPlata;
    metodaPlata.procesarePlata(price);
}

template void makePayment<PlataCard>(double price);
template void makePayment<PlataLivrare>(double price);
