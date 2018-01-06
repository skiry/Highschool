#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i,m,cmax;
char a[100],pi,pf;
int main()
{f>>n;
for(i=1;i<=n;i++)
    f>>a[i];
if(n%2)
{m=n/2+1;
    for(i=1;i<=n/2;i++)

if(int(a[m-i])+int(a[m+i])>cmax)
{cmax=int(a[m-i])+int(a[m+i]); pi=a[m-i];pf=a[m+i];}

}

else if(n%2==0)
{for(i=1;i<=n/2;i++)
if(int(a[i])+int(a[n-i+1])>cmax)
{
    cmax=int(a[i])+int(a[n-i+1]);
    pi=a[i];
    pf=a[n-i+1];
}




}
g<<pi<<" "<<pf;
    return 0;
}
