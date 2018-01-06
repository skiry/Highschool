#include <fstream>

using namespace std;
ifstream f("potriv.in");
ofstream g("potriv.out");
int n,a[1001],s[1001],i,j,sa=0,smin=0,suma,k;
/**void afis()
{
    long long prod=0;
    for(int i=1;i<=n;i++)
        g<<a[i]<<"*"<<i<<" ",prod+=i*a[i];
        if(prod==s) g<<"DAAAAA";
    g<<endl<<prod<<endl<<endl;

    rez[ind++]=prod;
}
int p(int k)
{
    if(k==n+1) afis();
    else
        for(int i=1;i<=n;i++)
            if(pus[i]==0)
    {
        a[k]=i;
        pus[i]=1;
        p(k+1);
        pus[i]=0;
    }

}*/
int main()
{
    f>>n>>suma;
    /**p(1);
    for(int i=1;i<ind;i++)
    {
        g<<rez[i]<<" ";
        if(i%((ind-1)/n)==0) g<<endl;
    }
g<<rez[ind-1];*/
    for(i=1;i<=n;i++)
        a[i]=i,sa+=i*i,s[i]=sa;
    if(sa<suma) g<<"no sol.";

    for(i=1;i<=n;i++)
        smin+=(n-i+1)*i;
    if(smin>suma) g<<"no sol.";

    while(sa>suma)
    {
        int ok=0;
        for(i=n;i>=2&&!ok;i--)
            for(j=i-1;j>=1&&!ok;j--)
        {
            k=(a[i]*i+a[j]*j)-(a[i]*j+a[j]*i);

            if(k>0&&sa-k>=suma)
                {
                   smin=a[i];
                   a[i]=a[j];
                   a[j]=smin;
                    sa-=k;
                    ok=1;
                }
        if(ok) break;
        }
    }
    for(i=1;i<=n;i++) g<<a[i]<<" ";
    return 0;
}
