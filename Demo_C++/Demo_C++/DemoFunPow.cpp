#include<math.h>
#include<iostream>

int k = 0; // глобальная переменна

double stepTo3(double x)
{
  double res = pow(x,3);//x*x*x
  k++;
  return res;
}

void printTo3(double x1, double x2)
{k--;
  std::cout << "Смотри " << x1 << " это в кубе "<< x2 << " k=" << k << std::endl;
}

int main() {
int a = 5;
//int b = pow(a,3);

double bb = stepTo3(a);
double cc = stepTo3(bb);
//std::cout << "Смотри " << a << " это в кубе "<< bb << std::endl;
printTo3(a,bb);
printTo3(bb,cc);
  return 0;
}