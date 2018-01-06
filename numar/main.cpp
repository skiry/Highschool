/**#include <fstream>

using namespace std;
ifstream f("numar2.in");
ofstream g("numar2.out");
int n,m,i,x,lim,j;
struct nod
{
    int nr;
    nod *urm;
};
nod *l,*p,*q;
int main()
{
    f>>n>>m;
    f>>x;
    lim=x*m;
    i=1;
    while(i<=m)
    {
        if(!l)
        {
            l=new nod;
            l->nr=x*i;
            l->urm=0;
        }
        else
        {
            p=l;
            while(p->urm) p=p->urm;
            q=new nod;
            q->nr=x*i;
            q->urm=0;
            p->urm=q;
        }
        i++;
    }
    for(i=2;i<=n;i++)
    {
        f>>x;
        j=1;
        while(x*j<=lim)
        {
            p=l;
            while(x*j>p->nr&&x*j>p->urm->nr) p=p->urm;
            if(p->urm->nr!=x*j)
            {
                q=new nod;
                q->nr=x*j;
                q->urm=p->urm;
                p->urm=q;
            }
            j++;
        }
    }
    i=1;
    for(p=l;p&&i!=m;p=p->urm) i++;
    g<<p->nr;

    return 0;
}
*/
#include <fstream>

using namespace std;
ifstream f("numar2.in");
ofstream g("numar2.out");
int n,m,i,a[100],nr,j,nr1;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    nr=1;
    //m=m+5;
    m=m+1;
    for(i=1;nr<=m;i++)
    {
        if(nr==m) g<<i-1,nr++;
        nr1=nr;
        for(int j=1;j<=n;j++)
            if(i%a[j]==0&&a[j]>=a[1]&&i>=a[j]) nr=nr1+1;
    }

    return 0;
}

