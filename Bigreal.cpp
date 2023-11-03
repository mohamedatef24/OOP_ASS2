#include "Bigreal.h"
#include <tuple>
#include <algorithm>

bool flag=0;
Bigreal::Bigreal(std::string num,int decimal_point_pos) : num(num) ,decimal_point_pos(decimal_point_pos) {
    if (isValidReal(num)) {
        std::cout << "Valid Real\n";
        flag=1;
    } else {
        std::cout << "Invalid Real\n";
    }
}

Bigreal::~Bigreal() {}

bool Bigreal::isValidReal(std::string n) {
    real = "";  // Initialize real part
    frac = "";  // Initialize fractional part
    sign = '+'; // Initialize sign

    if (n.empty()) {
        return false; // Empty string is not a valid real number
    }

    int i = 0;

    if (n[i] == '+' || n[i] == '-') {
        sign = n[i];
        i++;
    }

    bool hasDot = false; // To track if a dot is encountered

    while (i < n.length()) {
        if (n[i] == '.' && !hasDot) {
            hasDot = true;
            decimal_point_pos=i;
        } else if (n[i] >= '0' && n[i] <= '9') {
            if (hasDot) {
                frac += n[i];
            } else {
                real += n[i];
            }
        } else {
            return false; // Invalid character
        }
        i++;
    }

    // Ensure at least one digit is present
    if (real.empty() && frac.empty()) {
        return false;
    }
    std::string r{""},f{""};
    int j=0;
    for(;j<(int)real.size();j++)
    {
        if(real[j]!='0') break;
    }
    for(j+1;j<(int)real.size();j++) r+=real[j];

    j=(int)frac.size()-1;
    for(;j>=0;j--)
    {
        if(frac[j]!='0') break;
    }
    for(i=0;i<=j;i++) f+=frac[i];
    frac=f;

    return true; // Valid real number
}
std::string Bigreal::getReal() const {
    return real;
}

std::string Bigreal::getFraction() const {
    return frac;
}

char Bigreal::getSign() const {
    return sign;
}
int Bigreal::getDecimal_point_pos() const{
    return decimal_point_pos;
}
void Bigreal::setNum(const std::string &n) {
    num = n;
}


std::ostream& operator<<(std::ostream& out, const Bigreal& bigreal) {
    if(!flag){
        out<<"INVALID NUM!\n";
        return out;
    }
    out << "sign: " << bigreal.getSign() << "\n";
    out << "Real Part: " << bigreal.getReal() << "\n";
    out << "Fraction Part: " << bigreal.getFraction() << "\n";
    out << "Decimal point Position: " << bigreal.getDecimal_point_pos() << "\n";
    return out;
}
bool Bigreal::operator< ( Bigreal &anotherReal)
{
    if(!flag){
        std::cout<<"INVALID NUM!\n";
        return 0;
    }
    if(sign=='-'&&anotherReal.sign=='-')
    {
        std::swap(*this,anotherReal);
    }
    if(sign==anotherReal.sign)
    {
        if(real==anotherReal.real)
        {
            if(frac==anotherReal.frac) return 0;
            if(frac.size()==anotherReal.frac.size())  return std::tie(frac) < std::tie(anotherReal.frac);
            else return frac.size()< anotherReal.frac.size();
        }
        else
        {
            if(real.size()==anotherReal.real.size())  return std::tie(real) < std::tie(real);
            else return real.size()< anotherReal.real.size();
        }
    }
    else
    {
        if(sign=='-') return 1;
        else return 0;
    }
    return 0;
}
bool Bigreal::operator> ( Bigreal &anotherReal)
{
    if(!flag){
        std::cout<<"INVALID NUM!\n";
        return 0;
    }
    if(sign=='-'&&anotherReal.sign=='-')
    {
        std::swap(*this,anotherReal);
    }
    if(sign==anotherReal.sign)
    {
        if(real==anotherReal.real)
        {
            if(frac==anotherReal.frac) return 0;
            if(frac.size()==anotherReal.frac.size())  return std::tie(frac) > std::tie(anotherReal.frac);
            else return frac.size()> anotherReal.frac.size();
        }
        else
        {
            if(real.size()==anotherReal.real.size())  return std::tie(real) > std::tie(anotherReal.real);
            else return real.size()> anotherReal.real.size();
        }
    }
    else
    {
        if(sign=='-') return 0;
        else return 1;
    }
    return 0;
}
bool Bigreal::operator== (const Bigreal &anotherReal) const
{
    // Check if the signs, real parts, and fractional parts are all equal
    return (sign == anotherReal.sign) && (real == anotherReal.real) && (frac == anotherReal.frac);
}



