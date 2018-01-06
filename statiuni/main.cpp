#include <fstream>
#include <vector>
using namespace std;
ifstream f("statiuni.in");
ofstream g("statiuni.out");
int n,k,gr[100001],nr,i,j,d[35][100001],b,c,viz[100001];
vector <int> a[100001];
void dfs(int i,int nr,int val)
{
    for(int h=0;h<a[i].size();h++)
        if(viz[a[i][h]]!=nr)
        {
            viz[a[i][h]]=nr;
            d[nr][a[i][h]]=val;
            val++;
            dfs(a[i][h],nr,val);
            val--;
        }
}
int main()
{
    f>>n>>k;
    for(i=1;i<n;i++)
    {
        f>>b>>c;
        a[b].push_back(c);
        a[c].push_back(b);
        gr[b]++;
        gr[c]++;
    }
    for(i=1;i<=n;i++)
        if(gr[i]==1)
        {
            ++nr;
            for(int h=1;h<=n;h++)
                if(h!=i)
                    d[nr][h]=99999;
            d[nr][i]=0;
            d[nr][0]=i;
            int val=1;
            viz[i]=nr;
            dfs(i,nr,val);
        }
        int nr1=0;
        for(i=1;i<=n;i++)
            {
                int ok=2;
                for(j=1;j<=nr&&ok;j++)
                    if(d[j][i]<=k&&ok) ok--;
                if(!ok) nr1++;
            }
        g<<nr1;

    return 0;
}
