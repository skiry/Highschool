#include <bits/stdc++.h>

using namespace std;
ifstream f("teroristi.in");
ofstream g("teroristi.out");
int i,j,t[100001][3],n,m,viz[100001];
char a[100001],b,c;
vector <int> v[30];
vector <int>::iterator it;
int main()
{
    f>>n>>m;
    f>>a;
    for(i=1;i<=m;i++)
    {
        f>>b>>c;
        v[b-'a'].push_back(i),t[i][1]=b-'a';
        v[c-'a'].push_back(i),t[i][2]=c-'a';
    }
    for(i=0;i<strlen(a);i++)
    {
        int ok=0;
        for(int j=v[a[i]-'a'].size()-1;j>=0&&!ok;--j)
            if(!viz[v[a[i]-'a'][j]]) ++viz[v[a[i]-'a'][j]],g<<v[a[i]-'a'][j]<<" ",++ok;
    }
    return 0;
}
