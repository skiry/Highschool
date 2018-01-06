#include <fstream>
// suma celor impare si produsul celor pare de pe coloanele de pe pozitii impare
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,j,i,p=1,s;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) f>>a[i][j];
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)     if(a[i][j]%2) s=s+a[i][j];
      for(j=1;j<=m;j++)
        {i=1; if(j%2) while(i<=n) if(a[i][j]%2==0) {p=p*a[i][j];i++;}
        else i++;}
        g<<s<<" "<<p;


    return 0;
}
