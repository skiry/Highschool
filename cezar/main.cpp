#include <fstream>

using namespace std;
ifstream f("cezar.in");
ofstream g("cezar.out");
short n,m,n1;
struct nod
{
    short nr,t,val,nr1,viz;
    nod *urm;
};
nod *l[10000],*p,*q;
void pune(int x,int y)
{
    if(l[y]->t==0)
    {
        if(l[x]->nr==0)
        {
            l[x]->nr=y;
            l[x]->urm=0;
        }
        else if(l[x]->nr)
        {
            p=l[x];
            while(p->urm)
                p=p->urm;
            q=new nod;
            q->nr=y;
            q->urm=0;
            p->urm=q;
        }
        l[y]->t=x;
        l[x]->nr1++;
    }
    else if(l[y]->t!=0)
    {
        if(l[y]->nr==0)
        {
            l[y]->nr=x;
            l[y]->urm=0;
        }
        else
        {
            p=l[y];
            while(p->urm)
                p=p->urm;
            q=new nod;
            q->nr=x;
            q->urm=0;
            p->urm=q;
        }
        l[x]->t=y;
        l[y]->nr1++;
    }
}
void desfrunzire()
{
    short mx=9999;
    for(short i=1;i<=n;i++)
        if(l[i]->nr1<mx)
            mx=l[i]->nr1;///NU E NR, E VAL!
    //g<<"mx:"<<mx<<" ";
    for(short i=1;i<=n&&n1>m+1;i++)
        if(l[i]->nr1==mx&&((l[l[i]->t]->viz==0)||(l[l[i]->t]->viz==1&&l[l[i]->t]->nr1!=0)))
        {
            //g<<i<<" "<<mx<<" ";
            if(l[l[i]->t]->nr1)
            for(p=l[l[i]->t];p;p=p->urm)
                if(p->nr==i) //g<<i<<"  ",
                    p->nr=0,l[l[i]->t]->nr1--,l[l[i]->t]->val+=1,l[l[i]->t]->viz=1,n1--,l[i]->val=0;
        }
};
int main()
{
    short x,y,i;
    f>>n>>m;
    n1=n;
    for(int i=1;i<=n;i++)
        l[i]=new nod,l[i]->nr=0,l[i]->t=0,l[i]->nr1=0,l[i]->val=1,l[i]->urm=0;
    for(i=1;i<n;i++)
    {
        f>>x>>y;
        pune(x,y);
    }
    for(i=1;i<=n;i++)
    {
        p=l[i];
        if(p->nr)
        while(p) g<<p->nr<<" ",p=p->urm;
        g<<endl;
    }
    for(i=1;i<=n;i++) l[i]->viz=0;
        desfrunzire();
        g<<endl;
        g<<n1<<endl;
    for(i=1;i<=n;i++) g<<l[i]->val<<" ";
    g<<endl;

    for(i=1;i<=n;i++) l[i]->viz=0;
        desfrunzire();
        g<<endl;
        g<<n1<<endl;
    for(i=1;i<=n;i++) g<<l[i]->val<<" ";
    g<<endl;
    /**for(short h=1;h<=100&&n1>m+1;h++)
    {
        for(i=1;i<=n;i++) l[i]->viz=0;
        desfrunzire();
    }*/
    short s=0;
    for(i=1;i<=n;i++) s+=l[i]->val;
    g<<s;
    return 0;
}
