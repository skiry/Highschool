#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("biperm.in");
ofstream g("biperm.out");
struct plecare
{
    int val,s,d;
};
plecare a[100001];
int n,i,nr,b[100001],gx[100001],gy[100001],valoare,valmin,x[100001],y[100001],maxim,rezfinal,viz[100001],t[100001];
int drum(int p,int sos,int nr1)
{
   x[nr1]=p;
   //g<<p<<" "<<sos<<" "<<nr1<<endl;
   x[nr1+1]=sos;
   if(gy[sos]==2) {if(nr1<maxim) maxim=nr1; return nr1;}
   if(nr1<=n) drum(sos,a[sos].s,nr1+1);
   return 0;
}
int drum1(int p,int sos,int nr1)
{
   y[nr1]=p;
   //g<<p<<" "<<sos<<" "<<nr1<<endl;
   y[nr1+1]=sos;
   if(gy[sos]==2) {if(nr1<maxim) maxim=nr1; return nr1;}
   if(nr1<=n) drum1(sos,a[sos].s,nr1+1);
   return 0;
}
void conex(int i,int nr,int col)
{//g<<i<<" "<<nr<<endl;
    viz[i]=1;///SALVEAZA IN VECTOR CU STANGA SI DREAPTA, UPDATEURILE PT A AFISA IN O(1)!!!
    //g<<i<<" "<<nr<<" "<<col<<endl;
    if(!viz[b[col]])
    {
        for(int h=1;h<=n;h++)
            if(a[h].val==b[col])
                        conex(b[col],nr,h);
    }
}
void afis(int i,int nr)
{
    //g<<i<<" "<<nr<<endl;
    viz[i]=1;
    if(!viz[t[i]]) afis(t[i],nr);
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a[i].val;
        gx[a[i].val]++;
    }
    for(i=1;i<=n;i++)
    {
        f>>nr;
        b[i]=nr;
        if(!a[a[i].val].s) a[a[i].val].s=nr;
        else a[a[i].val].d=nr;
        //t[nr]=a[i].val;
        gy[nr]++;
    }

                        /**for(int h=1;h<=n;h++) g<<h<<" ";
                        g<<endl;g<<endl;
                        for(int h=1;h<=n;h++) g<<a[h].val<<" ";
                        g<<endl;
                        for(int h=1;h<=n;h++) g<<a[h].s<<" ";
                        g<<endl;
                        for(int h=1;h<=n;h++) g<<a[h].d<<" ";
                        g<<endl;*/
    ///for(i=1;i<=n;i++) g<<i<<" : "<<a[i].s<<" "<<a[i].d<<endl;
    ///for(i=1;i<=n;i++) g<<gx[i]<<" "<<gy[i]<<endl;
    int ok=1;
    while(ok)
    {
        ok=0;
        int valoare=0;
        for(i=1;i<=n;i++)
            if(gx[i]==2)
            {
                ok=1;
                valoare=i;
                break;
            }
    if(ok&&valoare)
        {
            int cauta=a[valoare].s;
            maxim=99999;
            drum(valoare,cauta,1);
            valmin=min(maxim,99999);
            cauta=a[valoare].d;
            maxim=99999;
            drum1(valoare,cauta,1);
            valmin=min(maxim,valmin);

            if(valmin==maxim) {
                for(i=1;i<=valmin+1;i++) x[i]=y[i];
            }
            for(i=1;i<=valmin;i++)
                {
                    for(int j=1;j<=n;j++)
                        if(a[j].val==x[i]&&b[j]==x[i+1])
                        {
                            swap(a[j].val,b[j]);
                            //t[x[i]]=x[i+1];
                            gx[x[i]]--;
                            gy[x[i]]++;
                            gx[x[i+1]]++;
                            gy[x[i+1]]--;
                            break;
                        }
                }
            rezfinal+=valmin;
        }
    }
    for(i=1;i<=n;i++) t[b[i]]=a[i].val;
    int nr=0;
    ///for(i=1;i<=n;i++)
       ///if(a[i].val!=b[i]) if(!viz[a[i].val]) conex(a[i].val,++nr,i);
    for(i=1;i<=n;i++) if(a[i].val!=b[i]) if(!viz[a[i].val]) afis(a[i].val,++nr);
    g<<(1<<nr)<<" "<<rezfinal<<endl;
    for(i=1;i<=n;i++) g<<a[i].val<<" ";
    g<<endl;
    for(i=1;i<=n;i++) g<<b[i]<<" ";
    return 0;
}
