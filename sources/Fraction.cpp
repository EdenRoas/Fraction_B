#include "Fraction.hpp"
using namespace std;
namespace ariel
{
    ariel::Fraction ariel::Fraction::floatToFraction(float value)
    {
        const float epsilon = 0.000001; // a small number for comparing floats
        Fraction result;
        int sign = value > 0 ? 1 : -1;
        value = abs(value);
        result.numerator = round(value);
        float fraction = value - result.numerator;
        result.denominator = 1;
        while (abs(fraction - round(fraction)) > epsilon)
        {
            result.denominator *= 10;
            fraction *= 10;
        }
        int gcd_val = gcd(result.numerator, result.denominator);
        result.numerator /= gcd_val;
        result.denominator /= gcd_val;
        result.numerator *= sign;
        return result;
    }
    // constructor and destructor
    Fraction::Fraction()
    {
        this->denominator = 1;
        this->numerator = 1;
    }
    Fraction::Fraction(float num)
    {
        this->number = num;
    }
    Fraction::Fraction(int num, int den)
    {
        if (den <= 0)
        {
            __throw_invalid_argument("The denominator cannot be 0!!!");
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
    Fraction fra_ans(3, 5);

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

    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }

    // Addition
    
    Fraction Fraction::operator+(const Fraction &fra1) const // Multiply by crossing
    {
        int num = this->numerator * fra1.denominator + fra1.numerator * this->denominator;
        int den = this->denominator * fra1.denominator;
        return Fraction(num, den);
    }
    Fraction Fraction::operator+(const Fraction &fra1, float scalar)
    {   
        Fraction flo_convert = floatTofraction(scalar);
        Fraction result = flo_convert + fra1;
        return result;
    }

    Fraction operator+(float scalar, const Fraction &fra1)
    {
        return fra_ans;
    }
    // Subtraction
    Fraction Fraction::operator-(const Fraction &fra1) const
    {
        int num = this->numerator * fra1.denominator - fra1.numerator * this->denominator;
        int den = this->denominator * fra1.denominator;
        return Fraction(num, den);
    }
    Fraction operator-(const Fraction &fra1, float scalar)
    {
        return fra_ans;
    }
    Fraction operator-(float scalar, const Fraction &fra1)
    {
        return fra_ans;
    }

    // Multiplication
    Fraction Fraction::operator*(const Fraction &fra1) const // ans = fra1 * fra2
    {
        int num = fra1.numerator * this->numerator;
        int den = fra1.denominator * this->denominator;
        return Fraction(num, den);
    }
    Fraction operator*(const Fraction &fra1, float scalar)
    {
        return fra_ans;
    }
    Fraction operator*(float scalar, const Fraction &fra1)
    {
        return fra_ans;
    }
    // Divide
    Fraction Fraction::operator/(const Fraction &fra1) const // ans = fra1 / fra2
    {
        int num = this->numerator * fra1.denominator;
        int den = this->denominator * fra1.numerator;
        return Fraction(num, den);
    }
    ariel::Fraction ariel::operator/(const Fraction &fra1, float scalar)
    {
        return fra_ans;
    }
    ariel::Fraction ariel::operator/(float scalar, const Fraction &fra1)
    {
        return fra_ans;
    }
    // comparison operators (<, >, <=, >=, ==, !=)
    bool operator>(const Fraction &fra1, const Fraction &fra2)
    {
        if (fra1 - fra2 > 0)
            return true;
        return false;
    }
    bool ariel::Fraction::operator>(const Fraction &fra1, float scalar)
    {
        Fraction ans_fra;
        if (fra1 - floatTofraction(scalar) = ans_fra)
            return true;
        return false;
    }
    bool operator>(float scalar, const Fraction &fra1)
    {
        if (floatTofraction(scalar) - fra1 > 0)
            return true;
        return false;
    }

    bool operator<(const Fraction &fra1, const Fraction &fra2)
    {
        if (fra1 - fra2 < 0)
            return true;
        return false;
    }
    bool operator<(const Fraction &fra1, const float scalar)
    {
        if (fra1 - floatTofraction(scalar) < 0)
            return true;
        return false;
    }
    bool operator<(float scalar, const Fraction &fra1)
    {
        if (floatTofraction(scalar) - fra1 < 0)
            return true;
        return false;
    }

    bool ariel::Fraction::operator==(const ariel::Fraction &fra1)
    {
        if (fra2 == fra1)
            return true;
        return false;
    }
    bool operator==(const Fraction &fra1, const float scalar)
    {
        if (fra1 == floatTofraction(scalar))
            return true;
        return false;
    }
    bool operator==(float scalar, const Fraction &fra1)
    {
        if (floatTofraction(scalar) == fra1)
            return true;
        return false;
    }

    bool operator>=(const Fraction &fra1, const Fraction &fra2)
    {
        if (fra1 - fra2 >= 0)
            return true;
        return false;
    }
    bool operator>=(const Fraction &fra1, float scalar)
    {
        if (fra1 - floatTofraction(scalar) >= 0)
            return true;
        return false;
    }
    bool operator>=(float scalar, const Fraction &fra1)
    {
        if (floatTofraction(scalar) - fra1 >= 0)
            return true;
        return false;
    }

    bool operator<=(const Fraction &fra1, const Fraction &fra2)
    {
        if (fra1 - fra2 <= 0)
            return true;
        return false;
    }
    bool operator<=(Fraction &fra1, const float scalar)
    {
        if (fra1 - floatTofraction(scalar) <= 0)
            return true;
        return false;
    }
    bool operator<=(float scalar, const Fraction &fra1)
    {
        if (floatTofraction(scalar) - fra1 <= 0)
            return true;
        return false;
    }
    // Increment and decrement operators
    // postfix y = x++ ->return the original num and then increment
    Fraction operator++(const Fraction &fra1) // fra1++
    {
        return fra_ans;
    }

    Fraction operator--(const Fraction &fra1) // fra1--
    {
        return fra_ans;
    }

    // prefix ++(++x) -> first make increment and then return ths num
    Fraction &operator++(const Fraction &fra1, int prefix)
    {
        return fra_ans;
    }
    Fraction &operator--(const Fraction &fra1, int prefix)
    {
        return fra_ans;
    }
    // Input & Output
    ostream &ariel::operator<<(ostream &ostream, const Fraction &fraction)
    {
        ostream << fraction.numerator << " / " << fraction.denominator;
        return ostream;
    }

    istream &operator>>(istream &istream, Fraction &fra1)
    {
        return istream;
    }

}
