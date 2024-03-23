#include <meniu.h>
#include <comanda.h>
#include <iostream>

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
    Pizza p1("Margherita",37.56);
    Pizza p2("Diavola",35.98);
    Pizza p3("Quattro Stagioni",39.67);
    Pizza p4("Pepperoni",34.99);
    Pizza p5("Quattro Formaggi",39.99);
    Pizza p6("Capriciosa",32.79);
    Pizza p7("Prosciutto e Funghi",36.87);
    Pizza p8("Vegetariana",32.99);
    Pizza p9("Calzone",31.97);
    Meniu meniu;
    meniu.adaugaPizza(p1);
    meniu.adaugaPizza(p2);
    meniu.adaugaPizza(p3);
    meniu.adaugaPizza(p4);
    meniu.adaugaPizza(p5);
    meniu.adaugaPizza(p6);
    meniu.adaugaPizza(p7);
    meniu.adaugaPizza(p8);
    meniu.adaugaPizza(p9);
    Comanda comanda;
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
                    if (pizza.getnume() == nume_pizza) {
                        comanda.adaugaInCos(pizza, cant);
                        pizza_gasita = true;
                        break;
                    }
                }
                if (!pizza_gasita) {
                    std::cout << "Pizza nu este disponibila in meniu.\n";
                    afisare_meniu();
                } else {
                    std::cout << "Pizza"<<" "<<nume_pizza<<" a fost adaugata cu succes.\n";
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
                    std::cout << "Te rugam sa introduci numarul pizzei pe care vrei sa o elimini: ";
                    size_t index;
                    std::cin >> index;
                    comanda.eliminaDinCos(index - 1);
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
                    std::cout << "\nTotalul de plata este: " << comanda.Total() << " RON\n";
                    std::cout << "Comanda finalizata!\n";
                    afisare_Meniu = false;
                }
                break;
            }
        }
    }
}
