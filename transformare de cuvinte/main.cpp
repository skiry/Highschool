#include <fstream>
#include <string.h>
///COPY, DELETE, INSERT, REPLACE, TWIDDLE, KILL
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,j,n,m,op[100][100],c[100][100],cost[100];
char a[100],b[100];
int main()
{
    f.get(a,100);
    m=strlen(a);
    f.get();
    f.get(b,100);
    n=strlen(b);
    for(i=0;i<6;i++) f>>cost[i];

    for(i=0;i<n;i++)
        c[m][i]=(n-i)*cost[2], op[m][i]=2;
    for(i=0;i<m;i++)
        {
            c[i][n]=(m-i)*cost[1], op[i][n]=1;
            if(cost[5]<=c[i][n]) c[i][n]=cost[5], op[i][n]=5;
        }
    c[n][m]=0;
    for(i=n-1;i>=0;i--)
        for(j=m-1;j>=0;j--)
    {
        c[i][j]=cost[5]+c[m][j]; op[i][j]=5;
            if(a[i]==b[j]&&c[i][j]>=cost[0]+c[i+1][j+1])
                c[i][j]=cost[0]+c[i+1][j+1], op[i][j]=0;
            if(c[i][j]>=cost[1]+c[i+1][j])
                c[i][j]=cost[1]+c[i+1][j], op[i][j]=1;
            if(c[i][j]>=cost[2]+c[i][j+1])
                c[i][j]=cost[2]+c[i][j+1], op[i][j]=2;
            if(c[i][j]>=cost[3]+c[i+1][j+1])
                c[i][j]=cost[3]+c[i+1][j+1], op[i][j]=3;
            if(i<m-1&&j<n-1&&a[i]==b[j+1]&&a[i+1]==b[j]&&c[i][j]>=cost[4]+c[i+2][j+2])
                c[i][j]=cost[4]+c[i+2][j+2], op[i][j]=4;
    }

    g<<c[0][0]<<endl;
    i=0;j=0;
    while(i<m||j<n)
    {
        if(op[i][j]==0) g<<"COPY",i++,j++;
        else if(op[i][j]==1) g<<"DELETE",i++;
        else if(op[i][j]==2) g<<"INSERT",j++;
        else if(op[i][j]==3) g<<"REPLACE",i++,j++;
        else if(op[i][j]==4) g<<"TWIDDLE",i+2,j+2;
        else if(op[i][j]==5) g<<"KILL",i=m;

        g<<endl;
    }
    return 0;
}
