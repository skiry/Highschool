#include <fstream>
#include <math.h>
using namespace std;
ifstream f("patrate7.in");
ofstream g("patrate7.out");
int n,m,a[30],i,nr,latura;
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>a[i],nr=nr+(1<<(a[i]-1));
    g<<nr<<endl;
    nr-=nr>>1;
    latura=(ceil(sqrt(1<<(n-1))));
    if(nr%latura==0) {
            g<<latura<<" "<<nr/latura;
    }
    else
    {
        g<<nr%latura<<" "<<nr/latura+1;
    }
    return 0;
}
