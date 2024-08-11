//314923822
//morberger444@gmail.com
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>

//this class represent a complex number
//the complex number contain two parts: the real and the imag
class Complex {
private:
    double real;//real part of the complex number
    double imag;//image part of the complex number

public:
    Complex(double real = 0.0, double imag = 0.0);
    //this function return the real of the complex number 
    double get_real() const;
    //this function return the imag of the complex number
    double get_imag() const;
    //operator for complex number
    bool operator>(const Complex& other) const;
    bool operator==(const Complex& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif 
