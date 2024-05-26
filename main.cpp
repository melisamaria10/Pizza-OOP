#include "meniu.h"
#include "comanda.h"
#include <iostream>
#include "plata.h"
#include "pizzacreator.h"

void afisare_meniu(){
    std::cout << "1.Vizualizeaza meniu"<<std::endl;
    std::cout << "2.Adauga in cos" << std::endl;
    std::cout << "3.Modifica cos"<<std::endl;
    std::cout<< "4.Vizualizare cos"<<std::endl;
    std::cout<< "5.Finalizare comanda" << std::endl;
    std::cout << "0.Exit"<<std::endl;
    std::cout <<"Choice: ";
}
int main() {
    Meniu meniu;

    PricingStrategy *weekendStrategy = new WeekendPricing();
    PricingStrategy *weekdayStrategy = new NormalPricing();

    Comanda comanda(weekendStrategy); //am setat la pretul de weekend

    PizzaCreator *pizzaClasicaCreator = new PizzaClasicaCreator();
    PizzaCreator *pizzaDesertCreator = new PizzaDesertCreator();

    Pizza *p1 = pizzaClasicaCreator->createPizza("Quattro Formaggi", 33.98, "subtire\n");
    Pizza *p2 = pizzaClasicaCreator->createPizza("Diavola", 34.61, "groasa\n");
    Pizza *p3 = pizzaDesertCreator->createPizza("Nutella", 27.21, "ciocolata\n");
    Pizza *p4 = pizzaClasicaCreator->createPizza("Margherita", 36.43, "crocanta\n");
    Pizza *p5 = pizzaDesertCreator->createPizza("Frutta", 30.24, "capsuni\n");
    Pizza *p6 = pizzaDesertCreator->createPizza("Stella", 33.10, "vanilie\n");
    Pizza *p7 = pizzaClasicaCreator->createPizza("Pepperoni", 34.99, "pufoasa\n");
    Pizza *p8 = pizzaClasicaCreator->createPizza("Quattro Stagioni", 36.56, "subtire\n");
    Pizza *p9 = pizzaClasicaCreator->createPizza("Prosciuto e Funghi", 35.89, "crocanta\n");
    Pizza *p10 = pizzaDesertCreator->createPizza("Deliciosa", 26.98,"banane\n"); //PizzaDesert p10("Deliciosa",26.98,"banane\n")
    meniu.adaugaPizza(p1);
    meniu.adaugaPizza(p2);
    meniu.adaugaPizza(p3);
    meniu.adaugaPizza(p4);
    meniu.adaugaPizza(p5);
    meniu.adaugaPizza(p6);
    meniu.adaugaPizza(p7);
    meniu.adaugaPizza(p8);
    meniu.adaugaPizza(p9);
    meniu.adaugaPizza(p10);


    //verificare downcasting

    /*PizzaClasica *classicPizzaPtr1 = dynamic_cast<PizzaClasica *>(ptr1);
    classicPizzaPtr1->afisare(std::cout);
    if (classicPizzaPtr1) {
        std::cout << classicPizzaPtr1->timpPreparare() << std::endl;
    } else {
        std::cout << "Downcast failed" << std::endl;
    }

    PizzaDesert *dessertPizzaPtr = dynamic_cast<PizzaDesert *>(ptr2);
    std::cout << dessertPizzaPtr->getIngredientSpecial() << std::endl; */

    std::cout << "Meniul contine " << Pizza::getnrTotalPizza() << " tipuri de pizza" << std::endl;

    int choice;
    int metodaPlata;
    afisare_meniu();
    bool afisare_Meniu = true;
    while (afisare_Meniu) {
        std::cin >> choice;
        std::cin.get();
        switch (choice) {
            case 0: {
                std::cout << "Ati iesit din aplicatie";
                afisare_Meniu = false;
                break;
            }
            case 1: {
                meniu.afisareMeniu();
                afisare_meniu();

                break;
            }
            case 2: {
                std::cout << "Introduceti numele pizzei si cantitatea dorita: ";
                std::string nume_pizza;
                int cant;
                std::getline(std::cin, nume_pizza);
                std::cin >> cant;
                if (cant > 0) {
                    // Cautam pizza in meniu
                    bool pizza_gasita = false;
                    for (const auto &pizza : meniu.getPizzas()) {
                        if (pizza->getnume() == nume_pizza) {
                            comanda.adaugaInCos(pizza, cant);
                            pizza_gasita = true;
                            std::cout << "Pizza a fost adaugata cu succes.\n";
                            break;
                        }
                    }
                    if (!pizza_gasita) {
                        std::cout << "Pizza nu este disponibila in meniu.\n";
                    }
                } else {
                    std::cout << "Cantitatea trebuie sa fie mai mare decat 0.\n";
                }
                afisare_meniu();
                break;
            }
            case 3: {
                if (comanda.size() == 0) {
                    std::cout << "Cosul este gol, nu se poate elimina niciun produs.\n";
                    afisare_meniu();
                } else {
                    try {
                        std::cout << "Te rugam sa introduci numarul pizzei pe care vrei sa o elimini: ";
                        size_t index;
                        std::cin >> index;
                        comanda.eliminaDinCos(index - 1);

                    } catch (const std::out_of_range &e) {
                        std::cout << e.what() << std::endl;
                    }
                    afisare_meniu();
                }
                break;
            }
            case 4: {
                if (comanda.size() == 0) {
                    std::cout << "Cosul este gol.\n";
                    afisare_meniu();

                } else {
                    comanda.afiseazaComanda();
                    afisare_meniu();

                }
                break;
            }
            case 5: {
                if (comanda.size() == 0) {
                    std::cout << "Cosul este gol.Pentru a finaliza comanda trebuie sa aveti minim un produs.\n";
                    afisare_meniu();

                } else {
                    comanda.afiseazaComanda();
                    std::cout << "Ati comandat: " << Comanda::getnrPizzaComandate() << " pizza\n";
                    std::cout << "\nTotalul de plata este: " << comanda.Total() << " RON\n";
                    afisare_Meniu = false;
                    bool plataValida= false;
                    while (!plataValida) {
                        std::cout << "Alegeti metoda de plata:\n";
                        std::cout << "1. Plata cu cardul\n";
                        std::cout << "2. Plata la livrare\n";
                        std::cout << "Choice: ";
                        std::cin >> metodaPlata;

                        switch (metodaPlata) {
                            case 1: {
                                makePayment<PlataCard>(comanda.Total());
                                plataValida = true;
                                break;
                            }
                            case 2: {
                                makePayment<PlataLivrare>(comanda.Total());
                                plataValida = true;
                                break;
                            }
                            default: {
                                std::cout << "Optiune invalida pentru metoda de plata.\n";
                                break;
                            }
                        }
                    }

                }
                break;
            }
        }
    }
    delete pizzaClasicaCreator;
    delete pizzaDesertCreator;
    delete weekendStrategy;
    delete weekdayStrategy;
}