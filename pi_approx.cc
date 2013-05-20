#include <math.h>   // pow
#include <stdio.h>  // printf
#include <stdlib.h> // exit functions

// user-defined methods
// crash
void Crash() {
  printf("%s\n", "Usage: pi_approx [iterations]");
  exit(EXIT_FAILURE);
}
// leibnix method
double leibniz(int its) {
  double approx = 0;
  for (int i=1; i<=its; i++) {
    double addend;
    addend = 4.0/((2*i)-1);
    int addOrSubtract = -(pow(-1, i));
    approx += addend*addOrSubtract;
  }
  return approx;
}
// nilakantha method
double nilakantha(int its) {
  double approx = 0;
  for (int i=1; i<=its; i++) {
    if (i == 1) {
      approx += 3;
    } else {
      int base = 2*(i-1);
      double addend = base * (base+1) * (base+2);
      addend = 4.0 / addend;
      int addOrSubtract = pow(-1, i);
      approx += addend*addOrSubtract;
    }
  }
  return approx;
}
int main(int argc, char* argv[])
{
  if (argc!=2) {
    Crash();
  } else {
  int its = atoi(argv[1]);
  printf("Leibniz:\t%.20f\n", leibniz(its));
  printf("Nilakantha:\t%.20f\n", nilakantha(its));
  return 0;
  }
}
