#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int x[100],n,gmax,v[100],i,j;
float c;
int main()
{f>>gmax>>n;
for(i=1;i<=n;i++)
    f>>x[i];
    for(i=1;i<=n;i++)
    f>>v[i];

for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    if((float)v[i]/x[i]<(float)v[j]/x[j])
{swap(v[i],v[j]);
swap(x[i],x[j]);
}
    i=1;
    while(gmax-x[i]>=0)
    {c+=v[i];
    gmax-=x[i];
    i++;}
     c+=gmax*(float)v[i]/x[i];
    g<<c;



    return 0;
}
