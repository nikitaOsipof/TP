class Gamer
{
  public:
  char N;
  
  private:
  int Reg;
  
  public:
  int Brosok()
  {
    int k = 6;
    return k;
  }
  
  void InitReg(int r)
  {
    if(r>0)
    Reg = r;
    else
    Reg = 0;
  }
  
};

int main() {
  Gamer g1;
  Gamer g2;
  g1.N = 'A';
 // g1.Reg = 10;
 g1.InitReg(10); 
 
  int rez = g1.Brosok();

  g2.N = 'B';
//  g2.Reg = 5;
g2.InitReg(-5);
   rez = g2.Brosok();
  return 0;
}