#include <bits/stdc++.h>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i,rez[200001];
int maxim(int k)
{
    int maxx=0;
    for(int i=1;i<=k;i++)
        if(rez[i]>=maxx) maxx=rez[i];
    return maxx;
}
void afis()
{
    for(int i=1;i<=maxim(n);i++)
    {
        g<<"{";
        for(int j=1;j<=n;j++)
            if(rez[j]==i) g<<j<<" ";
        g<<"}";
    }
    g<<endl;
}
void partitions(int poz)
{
    for(int i=1;i<=maxim(poz-1)+1;i++)
    {
        rez[poz]=i;
        if(poz==n) afis();
        else partitions(poz+1);
    }
}
int main()
{
    f>>n;
    partitions(1);
    return 0;
}
