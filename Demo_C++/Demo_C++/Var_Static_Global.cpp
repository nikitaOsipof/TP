#include <iostream>


using namespace std;

void sum(int); 		// �p������ �������
double sum2(int);

int s = 0; 		// ���������� ����������



int main()
{
    int i, b, k;  		// ��������� ����������
    double s = 0;
    cout << "\n������� ����� ��������� ";
    cin >> k;

    for (i=0; i<k; i++)
    {  cout << "\n������� ����� ��������� ";
        cin >> b;
        sum(b);  		// ����� �������
        s = sum2(b);
    }
       cout << "\ns = " << ::s; // ������ � ���������� ����������
       cout << "\ns = " << s;

       return 0;
}

void sum(int c)
{
    s = s + c;
}

double sum2(int c)
{
  static double ss;
  ss = ss + c;
    return ss;
}
