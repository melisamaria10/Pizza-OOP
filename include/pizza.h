
#ifndef OOP_PIZZA_H
#define OOP_PIZZA_H

#include <string>

class Pizza {
private:
    std::string nume;
    double pret;
public:
    Pizza(const std::string &, const double &);

    Pizza(const Pizza &);

    [[nodiscard]] const std::string &getnume() const;

    [[nodiscard]] const double &getpret() const;

    friend bool operator==(const Pizza &, const Pizza &) ;

    friend std::istream &operator>>(std::istream &, Pizza &);

    friend std::ostream &operator<<(std::ostream &,const Pizza &);

    Pizza& operator=(const Pizza& other);

    ~Pizza();
};
#endif //OOP_PIZZA_H
