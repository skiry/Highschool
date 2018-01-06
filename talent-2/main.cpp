#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a,n,b[100],x,y,i,ok,j,nr,nr1,h;
int main()
{f>>n;
for(i=1;i<=n;i++)
{f>>a;
x=a;
for(i=0;i<=9;i++) b[i]=0;
while(x)
{b[x%10]++;
x/=10;
}
nr=0;h=0;
for(j=0;j<=9;j++)
   {if(b[j]) h++;

    if(b[j]%2) nr++;
   }
if(nr<2) nr1++;
g<<h<<" "<<a<<endl;

}
g<<nr1;


    return 0;
}
