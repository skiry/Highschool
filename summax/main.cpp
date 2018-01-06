#include <fstream>
#include <vector>
using namespace std;
ifstream f("summax.in");
ofstream g("summax.out");
unsigned int st,dr,el,dist,sol[2001];
short int v,n,i,j,k;
vector <unsigned int> a[2001];
vector <unsigned int> c[2001];
void afis(int i,int j)
{
    if(dist+c[i][j]<st)
    {
        dist+=c[i][j];
        return;
    }
    sol[i]=j;
    if(i==n)
    {
        dist++;
        for(k=1;k<=n;k++)
            g<<sol[k]+1<<" ";
        g<<'\n';
        return;
    }
    if(a[i+1][j]>=a[i+1][j+1])
    {
        afis(i+1,j);
        if(dist==dr) return;
    }
    if(a[i+1][j]<=a[i+1][j+1])
        afis(i+1,j+1);
}
int main()
{
    f>>v;
    f>>n>>st>>dr;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            f>>el;
            a[i].push_back(el);
        }
    }
    for(i=n-1;i>=1;i--)
    {
        for(j=0;j<i;j++)
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
    }
    for(i=0;i<n;i++)
        c[n].push_back(1);
    for(i=n-1;i>=1;i--)
    {
        for(j=0;j<i;j++)
        {
                    if(a[i+1][j]<a[i+1][j+1]) c[i].push_back(c[i+1][j+1]);
                else if(a[i+1][j]>a[i+1][j+1]) c[i].push_back(c[i+1][j]);
            else if(a[i+1][j]==a[i+1][j+1]) c[i].push_back(c[i+1][j+1]+c[i+1][j]);

            if(c[i][j]>2000000001) c[i][j]=2000000001;
        }
    }
    if(v==1)    g<<c[1][0];
    else afis(1,0);
    return 0;
}
