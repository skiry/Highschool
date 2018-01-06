#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//ifstream cin("date.in");
//ofstream cout("date.out");
int n,i,x,y,culori,viz[200001],cul[200001],fol[200001],b,j,maxim;
vector <int> a[200001];
queue <int> q;
int main()
{
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
        if(x==1) cul[y]=2;
    }
    for(i=1;i<=n;i++) cul[i]=i;
    q.push(1);
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        viz[actual]=1;
        fol[cul[actual]]=actual;
        for(j=0;j<a[actual].size();j++)
        {
            if(cul[a[actual][j]]==cul[actual]) cul[a[actual][j]]=n;
            fol[cul[a[actual][j]]]=actual;
        }
        for(j=0;j<a[actual].size();j++)
            if(!viz[a[actual][j]])
        {
            for(i=1;i<=n;i++)
            if(fol[i]!=actual&&i<cul[a[actual][j]]) {cul[a[actual][j]]=i;fol[i]=actual;break;}

            q.push(a[actual][j]);
        }
    }
    for(i=1;i<=n;i++) if(cul[i]>maxim) maxim=cul[i];
    cout<<maxim<<'\n';
    for(i=1;i<=n;i++) cout<<cul[i]<<" ";
    return 0;
}
