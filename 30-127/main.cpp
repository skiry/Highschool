#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,q,k,nr,p;
int main()
{f>>n;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    f>>a[i][j];

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        if(i==j)
    {p=j;do{ swap (a[i][p],a[i][p+1]);p=p+1;}while(p<n);}

        for(i=1;i<=n;i++)
        {for(j=1;j<n;j++)
        g<<a[i][j]<<" ";
    g<<'\n';}


    return 0;
}
