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
    out << "sign: " << bigreal.getSign() << "\n";
    out << "Real Part: " << bigreal.getReal() << "\n";
    out << "Fraction Part: " << bigreal.getFraction() << "\n";
    out << "Decimal point Position: " << bigreal.getDecimal_point_pos() << "\n";
    return out;
}
bool Bigreal::operator< ( Bigreal &anotherReal)
{
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
std::string Bigreal::operator- (Bigreal& other) {
    // Calculate the maximum length of the two fraction parts
    int fracMaxLength = std::max(frac.length(), other.frac.length());

    // Add leading zeros to frac if needed
    if (frac.length() < fracMaxLength) {
        int numZerosToAdd = fracMaxLength - frac.length();
        frac = std::string(numZerosToAdd, '0') + frac;
    }

    // Add leading zeros to other.frac if needed
    if (other.frac.length() < fracMaxLength) {
        int numZerosToAdd = fracMaxLength - other.frac.length();
        other.frac = std::string(numZerosToAdd, '0') + other.frac;
    }

    std::string fracResult;
    int fracCarry = 0;

    // Subtracting each character in frac from the corresponding character in other
    for (int i = fracMaxLength - 1; i >= 0; --i) {
        int digit1 = frac[i] - '0';  // Change the frac char to decimal
        int digit2 = 0;
        if (i > 0) {
            digit2 = frac[i - 1] - '0';  // Adjust digit2 for carry
        }
        int digit3 = other.frac[i] - '0';
        digit1 += fracCarry;  // Add the carry from the previous iteration

        if (digit1 < digit3) {
            digit1 += 10;  // Borrow from the next digit
            fracCarry = -1;
        }
        else {
            fracCarry = 0;  // No borrow, carry is 0
        }

        int resultDigit = digit1 - digit3;  // Subtract
        fracResult = std::to_string(resultDigit) + fracResult;
    }
    int remainingCarry = fracCarry;

    // Calculate the maximum length of the two real parts
    int realMaxLength = std::max(real.length(), other.real.length());

    // Add leading zeros to 'real' if needed
    if (real.length() < realMaxLength) {
        int numZerosToAdd = realMaxLength - real.length();
        real = std::string(numZerosToAdd, '0') + real;
    }

    // Add leading zeros to 'other.real' if needed
    if (other.real.length() < realMaxLength) {
        int numZerosToAdd = realMaxLength - other.real.length();
        other.real = std::string(numZerosToAdd, '0') + other.real;
    }

    std::string realResult;
    int realCarry = 0;

    // Subtracting each character in frac from the corresponding character in other
    for (int i = realMaxLength - 1; i >= 0; --i) {
        int digit1 = real[i] - '0';  // Change real char to decimal
        int digit2 = 0;
        if (i > 0) {
            digit2 = real[i - 1] - '0';  // Adjust digit2 for carry
        }
        int digit3 = other.real[i] - '0';
        digit1 += realCarry;  // Add the carry from the previous iteration

        if (digit1 < digit3) {
            digit1 += 10;  // Borrow from the next digit
            realCarry = -1;
        }
        else {
            realCarry = 0;  // No borrow, carry is 0
        }
        if(fracCarry) digit1-=1,fracCarry=0;
        int resultDigit = digit1 - digit3;  // Subtract
        realResult = std::to_string(resultDigit) + realResult;
    }

    std::string res=realResult;
    res+=".";
    res+=fracResult;

    return res;
}
std::string Bigreal::operator+ (Bigreal& other) {
    // Calculate the maximum length of the two fraction parts
    int fracMaxLength = std::max(frac.length(), other.frac.length());

    // Add leading zeros to frac if needed
    if (frac.length() < fracMaxLength) {
        int numZerosToAdd = fracMaxLength - frac.length();
        frac += std::string(numZerosToAdd, '0');
    }

    // Add leading zeros to other.frac if needed
    if (other.frac.length() < fracMaxLength) {
        int numZerosToAdd = fracMaxLength - other.frac.length();
        other.frac += std::string(numZerosToAdd, '0');
    }

    std::string fracResult="";
    int fracCarry = 0;

    // Adding each character in frac to the corresponding character in other frac
    for (int i = fracMaxLength - 1; i >= 0; --i) {
        int digit1 = frac[i] - '0';
        int digit2 = other.frac[i] - '0';

        int sum = digit1 + digit2 + fracCarry;
        fracCarry = sum / 10;
        fracResult = std::to_string((int)(sum % 10)) + fracResult;
    }



    // Calculate the maximum length of the two real parts
    int realMaxLength = std::max(real.length(), other.real.length());

    // Add leading zeros to 'real' if needed
    if (real.length() < realMaxLength) {
        int numZerosToAdd = realMaxLength - real.length();
        real = std::string(numZerosToAdd, '0') + real;
    }

    // Add leading zeros to 'other.real' if needed
    if (other.real.length() < realMaxLength) {
        int numZerosToAdd = realMaxLength - other.real.length();
        other.real = std::string(numZerosToAdd, '0') + other.real;
    }

    std::string realResult;
    int realCarry = 0;

    // Adding each character in real to the corresponding character in other real
    for (int i = realMaxLength - 1; i >= 0; --i) {
        int digit1 = real[i] - '0';
        int digit2 = other.real[i] - '0';
        if(fracCarry) realCarry=1,fracCarry;
        int sum = digit1 + digit2 + realCarry;
        realCarry = sum / 10;
        realResult = std::to_string(sum % 10) + realResult;
    }

    if (realCarry > 0) {
        realResult = std::to_string(realCarry) + realResult;
    }

    std::string res="";
    res+=realResult;
    res+=".";
    res+=fracResult;


    return res;
}



