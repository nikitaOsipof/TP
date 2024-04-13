#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


class Kub
{
public :
   int  set()
    {
        srand(time(NULL));
        int k = rand()%6+1;
        return k;
    }
};


class Gamer
{
  public:
  string name;

  private:
  int Reg;

  public:
  int Brosok(Kub kb)
  {
   // srand(time(NULL));
   // int k = rand()%6+1;
    //int k = 6;
    int k = kb.set();

    return k;
  }

  void InitReg(int r)
  {
    if(r>0)
    Reg = r;
    else
    Reg = 0;
  }

  string Out()
  {
      string str = "Бросок " + this->name + " : ";
      return str;
  }

};

int main()
{
  Gamer g1;
  Kub kb1;
  g1.name = "Niko";
  // g1.Reg = 10;
  g1.InitReg(10);

  int rez = g1.Brosok(kb1);

  cout << g1.Out() << rez << endl;

  return 0;
}


