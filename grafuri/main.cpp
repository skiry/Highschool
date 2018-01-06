#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int main()
{
    int x,u,i,a[100][100],b,c,j,s;
    f>>x>>u;
for(i=1;i<=u;i++)
{
    f>>b>>c;
    a[b][c]=1;
    a[c][b]=1;
}
for(i=1;i<=x;i++)
{
    s=0;
    for(j=1;j<=x;j++) s+=a[i][j];
    g<<i<<" : "<<s<<endl;
}
    return 0;
}
