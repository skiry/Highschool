#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
char x[100];
int main()
{int n,m,a[100][100];
int i,j;
      f>>n>>m;
    for(i=1;i<=n;i++)
        {for(j=1;j<=m;j++)
          {
              f>>x; if(x=="R") a[i][j]=1;
                        else if(x=="J") a[i][j]=2;
                        else if(x=="X") a[i][j]=-1;
                        else if(x==32)  a[i][j]=0;
                        }

                        g<<endl;
        }
          }
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++) g<<a[i][j]<<" ";g<<endl;}

    return 0;
}
