#include <fstream>
#include <string.h>
using namespace std;
ifstream f("comp.in");
ofstream g("comp.out");
int n,i,nr,j;
char s[253];
int main()
{f>>n;
for(i=1;i<=n;i++)
{f.getline(s,250);

  for(j=0;j<strlen(s);j++)
  {if(s[j]=='<') nr++;}



}
    g<<nr;
    return 0;
}
