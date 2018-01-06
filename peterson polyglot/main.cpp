#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//ifstream cin("date.in");
//ofstream cout("date.out");
struct nod
{
    int v,cost;
};
nod p;
int n,i,a,best=99999,poz,level[300001],maxim,j;
char c;
vector <nod> v[300001];
vector <int> lvl[300001];
vector <int>::iterator it;
queue <nod> q;
vector <int> sol;
int main()
{
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>a>>p.v>>c;
        p.cost=c-'a';
        v[a].push_back(p);
    }
    level[1]=1;
    lvl[1].push_back(1);
    p.v=1;
    q.push(p);
    while(q.size())
    {
        nod actual=q.front();
        q.pop();
        for(i=0;i<v[actual.v].size();i++)
        {
            level[v[actual.v][i].v]=level[actual.v]+1;
            if(level[actual.v]+1>maxim) maxim=level[actual.v]+1;
            lvl[level[v[actual.v][i].v]].push_back(v[actual.v][i].v);
            q.push(v[actual.v][i]);
        }
    }
    for(i=0;i<maxim;i++)
    {
        int sum=n;
        for(j=0;j<lvl[i].size();j++)
        {
            int curent=lvl[i][j];
            if(v[curent].size())
            {
                sum-=v[curent].size();
                for(int k=0;k<v[curent].size();k++)
                    if(v[v[curent][k].v].size())
                    {
                        for(int o=0;o<v[v[curent][k].v].size();o++)
                            if(find(sol.begin(),sol.end(),v[v[curent][k].v][o].cost)!=sol.end()) sum--;
                            else sol.push_back(v[v[curent][k].v][o].cost);
                    }
            sol.clear();
            }
            else sum--;

        }
        if(sum<best) best=sum,poz=i;
    }
    cout<<best<<'\n'<<poz;
    return 0;
}
