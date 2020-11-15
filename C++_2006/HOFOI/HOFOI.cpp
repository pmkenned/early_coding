#include <iostream.h>

int main()
{
  double MI,MW,Mc,cW,cc,TF,T0,LF;

  cout << "Enter mass of ice (MI):";
  cin >> MI;
  cout << "Enter mass of water (MW):";
  cin >> MW;
  cout << "Enter mass of inner cup and stirrer (Mc):";
  cin >> Mc;
  cout << "Enter specific heat of water (cW):";
  cin >> cW;
  cout << "Enter specific heat of aluminum (cc):";
  cin >> cc;
  cout << "Enter final temperature (TF):";
  cin >> TF;
  cout << "Enter initial temperature (T0):";
  cin >> T0;

  LF = (MW*cW*(T0-TF)+Mc*cc*(T0-TF)-MI*cW*TF)/MI;

  cout << "(MW*cW*(T0-TF)+Mc*cc*(T0-TF)-MI*cW*TF)/MI = " << LF << endl;

  cout << "MI*LF+MI*cW*(TF-0) = MW*cW*(T0-TF)+Mc*cc*(T0-TF)" << endl;
  cout << "MI*LF+MI*cW*(TF-0) = " << MI*LF+MI*cW*(TF-0) << endl;
  cout << "MW*cW*(T0-TF)+Mc*cc*(T0-TF) = " << MW*cW*(T0-TF)+Mc*cc*(T0-TF) << endl;

  return 0;
}