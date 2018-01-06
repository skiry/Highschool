#include <iostream>

using namespace std;
int n,i,gas[1000001],a,b,cap,m,actual;
char c;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>c;
        gas[i]=c-'0';
    }
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>cap;
        int madestations=0;
        while(a<b)
        {
            for(actual=a+cap;!gas[actual]&&actual>a;actual--);
            if(a+cap>=b&&!gas[b]) actual=0,a=b;
            if(actual)
            {
                if(actual==a)
                {
                    madestations++;
                    a+=cap;
                }
                else a=actual;
            }
        }
        cout<<madestations<<'\n';
    }
    return 0;
}
