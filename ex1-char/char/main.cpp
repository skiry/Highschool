#include <iostream>
#include <string>
using namespace std;

int main ()
{
  char cuv1[] = "Cum te cheama? ";
  char rasp1[50];
  cout << cuv1;
  cin >> rasp1;
  char cuv2[] = "Unde stai ?";
  char rasp2[100];
  cout << cuv2;
  cin >> rasp2;
  cout << "Salut, " << rasp1;
  cout << " din " << rasp2 << "!\n";
  return 0;
}
