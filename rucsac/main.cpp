#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int d[3][100],i,j,p[100],w[100],n,gmax;
int main()
{
    f>>n>>gmax;
    for(i=1;i<=n;i++)
        f>>w[i]>>p[i];
    for(i=0;i<=n;i++)
        {
            {
                for(j=0;j<=gmax;j++)
                    if(j<w[i+1])
                        d[2][j]=d[1][j];
                    else if(d[1][j]>d[1][j-w[i+1]]+p[i+1])
                            d[2][j]=d[1][j];
                    else d[2][j]=d[1][j-w[i+1]]+p[i+1];
            }

            for(int k=1;k<=gmax;k++) d[1][k]=d[2][k];
        }
    g<<d[2][gmax];
    return 0;
}
