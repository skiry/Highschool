#include <bits/stdc++.h>

using namespace std;
ifstream f("urat.in");
ofstream g("urat.out");
long long n,a[500005],s;
int main()
{
    f>>n;
    int stanga=n/2,dreapta=n/2,nr=1,maxim=n+1,minim=1;
    a[n/2]=1;
    while(nr<=n)
    {
        if(!((nr/2)%2))
        {
            a[++dreapta]=--maxim;
            a[--stanga]=--maxim;
            s+=abs(a[dreapta-1]-a[dreapta])+abs(a[stanga+1]-a[stanga]);
        }
        else
        {
            a[++dreapta]=++minim;
            a[--stanga]=++minim;
            s+=abs(a[dreapta-1]-a[dreapta])+abs(a[stanga+1]-a[stanga]);
        }
        nr+=2;
    }if(n%2) s-=2;
    g<<s<<'\n'<<"48"<<'\n';
    for(int i=1;i<=n;i++) g<<a[i]<<" ";
    return 0;
}
