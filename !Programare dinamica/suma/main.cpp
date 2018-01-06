#include <fstream>
#include <string.h>
using namespace std;
ifstream f("suma.in");
ofstream g("suma.out");
int n,a[100],i,j,s[100][100],m;
char b[100],c[100];
int main()
{
    f>>n;
    f.get();
    for(i=1;i<=n;i++)
        f>>b,strcat(c,b);
    m=strlen(c);
    for(i=1;i<=m;i++)
        a[i]=c[i-1]-'0';

    for(i=1;i<=4;i++)
        for(j=0;j<=n;j++)
            s[i][j]=-1;
    s[0][0]=0;
    s[1][1]=a[1];
    s[2][1]=a[1]*10+a[2];
    if(a[2]) s[2][2]=a[1]+a[2];
    s[3][1]=a[1]*100+a[2]*10+a[3];
    if(a[2]) s[3][2]=a[1]+a[2]*10+a[3];
    if(a[3]&&s[3][2]<a[1]*10+a[2]+a[3])
            s[3][2]=a[1]*10+a[2]+a[3];
    if(a[2]&&a[3])
            s[3][3]=a[1]+a[2]+a[3];

    for(i=3;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i])
                s[i][j]=s[i-1][j-1]+a[i];
            if(a[i-1]&&s[i-2][j-1]+a[i-1]*10+a[i]>s[i][j])
                s[i][j]=s[i-2][j-1]+a[i-1]*10+a[i];
            if(a[i-2]&&s[i-3][j-1]+a[i-2]*100+a[i-1]*10+a[i]>s[i][j])
                s[i][j]=s[i-3][j-1]+a[i-2]*100+a[i-1]*10+a[i];
        }
    }
    g<<s[m][n];


    return 0;
}
