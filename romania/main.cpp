#include <fstream>

using namespace std;
ifstream f("romania.in");
ofstream g("romania.out");
int n,k,s[2500],i,j;
struct nod
    {
        int nr;
        nod *urm;
    };
nod *prim,*p,*ultim,*q;
void pune(nod *&prim,nod *ultim,int x)
{
    nod *p;
    if(!prim)
    {
        prim=new nod;
        prim->nr=x;
        prim->urm=0;
        ultim=prim;
    }
    else
    {
        p=new nod;
        p->nr=x;
        p->urm=0;
        ultim->urm=p;
        ultim=p;
    }
}

int main()
{
    f>>n>>k;
    for(i=1;i<=k;i++)
    {
        f>>s[i];
        for(j=1;j<=n;j++)
            if(j!=s[i]&&j!=s[i]-1&&j!=s[i]+1)
                if((s[i]==1&&j!=n)
                   ||(s[i]==n&&j!=1))

                g<<j<<" ";//pune(prim,ultim,j);
    }
    p=prim;
    /*while(p->urm)
    {
        q=p;
        while(q->urm)
            g<<q->nr,q=q->urm;
        p=p->urm;
        g<<endl;
    }*/
    //g<<prim->nr;




    return 0;
}
