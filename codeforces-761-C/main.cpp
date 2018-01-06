#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,lit=999,cif=999,semn=999,i,j;
char a[51][51];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
        if(strchr("1234567890",a[i][0])) cif=0;
        if(strchr("qwertyuiopasdfghjklzxcvbnm",a[i][0])) lit=0;
        if(strchr("*#&",a[i][0])) semn=0;
        for(j=1;j<=strlen(a[i])&&(cif||semn||lit);j++)
                    if(j<cif&&strchr("1234567890",a[i][j])) cif=j;
                    else if(j<lit&&strchr("qwertyuiopasdfghjklzxcvbnm",a[i][j])) lit=j;
                    else if(j<semn&&strchr("*#&",a[i][j])) semn=j;
        for(j=strlen(a[i])-1&&(cif||semn||lit);j>1;j--)
                    if(strlen(a[i])-j<cif&&strchr("1234567890",a[i][j])) cif=strlen(a[i])-j;
                    else if(strlen(a[i])-j<lit&&strchr("qwertyuiopasdfghjklzxcvbnm",a[i][j])) lit=strlen(a[i])-j;
                    else if(strlen(a[i])-j<semn&&strchr("*#&",a[i][j])) semn=strlen(a[i])-j;
    }
    g<<cif+lit+semn;
    return 0;
}
