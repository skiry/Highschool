#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
///c=copy 1
///i=insert 2
///d=delete 3
///r=replace 4
///t=twiddle 5
///k=kill 6
int c,i,dt,k,t,r,j,p,q,d[30][30],op[30][30],n,m;
char a[100],b[100];
int main()
{
    f>>c>>dt>>i>>r>>t>>k;
    f.get();
    f>>a>>b;
    n=strlen(a);
    m=strlen(b);
    for(i=0;i<n;i++)
    {
        d[i][m]=min(k,(n-i)*dt);
        if(d[i][m]==k) op[i][m]=6;
            else op[i][m]=3;
    }
    for(i=0;i<m;i++) d[n][i]=(m-i)*i,op[n][i]=2;
    d[n][m]=0;
    for(i=n-1;i>=0;i--)
        for(j=m-1;j>=0;j--)
    {
        d[i][j]=k+d[m][j];op[i][j]=6;
        if(d[i][j]>c+d[i+1][j+1])
            if(a[i]==b[j]) d[i][j]=c+d[i+1][j+1],op[i][j]=1;
        if(d[i][j]>i+d[i][j+1]) d[i][j]=i+d[i][j+1],op[i][j]=2;
        if(d[i][j]>dt+d[i+1][j]) d[i][j]=dt+d[i+1][j],op[i][j]=3;
        if(d[i][j]>r+d[i+1][j+1]) d[i][j]=r+d[i+1][j+1],op[i][j]=4;
        if(i<n-1&&j<m-1&&a[i+1]==b[j]&&a[i]==b[j+1])
            if(d[i][j]>t+d[i+2][i+2]) d[i][j]=t+d[i+2][j+2];
    }
    g<<d[0][0]<<endl;
    g<<"Operatii efectuate : "<<endl;
    i=j=0;
    while(i<n||j<m)
        if(op[i][j]==1) {g<<"COPY"<<endl;i++;j++;}
        else if(op[i][j]==2) {g<<"INSERT"<<endl;j++;}
        else if(op[i][j]==3) {g<<"DELETE"<<endl;i++;}
        else if(op[i][j]==4) {g<<"REPLACE"<<endl;i++;j++;}
        else if(op[i][j]==5) {g<<"TWIDDLE"<<endl;i+=2;j+=2;}
        else if(op[i][j]==6) {g<<"KILL"<<endl;j=m;}
    return 0;
}
