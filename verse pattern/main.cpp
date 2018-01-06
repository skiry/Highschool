#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i,a[1000],ok;
char c[1000],voc[]="aeiouy";
int main()
{
   f>>n;
   for(i=1;i<=n;i++) f>>a[i];
   f.get();
   for(i=1;i<=n;i++)
   {
       f.getline(c,1000);
       int nr=0;
       for(int j=0;j<strlen(c);j++)
        if(strchr(voc,c[j]))
           nr++;
                if(nr!=a[i]) ok=1;
   }
   if(!ok) g<<"YES";
   else g<<"NO";
    return 0;
}
