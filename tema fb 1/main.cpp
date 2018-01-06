#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
char a[100],*p,dp[]="cor",di[]="pto";
int main()
{
   f.get(a,100);
   g<<a;
   p=strstr(a,di);
   for(int i=0;i<=strlen(di);i++)
  // for(int j=0;j<=strlen(dp);j++)
   p[i]=di[i];
   g<<a;



    return 0;
}
