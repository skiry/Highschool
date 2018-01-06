#include <fstream>

using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
long i,j,k,n,m,minim;
unsigned long long r,a[301][301],val;
void intoarcere(int i,int nr)
{
    int k=i,l=i;
    for(int h=1;h<=nr;h++)
    {
        int o;
        long long nri=a[k][l];
        for(int o=l;o<=n-l;o++)
            a[k][o]=a[k][o+1];
        o++;
        k=o;
        for(int o=l;o<=m-l;o++)
            a[o][k]=a[o+1][k];
        o++;
        while(k>l)
        {
            a[o][k]=a[o][k-1];
            k--;
        }
        k--;
        while(o!=l+1)
        {
            a[o][k]=a[o-1][k];
            o--;
        }
        a[i+1][i]=nri;
    }
}
int main() {
    cin>>n>>m;
    cin>>r;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>a[i][j];
    val=2*(m+n-2);
    minim=n;
    if(m<minim) minim=m;
    cout<<minim;
    for(i=1;i<=minim/2;i++)
    {
        int nr;
        nr=r%val;
        cout<<nr<<" ";
        if(nr)
            intoarcere(i,nr);
        val-=8;
    }
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                cout<<a[i][j]<<" ";
                    cout<<endl;
        }
    return 0;
}
