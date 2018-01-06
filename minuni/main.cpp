#include <fstream>

using namespace std;
ifstream f("minuni.in");
ofstream g("minuni.out");
int m,i,j;
long long n,s;
struct intervale
{
    long long st,dr,rez;
}a[100001];
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>a[i].st>>a[i].dr;
        s=n-a[i].dr+1;
        int maxs=0,maxd=0;
        for(j=1;j<i;j++)
            if(a[j].st<a[i].st&&a[j].dr>a[i].dr)
                if(a[j].st>maxs) maxs=a[j].st,maxd=a[j].dr;
        if(!maxs) a[i].rez=s*a[i].st;
        else a[i].rez=s*(a[i].st-maxs)+(maxd-a[i].dr)*maxs;
        g<<a[i].rez<<'\n';
    }
    return 0;
}
