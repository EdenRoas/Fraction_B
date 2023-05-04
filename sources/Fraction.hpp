#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cmath>
#include <numeric>
#include <limits>
#include <iomanip>


using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
    int numerator;
    int denominator;
    float number;
    float mul(const Fraction &fra1, const Fraction &fra2);
    //Fraction floatToFraction(float value);
        
    public:
        // constructor and destructor
        Fraction();
        Fraction(int num ,int den);
        Fraction(float number);
        void reduce();
        void simplify();
        //Fraction floatToFraction(float value);
        // Getters and setters 
        int getNumerator() const;
        int getDenominator() const;
        

        // Addition
        Fraction operator+(const Fraction &fra1) const;
        friend Fraction operator+(const Fraction &fra1, float scalar);
        friend Fraction operator+(float scalar, const Fraction &fra1);
        
        // Subtraction
        Fraction operator-(const Fraction &fra1) const;
        friend Fraction operator-(const Fraction &fra1, float scalar);
        friend Fraction operator-(float scalar, const Fraction &fra1);
        
        // Multiplication
        Fraction operator*(const Fraction &fra1) const;
        friend Fraction operator*(const Fraction &fra1, float scalar);
        friend Fraction operator*(float scalar, const Fraction &fra1);
        
        //divide
        Fraction operator/(const Fraction &fra1) const;
        friend Fraction operator/(const Fraction &fra1, float scalar);
        friend Fraction operator/(float scalar, const Fraction &fra1);
        

         // comparison operators (<, >, <=, >=, ==, !=)
        bool operator>(const Fraction &fra1) const;
        friend bool operator>(const Fraction &fra1, float scalar);
        friend bool operator>(float scalar, const Fraction &fra1);

        bool operator<(const Fraction &fra1) const;
        friend bool operator<(const Fraction &fra1, float scalar);
        friend bool operator<(float scalar, const Fraction &fra1);

        bool operator==(const Fraction &fra1) const;
        friend bool operator==(const Fraction &fra1, float scalar);
        friend bool operator==(float scalar, const Fraction &fra1);

        //friend bool operator!=(const Fraction &fra1, const Fraction &fra2);
        bool operator>=(const Fraction &fra1) const;
        friend bool operator>=(const Fraction &fra1, float scalar);
        friend bool operator>=(float scalar, const Fraction &fra1);

        bool operator<=(const Fraction &fra1) const;
        friend bool operator<=(const Fraction &fra1, float scalar);
        friend bool operator<=(float scalar, const Fraction &fra1);
        
        // Increment and decrement operators
        //postfix y = x++ ->return the original num and then increment
        Fraction &operator++(); 
        Fraction &operator--();
        //prefix ++(++x) -> first make increment and then return ths num
        Fraction operator++(int prefix); 
        Fraction operator--(int prefix); 
        
        
        // Input and output
        friend ostream &operator<<(ostream &ostream, const Fraction &fra1);
        friend istream &operator>>(istream &ostream, Fraction &fra1);

            
    };

};