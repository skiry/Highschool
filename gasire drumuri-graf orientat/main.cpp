#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,i,j,x,y,a[100][100],drum[100][100],ext[100],viz[100],c[100],ultim,gasit;
void bfs(int i)
{
    int prim=ultim=1;
    c[1]=i;
    while(prim<=ultim)
    {
        int nod=c[prim];
        viz[nod]=1;
        for(int j=1;j<=n;j++)
            if(a[nod][j])
                if(!viz[j]) c[++ultim]=j;
        /*else {
            for(int j=1;j<=n;j++)
                    drum[i][j]=drum[gasit][j];
                drum[i][gasit]=1;
        }*/
        prim++;
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        {
            f>>x>>y;
            a[x][y]=1;
            ext[x]++;
        }
    for(i=1;i<=n;i++)
        {
            bfs(i);
            for(j=1;j<=n;j++) viz[j]=0;
                for(int j=2;j<=ultim;j++)
                        drum[i][c[j]]=1;
        }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        g<<drum[i][j]<<" ";g<<endl;}
    return 0;
}
