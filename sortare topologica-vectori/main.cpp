#include <fstream>

using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");
struct nod{int nr;
nod *urm;};
nod *a[100];
int contor[100],d[100],i,j;
void adaugare(int i,int j)
{
    nod *p,*c;
    contor[j]++;
    p=new nod;
    p->nr=j;
    p->urm=0;
    if(!a[i]) a[i]=p;
    else
    {
        c=a[i];
        while(c->urm) c=c->urm;
        c->urm=p;
    }
}

void marc(int i)
{
    while(a[i]) {contor[a[i]->nr]--;a[i]=a[i]->urm;}
}

int main()
{int n,m,k,ok;
    f>>n>>m;
for(int q=1;q<=m;q++)
    f>>i>>j,adaugare(i,j);

m=n;
do
    {
        k=1;
        ok=0;
        for(i=1;i<=n;i++)
            if(!contor[i])
        {
            ok=1;
            d[k]=i;
            k++;
            m--;
            contor[i]=-1;
        }
        for(i=1;i<k;i++)
            marc(d[i]),g<<d[i]<<" ";

    }
    while(ok&&m);
        if(m) g<<"Relatii contradictorii.";
    else g<<"Ordinea este cea de mai sus.";

    return 0;
}
