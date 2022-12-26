#include "racional.h"

#include <cmath>
#include <iostream>

// Implementação usando o algoritmo de Euclides.
// Precondição: y > 0.
int MaximoDivisorComum(int x, int y) {
	x = abs(x);	// No caso do numerador ser negativo.
	while (y > 0) {
		int aux = y;
		y = x % y;
		x = aux;
	}
	return x;
}

void Racional::Simplificar() {
		if (denominador_ < 0) { 
      denominador_ = -denominador_; 
      numerador_ = -numerador_; 
    }
		int mdc = MaximoDivisorComum(numerador_, denominador_);
		if (mdc > 1) { 
      numerador_ /= mdc; 
      denominador_ /= mdc; 
    }
}

Racional::Racional() : Racional(0, 1) {
}

Racional::Racional(int n) : Racional(n, 1) {
}

Racional::Racional(int n, int d) : numerador_(n), denominador_(d) {
  Simplificar();
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::operator-() const{
    return Racional(-numerador(), denominador());
}

Racional Racional::operator+(Racional k) const{
    int den = denominador() * k.denominador();
    int num = numerador() * k.denominador() + k.numerador() * denominador();
    return Racional(num,den);
}

Racional Racional::operator-(Racional k) const{
    int den = denominador() * k.denominador();
    int num = numerador() * k.denominador() - k.numerador() * denominador();
    return Racional(num,den);
}

Racional Racional::operator*(Racional k) const{
    int den = denominador() * k.denominador();
    int num = numerador() * k.numerador();
    return Racional(num,den);
}

Racional Racional::operator/(Racional k) const{
    int num = numerador() * k.denominador();
    int den = denominador() * k.numerador();
    if (den == 0){
        ExcecaoDivisaoPorZero x{};
        throw x;
    }
    else{
        return Racional(num,den);
    }
}

Racional::operator std::string() const{
    string num = std::to_string(numerador());
    string den = std::to_string(denominador());
    return (num + "/" + den);
}

Racional::operator float() const{
    float num = numerador();
    float den = denominador();
    return num/den;
}

istream& operator>>(istream& in, Racional& x) {
    int num;
    in >> num;
    int den;
    in >> den;
    x = Racional(num,den);
    return in;
}

ostream& operator<<(ostream& out, Racional x) {
    out << x.numerador() << "/" << x.denominador();
    return out;
}

