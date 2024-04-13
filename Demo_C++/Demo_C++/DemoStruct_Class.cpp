#include<iostream>
#include<cstring> 

struct Person
{
  char firstname[10];
  int age;

  
  void print()
  {
    std::cout << firstname << age;
    }
};

int main() {

int a = 4;
Person p;
p.age = 99;
strcpy(p.firstname, "Person");
p.print();
  return 0;
}