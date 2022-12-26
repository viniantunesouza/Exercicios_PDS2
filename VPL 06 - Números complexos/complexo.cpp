// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)
#define _USE_MATH_DEFINES

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
    mod_ = 0;
    arg_ = 0;
}

Complexo::Complexo(double a, double b) {
    mod_ = sqrt(pow(a,2) + pow(b,2));
    arg_ = atan2(b,a);
}

double Complexo::real() {
  return mod_*cos(arg_);
}

double Complexo::imag() {
  return mod_*sin(arg_);
}

bool Complexo::igual(Complexo x) {
  return (x.mod_ == this->mod_ && x.arg_ == this->arg_);
}

void Complexo::Atribuir(Complexo x) {
    *this = x;
}

double Complexo::modulo() {
  return mod_;
}

Complexo Complexo::conjugado() {
  Complexo c;
  c.mod_ = mod_;
  c.arg_ = -1*arg_;
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c;
  c.mod_ = mod_;
  c.arg_ = arg_+M_PI;
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  i.mod_ = 1/mod_;
  i.arg_ = -1*arg_;
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s;
  s.mod_ = sqrt(pow((this->real()+y.real()),2)+pow((this->imag()+y.imag()),2));
  s.arg_ = atan2((this->imag()+y.imag()),(this->real()+y.real()));
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  s.mod_ = sqrt(pow((this->real()-y.real()),2)+pow((this->imag()-y.imag()),2));;
  s.arg_ = atan2((this->imag()-y.imag()),(this->real()-y.real()));;
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.mod_ = mod_*y.mod_;
  p.arg_ = arg_+y.arg_;
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo d;
  d.mod_ = mod_/y.mod_;
  d.arg_ = arg_-y.arg_;
  return d;
}
