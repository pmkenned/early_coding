#ifndef CONVERSIONS_H
#define CONVERSIONS_H

// Distance
double in2mm(double);
double in2cm(double);
double ft2cm(double);
double ft2m(double);
double yd2cm(double);
double yd2m(double);
double mi2km(double);

// Area
double in_sq2mm_sq(double);
double in_sq2cm_sq(double);
double ft_sq2cm_sq(double);
double ft_sq2m_sq(double);
double yd_sq2m_sq(double);
double acres2hectre(double);
double mi_sq2km_sq(double);

// Distance
double in2mm(double in){
  return in * 25.40;}

double in2cm(double in){
  return in * 2.540;}

double ft2cm(double ft){
  return ft * 30.480;}

double ft2m(double ft){
  return ft * 0.30480;}

double yd2cm(double yd){
  return yd * 91.44;}

double yd2m(double yd){
  return yd * 0.9144;}

double mi2km(double mi){
  return mi * 1.609;

//Area
double in_sq2mm_sq(double in_sq){
  return in_sq * 645.16;}

double in_sq2cm_sq(double in_sq){
  return in_sq * 6.4516;}

double ft_sq2cm_sq(double ft_sq){
  return ft_sq * 929.03;}

double ft_sq2m_sq(double ft_sq){
  return ft_sq * .0929;}

double yd_sq2m_sq(double yd_sq){
  return yd_sq * .836;}

double acres2hectre(double acres){
  return acres * .4047;}

double mi_sq2km_sq(double mi_sq){
  return mi_sq * 2.59;}

#endif /* CONVERSIONS_H */