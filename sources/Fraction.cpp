#include "Fraction.hpp"
using namespace std;
using namespace ariel;

// constructor and destructor
Fraction::Fraction()
{
    this->denominator = 1;
    this->numerator = 1;
}
int gcd_F(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd_F(b, a % b);
}


     Fraction::Fraction (float value) // -> casting to fraction
     {
        this->numerator = static_cast<int>(value*1000); 
        this-> denominator = 1000;
        reduce();
    }

Fraction::Fraction(int num, int den) : numerator(num), denominator(den)
{
    if (den == 0)
    {
        __throw_invalid_argument("The denominator cannot be 0 or negative!!!");
    }
    if (num == 0)
    {
        this->numerator = 0;
        this->denominator = 1;
    }
    this->reduce();
    if (this->denominator < 0)
    {
        this->numerator *= -1;
        this->denominator *= -1;
    }
    
}

void Fraction::reduce()
{
    int tempNumerator = abs(this->numerator); // Find greatest common divisor using Euclid's algorithm
    int tempDenominator = abs(this->denominator);
    while (tempDenominator != 0)
    {
        int temp = tempDenominator;
        tempDenominator = tempNumerator % tempDenominator;
        tempNumerator = temp;
    }
    int gcd = tempNumerator;
    // Reduce the fraction by dividing both numerator and denominator by gcd
    numerator /= gcd;
    denominator /= gcd;
}
int Fraction::getNumerator() const
{
    return this->numerator;
}
int Fraction::getDenominator() const
{
    return this->denominator;
}

// Addition

Fraction Fraction::operator+(const Fraction &fra1) const // Multiply by crossing
{
    int num = this->numerator * fra1.denominator + fra1.numerator * this->denominator;
    int den = this->denominator * fra1.denominator;
    int max_int = numeric_limits<int>::max();
    int min_int = numeric_limits<int>::min();
    if ((this->numerator == max_int && this->denominator != max_int)
            || (this->numerator <= min_int + 100 && fra1.numerator <= min_int + 100)
            || (fra1.numerator == max_int && fra1.denominator != max_int)){
               __throw_overflow_error("ADD overflow!!");
            }
    return Fraction(num, den);
}
Fraction ariel::operator+(const Fraction &fra1, float scalar)
{
    return fra1 + Fraction(scalar);
}

Fraction ariel::operator+(float scalar, const Fraction &fra1)
{
    return Fraction(scalar) + fra1;
}
// Subtraction
Fraction Fraction::operator-(const Fraction &fra1) const
{
    int num = this->numerator * fra1.denominator - fra1.numerator * this->denominator;
    int den = this->denominator * fra1.denominator;
    int max_int = numeric_limits<int>::max();
    int min_int = numeric_limits<int>::min();
    if ((this->numerator <= min_int + 100 && fra1.numerator <= min_int + 100)
            || (this->numerator >= max_int - 100 && fra1.numerator <= min_int + 100))
            {
                __throw_overflow_error("Sub Overflow!");
            }
    return Fraction(num, den);
}
Fraction ariel::operator-(const Fraction &fra1, float scalar)
{
    return fra1 - Fraction(scalar);
}
Fraction ariel::operator-(float scalar, const Fraction &fra1)
{
    return Fraction(scalar) - fra1;
}

// Multiplication
Fraction Fraction::operator*(const Fraction &fra1) const // ans = fra1 * fra2
{
    int num = fra1.numerator * this->numerator;
    int den = fra1.denominator * this->denominator;
    int max_int = numeric_limits<int>::max();
    if  ((this->numerator == max_int && this->denominator != max_int)
            || (this->denominator == max_int && this->numerator != max_int)
            || (fra1.numerator == max_int && fra1.denominator != max_int)
            || (fra1.denominator == max_int && fra1.denominator != max_int))
            {
                __throw_overflow_error ("Mul Overflow!!");
            }

    return Fraction(num, den);
}
Fraction ariel::operator*(const Fraction &fra1, float scalar)
{
    
    return Fraction(scalar) * fra1;
}
Fraction ariel::operator*(float scalar, const Fraction &fra1)
{
    return Fraction(scalar) * fra1;
}
// Divide
Fraction Fraction::operator/(const Fraction &fra1) const // ans = fra1 / fra2
{   
    if(fra1.numerator == 0){
        __throw_runtime_error("Cannot divide by zero!");
    }
    int num = this->numerator * fra1.denominator;
    int den = this->denominator * fra1.numerator;
    int max_int = numeric_limits<int>::max();
    if ((this->denominator == max_int && this->numerator < max_int - 100)
            || (this->numerator == max_int && this->denominator != max_int)){
                __throw_overflow_error("Divide overflow!!");
            }

    return Fraction(num, den);
}
Fraction ariel::operator/(const Fraction &fra1, float scalar)
{
    return fra1 / Fraction(scalar);
}
Fraction ariel::operator/(float scalar, const Fraction &fra1)
{
    return Fraction(scalar) / fra1;
}
// comparison operators (<, >, <=, >=, ==, !=)
bool Fraction::operator>(const Fraction &fra1) const
{
    float this_value = static_cast<float>(numerator) / denominator;
    float other_value = static_cast<float>(fra1.numerator) / fra1.denominator;
    return this_value > other_value;
}
bool ariel::operator>(const Fraction &fra1, float scalar)
{
    return (fra1 > Fraction(scalar));
}
bool ariel::operator>(float scalar, const Fraction &fra1)
{
    return (Fraction(scalar) > fra1);
}

bool Fraction::operator<(const Fraction &fra1) const
{
    float this_value = static_cast<float>(numerator) / denominator;
    float other_value = static_cast<float>(fra1.numerator) / fra1.denominator;
    return this_value < other_value;
}
bool ariel::operator<(const Fraction &fra1, const float scalar)
{
    return (fra1 < Fraction(scalar));
}
bool ariel::operator<(float scalar, const Fraction &fra1)
{
    return (Fraction(scalar) < fra1);
}

bool Fraction::operator==(const Fraction &fra1) const
{
    return (this->numerator == fra1.numerator) && (this->denominator == fra1.denominator);
}
bool ariel::operator==(const Fraction &fra1, const float scalar)
{
    return (fra1 == Fraction(scalar));
}
bool ariel::operator==(float scalar, const Fraction &fra1)
{
    return (Fraction(scalar) == fra1);
}

bool Fraction::operator>=(const Fraction &fra1) const
{
    Fraction me = Fraction(numerator, denominator);
    return ((me == fra1) || (me > fra1));
}
bool ariel::operator>=(const Fraction &fra1, float scalar)
{
    return (fra1 >= Fraction(scalar));
}
bool ariel::operator>=(float scalar, const Fraction &fra1)
{
    return (Fraction(scalar) >= fra1);
}

bool Fraction::operator<=(const Fraction &fra1) const
{
    Fraction me = Fraction(numerator, denominator);
    return ((me == fra1) || (me < fra1));
}
bool ariel::operator<=(const Fraction &fra1, float scalar)
{
    return (fra1 <= Fraction(scalar));
}
bool ariel::operator<=(float scalar, const Fraction &fra1)
{
    return (Fraction(scalar) <= fra1);
}
// Increment and decrement operators
// prefix ++(++x) -> first make increment and then return ths num
 Fraction &Fraction::operator++() // ++fra1
{   
    this->numerator += this->denominator;
    return *this;
    
}

Fraction &Fraction::operator--() // --fra1
{
    this->numerator -= this->denominator;
    return *this;
    
}
//postfix y = x++ ->return the original num and then increment
Fraction Fraction::operator++(int prefix)
{
    Fraction temp = Fraction(this->numerator, this->denominator);
    this->numerator += this->denominator;
    return temp;
   
}
Fraction Fraction::operator--(int prefix)
{   
    Fraction temp = Fraction(this->numerator, this->denominator);
    this->numerator -= this->denominator;
    return temp;
}
// Input & Output
ostream &ariel::operator<<(ostream &ostream, const Fraction &fraction)
{
    ostream << fraction.numerator << "/" << fraction.denominator  ;
    return ostream;
}

istream &ariel::operator>>(istream &istream, Fraction &fra1)
{
    int num, den;
    istream >> num >> den;
    if (istream.fail()) // If input is not 2 integers -> its invalid input
    {
        throw runtime_error("Invalid input: expected two integers separated by a space");
    }
    // If there is wrong initialization with denominator 0 ->Invalid
    if (den == 0)
    {
        throw runtime_error("Invalid input: Denominator can not be 0!");
    }
    // For test case " Input and output operators tests"
    if (den < 0)
    {
        num = num * (-1);
        den = den * (-1);
    }
    if (num == 0)
    {
        num = 0;
        den = 1;
    }
    fra1.numerator = num;
    fra1.denominator = den;
    return istream;
}


