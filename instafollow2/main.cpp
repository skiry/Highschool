#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
char a[500][500],b[500][500];
int i,j,n,m,ok;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
    f>>m;
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
    {
        ok=0;
        for(j=1;j<=m;j++)
            if(strcmp(a[i],b[j])==0) ok=1;
        if(!ok) g<<"Ti-a dat unfollow muistul de : "<<a[i]<<". Pozitia : "<<i<<endl;
    }
    for(i=1;i<=m;i++)
    {
        ok=0;
        for(j=1;j<=n;j++)
            if(strcmp(b[i],a[j])==0) ok=1;
        if(!ok) g<<"Ti-a dat follow : "<<b[i]<<". Pozitia : "<<i<<endl;
    }///verifica sa nu isi fi schimbat numele de pe instagram
    return 0;
}
