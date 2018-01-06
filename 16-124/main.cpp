#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,i,j,x,p;
int main()
{f>>n;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    f>>a[i][j];
    for(i=1;i<=n;i++)
        {x=i;
        if(a[i][1]%10==0)
    {for(p=1;p<n;p++)
    {for(j=i;j<=n;j++)
    for(i=1;i<=n;i++)
        swap(a[j][i],a[j][i]);

    }i=x;
        n--;}
    }
for(i=1;i<=n;i++)
   {

    for(j=1;j<=n;j++)g<<a[i][j]<<" ";
g<<'\n';}

    return 0;
}
