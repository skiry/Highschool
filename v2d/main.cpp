#include <bits/stdc++.h>
using namespace std;
ifstream f("v2d.in");
ofstream g("v2d.out");
long n,t,q,s,rez,pl,pl2;
struct punct
{
    int bef,act;
}a[501][501];
int main()
{
    f>>n>>t>>q;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        f>>a[i][j].bef,s+=a[i][j].bef;
    for(int k=1;k<=t;k++)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            if(j==n-1) pl=i+1,pl2=0;
            else pl=i,pl2=j+1;
            for(int o=pl;o<n;o++)
                for(int l=pl2;l<n;l++)
            if(i!=o||j!=l)
            {pl2=0;int dist=abs(i-o)+abs(j-l);
                a[o][l].act=max(a[o][l].act,a[i][j].bef-dist);
                a[i][j].act=max(a[i][j].act,a[o][l].bef-dist);
            }
        }
        int s=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) a[i][j].bef=k+1+(a[i][j].bef+k*a[i][j].act)%q,s+=a[i][j].bef,a[i][j].act=0;
        if(k==t) g<<s%q<<endl;
    }

    return 0;
}
