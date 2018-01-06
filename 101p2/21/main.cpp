#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i,a[100],j,aux;
int main()
{f>>n;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<n;i++)
if(a[i]%2==0)
for(j=i+1;j<=n;j++) if(a[i]>a[j]&&a[j]%2==0) {aux=a[i];a[i]=a[j];a[j]=aux;}
for(i=1;i<=n;i++) g<<a[i]<<" ";
    return 0;
}
