#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream f("lant.in");
ofstream g("lant.out");
int ks,i,j,k,l,nrc,n,m,d[31][31],a[151][151],nr[151];
char c[151][31],s[1001],*p;
void calculeaza(int n)
{
    if(!a[n][0]) {nr[n]=1;return;}
    long int suma=0;
    for(int i=1;i<=a[n][0];i++)
    {
        if(!nr[a[n][i]]) calculeaza(a[n][i]);
        suma+=nr[a[n][i]];
    }
    nr[n]=suma;
}
int main()
{
    f>>ks;
    f.get();
    do
    {
        f.getline(s,1001);
        p=strtok(s," ,:;.!?-");
        while(p)
        {
            for(i=0;i<nrc&&strcmp(p,c[i]);i++);
            if(i==nrc) strcpy(c[nrc++],p);
            p=strtok(NULL," ,:;.!?-");
        }
    }while(f);
    for(i=0;i<nrc;i++)
        for(j=i+1;j<nrc;j++)
    {
        n=strlen(c[i]);
        m=strlen(c[j]);
        for(k=0;k<=m;k++) d[n][k]=m-k;
        for(k=0;k<=n;k++) d[k][m]=n-k;
        for(k=n-1;k>=0;k--)
            for(l=m-1;l>=0;l--)
        {
            d[k][l]=1+min(d[k+1][l],d[k][l+1]);
            if(c[i][k]==c[j][l]&&d[k+1][l+1]<d[k][l])
                d[k][l]=d[k+1][l+1];
        }
        if(d[0][0]<=ks) a[i][++a[i][0]]=j;
    }
    calculeaza(0);
    g<<nr[0];
    return 0;
}
