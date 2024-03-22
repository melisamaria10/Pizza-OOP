
#ifndef OOP_PIZZA_H
#define OOP_PIZZA_H

#include <string>

class Pizza {
private:
    std::string nume;
    float pret;
public:
    Pizza(const std::string &, const float &);

    Pizza(const Pizza &);

    [[nodiscard]] const std::string &getnume() const;

    [[nodiscard]] const float &getpret() const;

    friend bool operator==(const Pizza &, const Pizza &) ;

    friend std::istream &operator>>(std::istream &, Pizza &);

    friend std::ostream &operator<<(std::ostream &, Pizza &);
    ~Pizza();
};
#endif //OOP_PIZZA_H
