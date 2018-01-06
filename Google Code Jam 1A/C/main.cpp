#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,n,u,a[1001],b[1001],nr,i,j,k,ok1,ok,nr1;
int main()
{
    f>>t;
    for(u = 1; u <= t ; u++)
    {
        f>>n;
        for(i=1;i<=n;i++)
            f>>a[i];
        b[1]=1;
        b[2]=a[1];
        j=b[1];
        k=b[2];
        nr=2;
        nr1=nr;
        ok=1;
        while(ok)
        {
            ok1=1;
            for(i=1;i<=nr;i++)
                if(b[i]==a[k]) ok1=0;
            if(ok1) nr++,b[nr]=a[k];
            k=a[a[k]];
            ok1=1;
            for(i=1;i<=n;i++)
                if(a[i]==j)
            {
                for(int l=1;l<=nr;l++)
                    if(b[l]==i) ok1=0;
                if(ok1) nr++,b[nr]=i;
                j=i;
            }
            if(nr==nr1) ok=0;
            nr1=nr;
        }
        g<<"Case #"<<u<<": "<<nr<<endl;
    }
    return 0;
}
