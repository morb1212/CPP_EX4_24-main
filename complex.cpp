#include "complex.hpp"
#include <stdexcept>
#include <iomanip> 

//this class represent a complex number
//the complex number contain two parts: the real and the imag
Complex::Complex(double re, double im) : real(re), imag(im) {}

//this function return the real of the complex number 
double Complex::get_real() const {
    return real;
}

//this function return the imag of the complex number
double Complex::get_imag() const {
    return imag;
}
//operator >  for complex number
bool Complex::operator>(const Complex& other) const {
//steps:
//check if the real of the class is > of the real of the other
//if yes return true 
//if equal check if the image of the class is  > of the image of the other
//if yes return true 
//else return false
    if(real > other.get_real()|| (real == other.get_real() && imag > other.get_imag())){
        return true;
    }
    else {
        return false;
    }
}
//operaor == for complex number
bool Complex::operator==(const Complex& other) const {
//check if their real and the image parts are equals
//if yes return true
//else return false
    if(real == other.real && imag == other.imag){
        return true;
    }
    else{
        return false;
    }
}

//operaotr << for the complex number
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << std::fixed << std::setprecision(2); 
    os << "(" << c.real << " + " << c.imag << "i)";
    return os;
}
