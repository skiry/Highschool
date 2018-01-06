#include <bits/stdc++.h>

using namespace std;
ifstream f("telefon2.in");
ofstream g("telefon2.out");
int n,i,el,viz[100001],nrculori,t[100001];
vector <int> a[100001];
queue <int> q;
void ver(int nod,int culoare)
{
    q.push(nod);
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        if(!viz[a[actual][0]]) viz[a[actual][0]]=culoare,q.push(a[actual][0]);
    }
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>el,a[i].push_back(el),t[el]=i;
    for(i=1;i<=n;i++)
        if(!viz[i]) ver(i,++nrculori);
    g<<(nrculori-1)*2<<'\n';
    for(i=1;i<=(nrculori-1)*2;i++)
    {
        int ok=0;
        for(int j=1;j<n&&!ok;j++)
            for(int k=j+1;k<=n&&!ok;k++)
            if(viz[i]!=viz[j])
        {
            g<<i<<" "<<j<<'\n';
            g<<t[j]<<" "<<a[i][0]<<'\n';
            a[t[j]][0]=a[i][0];
            t[a[i][0]]=t[j];
            a[i][0]=j;
            t[j]=i;
            for(int e=1;e<=n;e++)
                if(viz[e]==viz[j]&&e!=j) viz[e]=viz[i];
            viz[j]=viz[i];
            ++ok;
        }
    }
    return 0;
}
