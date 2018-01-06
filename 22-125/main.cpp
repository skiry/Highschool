#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,s1,p=1,ok,k,q,d,x,o,r,c;
int main()
{f>>n;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    f>>a[i][j];
    for(i=1;i<=n;i++)
    {x=0;d=1;p=1;r=0;
        for(o=1;o<m;o++)
    p=p*10;
   for(j=1;j<=m;j++)
        {r=a[i][j]*p+r;
    p=p/10;}
    while(r)
    {c=r%2;
    r=r/2;
    x=x+d*c;
    d=d*10;

    }
g<<x;
    }

    return 0;
}
