#include <fstream>

using namespace std;
ifstream f("blaturi.in");
ofstream g("blaturi.out");
int sum1[100002],sum2[100002],n,cost[100002],c1,c2,s1,s2,i,minim=9999;
int main()
{
    f>>n;
    for(i=1;i<=n;i++) f>>cost[i];
    f>>c1>>s1>>c2>>s2;
    sum1[1]=c1*cost[1];
    for(i=2;i<=n;i++) sum1[i]=sum1[i-1]+c1*cost[i]+s1;
    sum2[n]=c2*cost[n];
    for(i=n-1;i>=1;i--) sum2[i]=sum2[i+1]+c2*cost[i]+s2;
    for(int i=0,j=1;i<=n;i++,j++)
        minim=min(minim,sum1[i]+sum2[j]);
    g<<minim;
    return 0;
}
