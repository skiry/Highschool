#include <bits/stdc++.h>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,n,m,i,j,k,vizt[30][30];
char a[30][30];
struct maxim
{
    int st,dr,sus,jos;
}maxim[30];
struct punct
{
    int l,c,vecini;
}el,el2;
struct cmp
{
    bool operator() (punct const &b,punct const &ce)
    {
        return b.vecini<ce.vecini;
    }
};
int numaravecini(int i,int j)
{
    if(i==1||i==n) {if(j>1&&j<m) return 20;
    else return 10;}
    else if(j==1||j==m) {if(i>1&&i<n)return 20;
    else return 10;}
        else{int nr1=0;
            if(a[i+1][j]>='A'&&a[i+1][j]<='Z') nr1++;
            if(a[i-1][j]>='A'&&a[i-1][j]<='Z') nr1++;
            if(a[i][j-1]>='A'&&a[i][j-1]<='Z') nr1++;
            if(a[i][j+1]>='A'&&a[i][j+1]<='Z') nr1++;

            return nr1;
        }
}
priority_queue <punct,vector <punct>, cmp> q;
queue <punct> viz;
void update(int i,int j)
{
    if(a[i-1][j]!=a[i][j]&&a[i-1][j]>='A'&&a[i-1][j]<='Z'&&(!maxim[a[i-1][j]-'A'].jos||maxim[a[i-1][j]-'A'].jos<i-1))
    {
        maxim[a[i-1][j]-'A'].jos=i-1;
        if(!maxim[a[i][j]-'A'].sus||maxim[a[i][j]-'A'].sus<i) maxim[a[i][j]-'A'].sus=i;
    }
    if(a[i+1][j]!=a[i][j]&&a[i+1][j]>='A'&&a[i+1][j]<='Z'&&(!maxim[a[i+1][j]-'A'].sus||maxim[a[i+1][j]-'A'].sus<i+1))
    {
        maxim[a[i+1][j]-'A'].sus=i+1;
        if(!maxim[a[i][j]-'A'].sus||maxim[a[i][j]-'A'].jos<i) maxim[a[i][j]-'A'].jos=i;
    }
    if(a[i][j-1]!=a[i][j]&&a[i][j-1]>='A'&&a[i][j-1]<='Z'&&(!maxim[a[i][j-1]-'A'].dr||maxim[a[i][j-1]-'A'].dr<j-1))
    {
        maxim[a[i-1][j]-'A'].dr=i-1;
        if(!maxim[a[i][j]-'A'].st||maxim[a[i][j]-'A'].st<j) maxim[a[i][j]-'A'].st=j;
    }
    if(a[i][j+1]!=a[i][j]&&a[i][j+1]>='A'&&a[i][j+1]<='Z'&&(!maxim[a[i][j+1]-'A'].st||maxim[a[i][j+1]-'A'].st<j+1))
    {
        maxim[a[i+1][j]-'A'].st=i+1;
        if(!maxim[a[i][j]-'A'].dr||maxim[a[i][j]-'A'].dr<j) maxim[a[i][j]-'A'].dr=j;
    }
}
int pune(int i,int j)
{
    if(a[i+1][j]>='A'&&a[i+1][j]<='Z'&&(!maxim[a[i+1][j]-'A'].sus||maxim[a[i+1][j]-'A'].sus>=i)) {a[i][j]=a[i+1][j];update(i+1,j);return 0;}
     if(a[i][j-1]>='A'&&a[i][j-1]<='Z'&&(!maxim[a[i][j-1]-'A'].dr||maxim[a[i][j-1]-'A'].dr>=j)) {a[i][j]=a[i][j-1];update(i,j-1);return 0;}
     if(a[i-1][j]>='A'&&a[i-1][j]<='Z'&&(!maxim[a[i-1][j]-'A'].jos||maxim[a[i-1][j]-'A'].jos>=i)) {a[i][j]=a[i-1][j];update(i-1,j);return 0;}
     if(a[i][j+1]>='A'&&a[i][j+1]<='Z'&&(!maxim[a[i][j+1]-'A'].st||maxim[a[i][j-1]-'A'].st>=j)) {a[i][j]=a[i][j+1];update(i,j+1);return 0;}

}

int main()
{
    f>>t;int valmax=t;
    for(k=1;k<=valmax;k++)
    {
        f>>n>>m;int nr=0;
        g<<"Case #"<<k<<":"<<'\n';
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                f>>a[i][j];
        for(i=0;i<=30;i++) maxim[i].sus=maxim[i].jos=maxim[i].st=maxim[i].dr=0;
            for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(a[i][j]!='?') update(i,j);
                else el.l=i,el.c=j,el.vecini=numaravecini(i,j),q.push(el);
        while(q.size())
        {
            el=q.top();
            q.pop();
            i=el.l;
            j=el.c;
            el2.l=i;
            el2.c=j;
if(a[i-1][j]=='?')pune(i,j),el2.vecini=numaravecini(i,j),q.push(el2);
            if(a[i-1][j]=='?') el2.l--,pune(i-1,j),el2.vecini=numaravecini(i-1,j),q.push(el2),viz.push(el2);
            if(a[i+1][j]=='?') el2.l+=2,pune(i+1,j),el2.vecini=numaravecini(i+1,j),q.push(el2),viz.push(el2);
            if(a[i][j-1]=='?') el2.l--,el2.c--,pune(i,j-1),el2.vecini=numaravecini(i,j-1),q.push(el2),viz.push(el2);
            if(a[i][j+1]=='?') el2.c+=2,pune(i,j+1),el2.vecini=numaravecini(i,j+1),q.push(el2),viz.push(el2);
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)
            g<<a[i][j];g<<'\n';}
    }
    return 0;
}
