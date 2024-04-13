#include <iostream>
int MySum(int, int); // прототип функции

void Out(int s) // как процедура
{
     std::cout << "\nHello, world! " << s;
}
    

int main()
{
    int a = 10;
    int b = 80;
    int s = MySum(b,a);
    Out(s);
    int k = 5;
    int m = 8;
    int f = MySum(k,m);
    Out(f);
   
}

int MySum(int x, int y)
{
    int res = x - y;
    return res;
}
