#ifndef CHEMISTRY_H
#define CHEMISTRY_H

double hofoi(double, double, double, double, double, double, double);

double hofoi(double MI, double MW, double Mc, double cW, double cc, double  TF, double T0)
{
  double LF = (MW*cW*(T0-TF)+Mc*cc*(T0-TF)-MI*cW*(TF-0))/MI;
  return LF;
}

#endif /* CHEMISTRY_H */