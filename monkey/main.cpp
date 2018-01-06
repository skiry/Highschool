#include <fstream>
#include <vector>
#include <cstdio>
using namespace std;
ifstream f("monkey.in");
int n,m,i,j,el,actual,total;
short int viza[1000001],vizb[1000001],vera[1000001],verb[1000001];
vector <int> a;
vector <int> b;
vector <int> v[1000001];
vector <int> c[1000001];
int main()
{
    FILE *g=fopen("monkey.out","w");
    f>>n>>m;
    for(i=1;i<=n;i++) f>>el,a.push_back(el),viza[el]=1,v[el].push_back(i);
    for(i=1;i<=n;i++) f>>el,b.push_back(el),vizb[el]=1,c[el].push_back(i);
    int minim1=0,minim2=0,nr=0;
    for(i=0;i<n&&minim2<n;i++)
    {
        actual=a[i];
        if(c[actual].size()>1) while(c[actual][0]<minim2) c[actual].erase(c[actual].begin());
        if(viza[actual]&&vizb[actual]&&v[actual][0]>minim1&&c[actual][0]>minim2)
        {
            nr++;
            minim1=v[actual][0];
            minim2=c[actual][0];
            v[actual].erase(v[actual].begin());
            c[actual].erase(c[actual].begin());
        }
    }
    total=nr;
    minim1=0,minim2=0,nr=0;
    for(i=0;i<n;i++)
    {
        if(!vera[a[i]]) v[a[i]].erase(v[a[i]].begin(),v[a[i]].end()),vera[a[i]]++;
        if(!verb[b[i]]) c[b[i]].erase(c[b[i]].begin(),c[b[i]].end()),verb[b[i]]++;
        v[a[i]].push_back(i+1);
        c[b[i]].push_back(i+1);
    }
    for(i=0;i<n&&minim1<n;i++)
    {
        actual=b[i];
        if(v[actual].size()>1) while(v[actual][0]<minim1) v[actual].erase(v[actual].begin());
        if(viza[actual]&&vizb[actual]&&v[actual][0]>minim1&&c[actual][0]>minim2)
        {
            nr++;
            minim1=v[actual][0];
            minim2=c[actual][0];
            v[actual].erase(v[actual].begin());
            c[actual].erase(c[actual].begin());
        }
    }
    if(total>nr) fprintf(g,"%d", total);
    else fprintf(g,"%d", nr);
    fclose(g);
    return 0;

}
