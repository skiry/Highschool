#include <fstream>
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int queries,i,j,n,m,a[1001][1001],u,v,s,nr=0,c[1001],d[1001],val=0,viz[1001];

int main() {

    cin >> queries;

    for (int t = 0; t < queries; t++) {
        cin >> n>>m;

        for(i=1;i<=m;i++)
            cin>>u>>v,a[u][v]=a[v][u]=6;
        cin>>s;
int prim=val=1;
c[1]=s;
d[s]=0;
while(prim<=val)
{
    int nod=c[prim];
    for(int i=1;i<=n;i++)
        if(a[nod][i]&&!viz[i]) viz[i]=1,d[i]=d[nod]+6,c[++val]=i;
    prim++;
}


    for(i=1;i<=n;i++)
        if(i!=s)
        if(d[i]==0) cout<<"-1 ";
        else cout<<d[i]<<" ";cout<<endl;

    for(i=1;i<=n;i++){

    d[i]=viz[i]=0;
        for(j=1;j<=m;j++)
        a[i][j]=0;}
    }
    return 0;
}
