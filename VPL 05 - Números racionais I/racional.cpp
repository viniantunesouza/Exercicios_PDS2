#include "racional.h"

#include <cmath>
#include <iostream>

int mdc(int num1, int num2)
{
    if(num1%num2 == 0)
        return num2;
    else
        return mdc(num2, num1%num2);
}

void Racional::Normalizar() {
  int mdc_ = mdc(numerador_,denominador_);
  numerador_ = numerador_/mdc_;
  denominador_ = denominador_/mdc_;
  if (denominador_ < 0)
    denominador_ = denominador_ * (-1);
    numerador_ = numerador_ * (-1);
}

Racional::Racional() {
  numerador_ = 0;
  denominador_ = 1;
}

Racional::Racional(int n)  {
  numerador_ = n;
  denominador_ = 1;
}

Racional::Racional(int n, int d) {
  numerador_ = n;
  denominador_ = d;
}

int Racional::numerador() const {
  return this->numerador_;
}

int Racional::denominador() const {
  return this->denominador_;
}

Racional Racional::simetrico() const {
  Racional r = Racional(numerador_ * (-1), denominador_);
  r.Normalizar();
  return r;
}

Racional Racional::somar(Racional k) const {
  Racional r1 = Racional(numerador_,denominador_);
  Racional r2 = Racional(k.numerador_,k.denominador_);
  int novoDenominador;
  novoDenominador = r1.denominador_ * r2.denominador_;
  r1.numerador_ = novoDenominador/r1.denominador_*r1.numerador_;
  r2.numerador_ = novoDenominador/r2.denominador_*r2.numerador_; 
  r1.numerador_ = r1.numerador_ + r2.numerador_;
  r1.denominador_ = novoDenominador;
  r1.Normalizar();
  return r1;
}

Racional Racional::subtrair(Racional k) const {
  Racional r1 = Racional(numerador_,denominador_);
  Racional r2 = Racional(k.numerador_,k.denominador_);
  int novoDenominador;
  novoDenominador = r1.denominador_ * r2.denominador_;
  r1.numerador_ = novoDenominador/r1.denominador_*r1.numerador_;
  r2.numerador_ = novoDenominador/r2.denominador_*r2.numerador_; 
  r1.numerador_ = r1.numerador_ - r2.numerador_;
  r1.denominador_ = novoDenominador;
  r1.Normalizar();
  return r1;
}

Racional Racional::multiplicar(Racional k) const {
  Racional r1 = Racional(numerador_,denominador_);
  Racional r2 = Racional(k.numerador_,k.denominador_);
  r1.numerador_ = r1.numerador_ * r2.numerador_;
  r1.denominador_ = r1.denominador_ * r2.denominador_;
  r1.Normalizar();
  return r1;
}

Racional Racional::dividir(Racional k) const {
  Racional r1 = Racional(numerador_,denominador_);
  Racional r2 = Racional(k.numerador_,k.denominador_);
  r1.numerador_ = r1.numerador_ * r2.denominador_;
  r1.denominador_ = r1.denominador_ * r2.numerador_;
  r1.Normalizar();
  return r1;
}