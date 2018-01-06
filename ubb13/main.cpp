#include <bits/stdc++.h>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i,a[501],v[10001],cnt;
struct vectro
{
    int nmr,viz;
}y[501];
int suma(int nr)
{
    int numar=nr,suma=0;
    while(numar) suma+=numar%10,numar/=10;
    return suma;
}
int prim(int nr)
{
    for(int k=2;k<=nr/2;k++)
        if(nr%k==0) return 0;
    return 1;
}
void introduce(int nr)
{
    int o;
    if(!cnt) y[1].nmr=nr;
    else
    {
        for(o=1;o<=cnt&&y[o].nmr<nr;o++);
        if(o==cnt+1) y[cnt+1].nmr=nr;
        else for(int k=cnt;k>=o;k--) y[k+1].nmr=y[k].nmr;
        y[o].nmr=nr;
    }
}
int main()
{
    while(f>>i&&i)
    {
        a[++n]=i;
        if(!v[i]&&prim(suma(i))) introduce(i),++cnt;
        ++v[i];
    }
    for(i=1;i<=cnt;i++) g<<y[i].nmr<<", "<<v[y[i].nmr]<<endl;
    return 0;
}
