#include <bits/stdc++.h>

using namespace std;
ifstream f("search.in");
ofstream g("search.out");
vector <int> a[101][30];
deque <int> rezultat;
deque <int> q[101];
int n,m,i,j,k,nr;
char s[5001],c;
int main()
{
    f>>n>>m;
    f.get();
    for(i=1;i<=n;i++)
    {
        f.getline(s,5001);
        for(j=0;j<strlen(s);j++)
            a[i][s[j]-'a'].push_back(j);
    }
    for(k=1;k<=m;k++)
    {
        f>>c;
        nr=0;
        if(c=='-')
        {
            rezultat.pop_front();
            g<<rezultat.front()<<'\n';
            for(i=1;i<=n;i++) if(q[i].size()) q[i].pop_front();
        }
        else
        {
            for(i=1;i<=n;i++)
                if(a[i][c-'a'].size())
            {
                if(q[i].size())
                {
                    if(q[i].front()!=-1)
                    {
                        for(j=0;j<a[i][c-'a'].size()&&a[i][c-'a'][j]<=q[i].front();++j);
                        if(j<a[i][c-'a'].size()&&a[i][c-'a'][j]>q[i].front())
                        {
                            nr++,q[i].push_front(a[i][c-'a'][j]);
                        }
                        else q[i].push_front(-1);
                    }
                    else q[i].push_front(-1);
                }
                else nr++,q[i].push_front(a[i][c-'a'][0]);
            }
            else q[i].push_front(-1);
            rezultat.push_front(nr);
            g<<rezultat.front()<<'\n';
        }
    }
    return 0;
}
