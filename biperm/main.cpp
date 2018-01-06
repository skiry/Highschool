#include <fstream>

using namespace std;
ifstream f("biperm.in");
ofstream g("biperm.out");
int a[3][100001],i,j,viz[10001],s[10001],nr,n,x;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[1][i],s[i]=a[1][i];
    for(i=1;i<=n;i++)
        f>>a[2][i],s[i]+=a[2][i];
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(a[1][i]==a[1][j])
                {
                    if(s[i]>=s[j]&&!viz[i]) x=a[1][i],a[1][i]=a[2][i],a[2][i]=x,viz[i]=1,nr++,i--;
                        else if(s[i]<s[j]&&!viz[j]) x=a[1][j],a[1][j]=a[2][j],a[2][j]=x,viz[j]=1,nr++,i--;
                            else if(s[i]>=s[j]&&viz[i]) x=a[1][j],a[1][j]=a[2][j],a[2][j]=x,viz[j]=1,nr++;
                                else if(s[i]<s[j]&&viz[j]) x=a[1][i],a[1][i]=a[2][i],a[2][i]=x,viz[i]=1,nr++;
                }
                for(i=1;i<=n;i++) viz[i]=0;
             for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(a[1][i]==a[1][j])
                {
                    if(s[i]>=s[j]&&!viz[i]) x=a[1][i],a[1][i]=a[2][i],a[2][i]=x,viz[i]=1,nr++,i--;
                        else if(s[i]<s[j]&&!viz[j]) x=a[1][j],a[1][j]=a[2][j],a[2][j]=x,viz[j]=1,nr++,i--;
                            else if(s[i]>=s[j]&&viz[i]) x=a[1][j],a[1][j]=a[2][j],a[2][j]=x,viz[j]=1,nr++;
                                else if(s[i]<s[j]&&viz[j]) x=a[1][i],a[1][i]=a[2][i],a[2][i]=x,viz[i]=1,nr++;
                }
    g<<"2 "<<nr<<endl;
    for(i=1;i<=n;i++)
        g<<a[1][i]<<" ";
    g<<endl;
    for(i=1;i<=n;i++)
        g<<a[2][i]<<" ";

    return 0;
}
