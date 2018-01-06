#include <bits/stdc++.h>

using namespace std;
ifstream f("xor.in");
ofstream g("xor.out");
long t,p,a,b,c,d;
int main()
{
    f>>t>>p;
    if(p==2)
    {
        for(int i=1;i<=t;i++)
        {
            f>>a>>b>>c>>d;
            int linii=c-a+1,coloane=d-b+1;
            if(linii%2)
            {
                if(coloane%2)
                {
                    if(a%2&&b%2) g<<"0"<<'\n';
                    else if(a%2==0&&b%2==0) g<<"0"<<'\n';
                    else g<<"1"<<'\n';
                }
                else if(coloane%2==0) g<<"1"<<'\n';
            }
            else if(linii%2==0)
            {
                if(coloane%2==0) g<<"0"<<'\n';
                else g<<"1"<<'\n';
            }
        }
    }
    else
    {
        for(int k=1;k<=t;k++)
        {
            f>>a>>b>>c>>d;
            long s=0;
            for(int i=a;i<=c;i++)
                for(int j=b;j<=d;j++)
                s+=i^j;
            g<<s%p<<'\n';
        }
    }
    return 0;
}
