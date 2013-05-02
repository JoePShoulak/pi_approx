#include <iostream> // std::cout, std::cin
#include <iomanip>  // std::setprecision
#include <math.h>   // pow

using std::cout;
using std::cin;
using std::setprecision;

double leibniz(int its) // 4/1 - 4/3 + 4/5 - 4/7 ... 
{
  double approx;
  approx = 0;
  for (int i=1; i<=its; i++)
  {
    double addend;
    int addOrSubtract;
    addend = 4.0/((2*i)-1);
    addOrSubtract = -(pow(-1, i));
    approx += addend*addOrSubtract;
  }

  return approx;
}

double nilakantha(int its)
{
  double approx;
  approx = 0;
  for (int i=1; i<=its; i++)
  {
    if (i == 1)
      approx += 3;
    else
    {
      int base;
      double addend;
      int addOrSubtract;
      base = 2*(i-1);
      addend = base * (base+1) * (base+2);
      addend = 4.0 / addend;
      addOrSubtract = pow(-1, i);
      approx += addend*addOrSubtract;
    }
  }
  return approx;
}

int main()
{
  int its;
  cout << "How many iterations would you like to do? ";
  cin >> its;
  
  cout << setprecision(10) << "Leibniz:\t"    << leibniz(its)    << "\n";
  cout << setprecision(10) << "Nilakantha:\t" << nilakantha(its) << "\n";

  return 0;
}
