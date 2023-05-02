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

Fraction::Fraction(float value)
{
    float decimal = std::abs(value);                 // Take the absolute value of the input
    int sign = (value < 0) ? -1 : 1;                 // Determine the sign of the input
    int whole = static_cast<int>(decimal);           // Find the integer part of the input
    decimal -= whole;                                // Remove the integer part from the decimal
    int precision = 1000000;                         // Set a precision value for the decimal (here, 6 decimal places)
    int num = static_cast<int>(decimal * precision); // Convert the decimal to a numerator
    int denom = precision;                           // The denominator is the precision value
    int gcd = gcd_F(num, denom);                     // Reduce the fraction using the greatest common divisor
    num /= gcd;
    denom /= gcd;
    numerator = sign * (whole * denom + num); // Combine the whole number and fraction parts
    denominator = denom;
}

Fraction::Fraction(int num, int den)
{
    if (den <= 0)
    {
        __throw_runtime_error("The denominator cannot be 0!!!");
    }
    if (num == 0)
    {
        this->numerator = 0;
        this->denominator = 0;
    }
    else
    {
        this->numerator = num;
        this->denominator = den;
        this->reduce();
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
    return Fraction(num, den);
}
Fraction ariel::operator+(const Fraction &fra1, float scalar)
{
    Fraction result = fra1 + Fraction(scalar);
    return result;
}

Fraction ariel::operator+(float scalar, const Fraction &fra1)
{
    Fraction result = Fraction(scalar) + fra1;
    return result;
}
// Subtraction
Fraction Fraction::operator-(const Fraction &fra1) const
{
    int num = this->numerator * fra1.denominator - fra1.numerator * this->denominator;
    int den = this->denominator * fra1.denominator;
    return Fraction(num, den);
}
Fraction ariel::operator-(const Fraction &fra1, float scalar)
{
    Fraction result = fra1 - Fraction(scalar);
    return result;
}
Fraction ariel::operator-(float scalar, const Fraction &fra1)
{
    Fraction result = Fraction(scalar) - fra1;
    return result;
}

// Multiplication
Fraction Fraction::operator*(const Fraction &fra1) const // ans = fra1 * fra2
{
    int num = fra1.numerator * this->numerator;
    int den = fra1.denominator * this->denominator;
    return Fraction(num, den);
}
Fraction ariel::operator*(const Fraction &fra1, float scalar)
{
    Fraction result = Fraction(scalar) * fra1;
    return result;
}
Fraction ariel::operator*(float scalar, const Fraction &fra1)
{
    Fraction result = Fraction(scalar) * fra1;
    return result;
}
// Divide
Fraction Fraction::operator/(const Fraction &fra1) const // ans = fra1 / fra2
{
    int num = this->numerator * fra1.denominator;
    int den = this->denominator * fra1.numerator;
    return Fraction(num, den);
}
Fraction ariel::operator/(const Fraction &fra1, float scalar)
{
    Fraction result = fra1 / Fraction(scalar);
    return result;
}
Fraction ariel::operator/(float scalar, const Fraction &fra1)
{
    Fraction result = Fraction(scalar) / fra1;
    return result;
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
// postfix y = x++ ->return the original num and then increment
Fraction Fraction::operator++() // fra1++
{
    Fraction temp = Fraction(this->numerator, this->denominator);
    this->numerator += this->denominator;
    return temp;
}

Fraction Fraction::operator--() // fra1--
{
    Fraction temp = Fraction(this->numerator, this->denominator);
    this->numerator -= this->denominator;
    return temp;
}

// prefix ++(++x) -> first make increment and then return ths num
Fraction &Fraction::operator++(int prefix)
{
    this->numerator += this->denominator;
    return *this;
}
Fraction &Fraction::operator--(int prefix)
{
    this->numerator -= this->denominator;
    return *this;
}
// Input & Output
ostream &ariel::operator<<(ostream &ostream, const Fraction &fraction)
{
    ostream << " "<< fraction.numerator << " / " << fraction.denominator << " ";
    return ostream;
}

istream &ariel::operator>>(istream &istream, Fraction &fra1)
{
    int num, den;
    istream >> num >> den;
    if (istream.fail()) // If input is not 2 integers
    {
        throw runtime_error("Invalid input: expected two integers separated by a space");
    }
    // If there is wrong initialization with denominator 0
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
    fra1.numerator = num;
    fra1.denominator = den;
    return istream;
}

