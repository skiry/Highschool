#include <fstream>

using namespace std;
ifstream f("arbxyz.in");
ofstream g("arbxyz.out");
int nr,n,x,y,z,a,b,i,j,t[100001],v,val,stop;
struct grad
{
    int e,t,t1;
};
grad d[100001];
/**void gradtotal(int a)
{
    for(int i=1;i<=n;i++)
        if(t[i]==a&&d[i].e) d[i].t=d[a].t-d[a].e,gradtotal(i);
}*/
void scadgrad(int a,int val)
{
    if(t[a]) d[a].t=d[a].t-val,scadgrad(t[a],val);
        else d[a].t=d[a].t-val;
}
/**int rezolvare(int x,int y,int z)
{
    int ok=1;
    for(i=1;i<=n;i++)
    {
        if(d[i].t==x)
        {
            val=x,x=0,scadgrad(t[i],val),i=n+1,ok=0;
            if(d[t[i]].t>d[i].t) stop=t[i];
                else stop=i;
        }
        else if(d[i].t==y)
        {
            val=y,y=0,scadgrad(t[i],val),i=n+1,ok=0;
            if(d[t[i]].t>d[i].t) stop=t[i];
                else stop=i;
        }
        else if(d[i].t==z)
        {
            val=z,z=0,scadgrad(t[i],val),i=n+1,ok=0;
            if(d[t[i]].t>d[i].t) stop=t[i];
                else stop=i;
        }
        //g<<"prima"<<x<<" "<<y<<" "<<z<<endl;
    }
    if(!ok)
    {
        for(i=1;i<=n;i++)
        {
            if(d[i].t==x&&x) i=n+1,ok=2;
            if(d[i].t==y&&y) i=n+1,ok=2;
            if(d[i].t==z&&z) i=n+1,ok=2;
        }
        //g<<"a doua"<<x<<" "<<y<<" "<<z<<endl;
    }
    if(ok==2) return 1;
    if(!ok)
    {
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
                //if(d[i].t!=1&&d[i].t!=1)
                    if(d[i].t-d[j].t==x&&x&&i!=stop) {i=n;return 1;}
                    else if(d[i].t-d[j].t==y&&y&&i!=stop) {i=n;return 1;}
                    else if(d[i].t-d[j].t==z&&z&&i!=stop) {i=n;return 1;}
                    else if(d[j].t-d[i].t==x&&x&&i!=stop) {i=n;return 1;}
                    else if(d[j].t-d[i].t==x&&x&&i!=stop) {i=n;return 1;}
                    else if(d[j].t-d[i].t==x&&x&&i!=stop) {i=n;return 1;}
        }
        //g<<"a treia"<<x<<" "<<y<<" "<<z<<endl;
    }
    if(ok==1)
    {
        for(i=1;i<n&&ok==1;i++)
        {
            for(j=i+1;j<=n&&ok==1;j++)
                //if(d[i].t!=1&&d[i].t!=1)
                    if(d[i].t-d[j].t==x&&x&&i!=stop)
                    {
                        val=d[i].t-d[j].t,x=0,scadgrad(t[i],val);
                        if(ok==3) ok=5;
                        if(ok==1) ok=3;
                            if(d[j].t>d[i].t) stop=i;
                                else stop=j;
                    }
                    else if(d[i].t-d[j].t==y&&y&&i!=stop)
                        {
                        val=d[i].t-d[j].t,y=0,scadgrad(t[i],val);
                        if(ok==3) ok=5;
                        if(ok==1) ok=3;
                            if(d[j].t>d[i].t) stop=i;
                                else stop=j;
                        }
                    else if(d[i].t-d[j].t==z&&z&&i!=stop)
                    {
                        val=d[i].t-d[j].t,x=0,scadgrad(t[i],val);
                        if(ok==3) ok=5;
                        if(ok==1) ok=3;
                            if(d[j].t>d[i].t) stop=i;
                                else stop=j;
                    }
                    else if(d[j].t-d[i].t==x&&x&&i!=stop)
                    {
                        val=d[i].t-d[j].t,x=0,scadgrad(t[i],val);
                        if(ok==3) ok=5;
                        if(ok==1) ok=3;
                            if(d[j].t>d[i].t) stop=i;
                                else stop=j;
                    }
                    else if(d[j].t-d[i].t==y&&y&&i!=stop)
                    {
                        val=d[i].t-d[j].t,y=0,scadgrad(t[i],val);
                        if(ok==3) ok=5;
                        if(ok==1) ok=3;
                            if(d[j].t>d[i].t) stop=i;
                                else stop=j;
                    }
                    else if(d[j].t-d[i].t==z&&z&&i!=stop)
                    {
                        val=d[i].t-d[j].t,z=0,scadgrad(t[i],val);
                        if(ok==3) ok=5;
                        if(ok==1) ok=3;
                            if(d[j].t>d[i].t) stop=i;
                                else stop=j;
                    }
        }
        //g<<"a patra"<<x<<" "<<y<<" "<<z<<endl;
    }
    if(ok==5) return 1;
    return 0;
}
*/
int rezolvare(int x,int y,int z)
{
    return v;
}
void adaugare(int a)
{
    d[a].t++;d[a].t1++;
    if(t[a]) adaugare(t[a]);
}
int main()
{
    f>>nr;
    f>>n>>x>>y>>z;

    for(i=1;i<n;i++)
        f>>a>>b,d[a].e++,t[b]=a;

    //for(i=1;i<=n;i++) g<<d[i].e<<" ";g<<endl;

    //for(i=1;i<=n;i++) g<<t[i]<<" ";g<<endl;

    for(i=1;i<=n;i++)
        if(t[i]) adaugare(i);
            else d[i].t++,d[i].t1++,v=i;

    //for(i=1;i<=n;i++) g<<d[i].t<<" ";g<<endl;

    g<<rezolvare(x,y,z)<<endl;
    //for(i=1;i<=n;i++) g<<d[i].t<<" ";g<<endl;
    for(int h=2;h<=nr;h++)
    {
        f>>x>>y>>z;
        for(i=1;i<=n;i++)
            d[i].t=d[i].t1;
        g<<rezolvare(x,y,z)<<endl;
    }
    return 0;
}
