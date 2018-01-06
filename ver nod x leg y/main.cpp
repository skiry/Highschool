#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,u=0,n,p1,m,x,y,a[100][100],coada[100],viz[100],ok,nr,ok1=0,nr1;
void parc(int p1,int y,int ok1)
{
    for(int i=1;i<=n;i++)
        if(a[coada[p1]][i]&&viz[i]==0)
            {
                if(i==y) ok1=1;
                u++, coada[u]=i, viz[i]++;
            }
    if(p1<=u)
    {
        parc(p1+1,y,ok1);
        if(!ok1) nr1++;
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y, a[x][y]=1, a[y][x]=1;
    f>>x>>y;
    viz[x]=1;
    coada[1]=x;
    u=1;
    parc(1,y,0);
    g<<"De la "<<x<<" la "<<y<<" : ";
    for(i=1;i<=u;i++)
        if(coada[i]==y)
            ok=1;
    if(ok) g<<"Da";
    else g<<"Nu";
    g<<endl;
    if(n==u) g<<"Graful este conex!";
    else g<<"Nu se poate parcurge pornind de la un nod tot graful.";
    g<<endl;
    g<<"Lantul de lungime minima este de "<<nr1;
    return 0;
}
