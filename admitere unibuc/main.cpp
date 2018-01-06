#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,n,a[100][100],c[100],nr,j,m,k,gr[100],ok;
int main()
{
    f>>n>>m>>k;
    for(int l=1;l<=m;l++) f>>i>>j,a[i][j]=a[j][i]=1,gr[i]++,gr[j]++;
    j=1;
    for(i=1;i<=n;i++) if(gr[i]>=k) c[j++]=i;
    for(i=1;i<=n;i++) g<<gr[i]<<" ";
    for(i=1;i<j;i++)
    {
        nr=0;
         for(int l=1;l<j;l++)
            if(a[c[i]][c[l]]) nr++;

        if(nr<k) c[i]=0;
        else ok=1;
    }
    g<<endl;
    if(!ok) g<<"NU";
    else
    for(i=1;i<j;i++)
        if(c[i]) g<<c[i]<<" ";
    return 0;
}
