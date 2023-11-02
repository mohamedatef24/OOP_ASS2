#ifndef BIGREAL_H
#define BIGREAL_H

#include <iostream>
#include <string>

class Bigreal
{
private:
    std::string num;
    bool isValidReal(std::string n);

    std::string real; // Member variable for real part
    std::string frac; // Member variable for fractional part
    char sign;        // Member variable for the sign
    int decimal_point_pos; // member variable for the position of the decimal point

public:
    Bigreal(std::string num,int decimal_point_pos=-1);
    virtual ~Bigreal();

    std::string getReal() const; // Member function to get the real part
    std::string getFraction() const; // Member function to get the fractional part
    char getSign() const; // Member function to get the sign
    int getDecimal_point_pos() const; // Member function to get the position of the decimal point
    void setNum(const std::string &n); // member function to set number
    friend std::ostream& operator<<(std::ostream& os, const Bigreal& bigreal); // friend function to print the number
    bool operator< (const Bigreal &anotherReal)const ;
    bool operator> (const Bigreal &anotherReal) const;
    bool operator== (const Bigreal &anotherReal)const;
};

#endif // BIGREAL_H
