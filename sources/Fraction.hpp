#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cmath>
#include <numeric>


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
    
        
    public:
        // constructor and destructor
        Fraction();
        Fraction(int num ,int den);
        Fraction(float number);
        void reduce();
        static Fraction floatToFraction(float value);

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
        friend bool operator>(const Fraction &fra1, const Fraction &fra2);
        friend bool operator>(const Fraction &fra1, float scalar);
        friend bool operator>(float scalar, const Fraction &fra1);

        friend bool operator<(const Fraction &fra1, const Fraction &fra2);
        friend bool operator<(const Fraction &fra1, float scalar);
        friend bool operator<(float scalar, const Fraction &fra1);

        friend bool operator==(const Fraction &fra1, const Fraction &fra2);
        friend bool operator==(const Fraction &fra1, float scalar);
        friend bool operator==(float scalar, const Fraction &fra1);

        //friend bool operator!=(const Fraction &fra1, const Fraction &fra2);
        friend bool operator>=(const Fraction &fra1, const Fraction &fra2);
        friend bool operator>=(const Fraction &fra1, float scalar);
        friend bool operator>=(float scalar, const Fraction &fra1);

        friend bool operator<=(const Fraction &fra1, const Fraction &fra2);
        friend bool operator<=(const Fraction &fra1, float scalar);
        friend bool operator<=(float scalar, const Fraction &fra1);
        
        // Increment and decrement operators
        //postfix y = x++ ->return the original num and then increment
        friend Fraction operator++(const Fraction &fra1); 
        friend Fraction operator--(const Fraction &fra1);
        //prefix ++(++x) -> first make increment and then return ths num
        friend Fraction &operator++(const Fraction &fra1, int prefix); 
        friend Fraction &operator--(const Fraction &fra1, int prefix); 
        
        
        // Input and output
        friend ostream &operator<<(ostream &ostream, const Fraction &fra1);
        friend istream &operator>>(istream &ostream, Fraction &fra1);

          // Getters and setters 
            int getNumerator() const;
            int getDenominator() const;
            void setNumerator(int numerator);
            void setDenominator(int denominator);
    };

};