#include <fstream>
#include <deque>
using namespace std;
ifstream f("volum.in");
ofstream g("volum.out");
int n,m,i,j;
long long a[753][753],b[753][753],rezultat,initial;
struct element
{
    int l,c;
};
element el,calc;
int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};
deque <element> q;
deque <element>::iterator it;
void backt(element el,long long initial)
{
    for(int k=0;k<4;k++)
    {
        calc.l=el.l+dl[k];
        calc.c=el.c+dc[k];
        if(a[calc.l][calc.c]!=-1)
        {
            if(a[calc.l][calc.c]<=initial)  a[calc.l][calc.c]=-1,rezultat+=initial-b[calc.l][calc.c],backt(calc,initial);
            else {q.push_back(calc);if(q.size()>1) for(int k=q.size()-2;k>=0&&b[q[k].l][q[k].c]>b[q[k+1].l][q[k+1].c];k--) swap(q[k],q[k+1]);}
        }
    }

    g<<rezultat<<" "<<initial<<endl;
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {f>>a[i][j];
            if(i==1||j==1||i==n||j==m)
            {
                el.l=i;
                el.c=j;
                b[i][j]=a[i][j];
                a[i][j]=-1;
                q.push_back(el);
                if(q.size()>1) for(int k=q.size()-2;k>=0&&b[q[k].l][q[k].c]>b[q[k+1].l][q[k+1].c];k--) swap(q[k],q[k+1]);
                if(i==1) a[0][j]=-1;
                if(j==1) a[i][0]=-1;
                if(i==n) a[n+1][j]=-1;
                if(j==m) a[i][m+1]=-1;
            }
        }
    while(q.size())
    {
        el=q.front();
        q.pop_front();
        long long initial=b[el.l][el.c];
        backt(el,initial);
    }
    //for(i=0;i<q.size();i++) g<<q[i].l<<" "<<q[i].c<<endl;
    g<<rezultat;
    return 0;
}
