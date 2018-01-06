#include <fstream>
#include <vector>
using namespace std;
ifstream f("scara3.in");
ofstream g("scara3.out");
int n,apa,redbull,b,c,i,j,rez[1201],cost[1201];
vector <int> a[1201];
vector <int> rb[1201];
int main()
{
    f>>n;
    f>>apa;
    for(i=1;i<=apa;i++)
    {
        f>>b>>c;
        a[b].push_back(c);
    }
    f>>redbull;
    for(i=1;i<=redbull;i++)
    {
        f>>b>>c;
        rb[b].push_back(c);
    }
    rez[1]=1;
    for(i=1;i<=n;i++)
    {
        if(!rez[i]) rez[i]=rez[i-1]+1,cost[i]=cost[i-1];
        if(a[i].size())
            for(j=1;j<=a[i][0]&&i+j<=n;j++)
                if(rez[i+j]>rez[i]+1||!rez[i+j]||(rez[i+j]==rez[i]+1&&cost[i+j]>cost[i]))
                    rez[i+j]=rez[i]+1,cost[i+j]=cost[i];
        if(rb[i].size())
            for(j=1;j<=rb[i][0]*2&&i+j<=n;j++)
                if(!rez[i+j]||rez[i+j]>rez[i]+1||(rez[i+j]==rez[i]+1&&cost[i+j]>cost[i]+(j-1)/2+1))
                    rez[i+j]=rez[i]+1,cost[i+j]=cost[i]+(j-1)/2+1;
    }
    g<<rez[n]<<" "<<cost[n];
    return 0;
}
