#include <bits/stdc++.h>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,a[51][51],i,j,v[2501],k,d,viz[20001];
int prim(int nr)
{
    for(int k=2;k<=nr/2;k++)
        if(nr%k==0) return 0;
    return 1;
}
int verifica(int nr)
{
    int numar=nr;
    while(numar)
        if(!prim(numar)) return 0;
    else numar/=10;
    return 1;
}
void introduce(int nr)
{
    int o;
    if(!d) v[1]=nr;
    else
    {
        for(o=1;o<=d&&v[o]>nr;o++);
    if(o==d+1) v[d+1]=nr;
    else
    {
        for(int k=d;k>=1;k--) v[k+1]=v[k];
        v[1]=nr;
    }
    }
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        f>>a[i][j];
        if(!viz[a[i][j]]&&verifica(a[i][j])&&((i+j<n+1&&i>j)||(i+j>n+1&&i<j))) introduce(a[i][j]),++d;
        ++viz[a[i][j]];
    }
    for(i=1;i<=d;i++) g<<v[i]<<" ";
    if(!d) g<<"Șirul este vid";
    return 0;
}
