#include <meniu.h>
#include <comanda.h>
#include <iostream>
#include "pizzaclasica.h"
#include "pizzadesert.h"

void afisare_meniu(){
    std::cout << "1.Vizualizeaza meniu"<<std::endl;
    std::cout << "2.Adauga in cos" << std::endl;
    std::cout << "3.Modifica cos"<<std::endl;
    std::cout<< "4.Vizualizare cos"<<std::endl;
    std::cout<< "5.Finalizare comanda" << std::endl;
    std::cout << "0.Exit"<<std::endl;
    std::cout <<"Choice: ";
}
int main(){
    Meniu meniu;
    Comanda comanda;
    PizzaClasica p1("Quattro Formaggi",33.98,"subtire\n");
    PizzaClasica p2("Diavola",34.61,"groasa\n");
    PizzaDesert p3("Nutella",27.21,"ciocolata \n");
    PizzaClasica p4("Margherita",36.43,"crocanta\n");
    PizzaDesert p5("Frutta", 30.24,"capsuni\n");
    PizzaDesert p6("Stella",33.10,"vanilie\n");
    PizzaClasica p7("Pepperoni",34.99,"pufoasa\n");
    PizzaClasica p8("Quattro Stagioni",36.56,"subtire\n");
    PizzaClasica p9("Prosciuto e Funghi",35.89,"crocanta\n");
    PizzaDesert p10; //PizzaDesert p10("Deliciosa",26.98,"banane\n")
    std::cin>>p10;
    meniu.adaugaPizza(&p1);
    meniu.adaugaPizza(&p2);
    meniu.adaugaPizza(&p3);
    meniu.adaugaPizza(&p4);
    meniu.adaugaPizza(&p5);
    meniu.adaugaPizza(&p6);
    meniu.adaugaPizza(&p7);
    meniu.adaugaPizza(&p8);
    meniu.adaugaPizza(&p9);
    meniu.adaugaPizza(&p10);

    //verificare upcasting
    std::cout<<"///Verificare upcasting///"<<std::endl;
    Pizza *ptr1=&p1;
    ptr1->afisare(std::cout);
    std::cout<<ptr1->getnume()<<std::endl;

    Pizza *ptr2=&p3;
    std::cout<<ptr2->getpret()<<std::endl;

    //verificare downcasting
    std::cout<<"///Verificare downcasting///"<<std::endl;
    auto* classicPizzaPtr1 = dynamic_cast<PizzaClasica*>(ptr1);
    classicPizzaPtr1->afisare(std::cout);
    std::cout << classicPizzaPtr1->getTipCrusta() << std::endl;

    auto* dessertPizzaPtr= dynamic_cast<PizzaDesert*>(ptr2);
    std::cout<< dessertPizzaPtr->getIngredientSpecial()<<std::endl;

    std::cout<<"Meniul contine "<<Pizza::getnrTotalPizza()<<" tipuri de pizza"<<std::endl;

    int choice;
    afisare_meniu();
    bool afisare_Meniu=true;
    while(afisare_Meniu){
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
                //cauta pizza in meniu
                bool pizza_gasita = false;
                for (const auto &pizza: meniu.getPizzas()) {
                    if (pizza->getnume() == nume_pizza) {
                        comanda.adaugaInCos(pizza, cant);
                        pizza_gasita = true;
                        break;
                    }
                }
                if (!pizza_gasita) {
                    std::cout << "Pizza nu este disponibila in meniu.\n";
                    afisare_meniu();
                } else {
                    std::cout << "Pizza a fost adaugata cu succes.\n";
                    afisare_meniu();
                }
                break;
            }
            case 3: {
                if(comanda.size()==0){
                    std::cout<<"Cosul este gol, nu se poate elimina niciun produs.\n";
                    afisare_meniu();
                }
                else {
                    try{
                        std::cout << "Te rugam sa introduci numarul pizzei pe care vrei sa o elimini: ";
                        size_t index;
                        std::cin >> index;
                        comanda.eliminaDinCos(index - 1);

                    } catch(const std::out_of_range &e){
                        std::cout<<e.what()<<std::endl;
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
                    std::cout<<"Ati comandat: "<<Comanda::getnrPizzaComandate()<<" pizza\n";
                    std::cout << "\nTotalul de plata este: " << comanda.Total() << " RON\n";
                    std::cout << "Comanda finalizata!\n";
                    afisare_Meniu = false;
                }
                break;
            }
        }
    }
}