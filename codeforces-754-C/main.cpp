#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,n,m,i,j,k;
char a[101][11],chat[101][101],*p,rez[101][101];
int viz[101],c[101][101];
int main()
{
    f>>t;
    for(k=1;k<=t;k++)
    {
        f>>n;
        for(i=1;i<=n;i++)
            f>>a[i];
        f>>m;
        f.get();
        for(j=1;j<=m;j++)
            {
                f.getline(chat[j],100);
                strcpy(rez[j],chat[j]);
            }
        for(i=1;i<=m;i++)
            if(chat[i][0]!='?')
                {
                    p=strtok(chat[i],":");
                    for(j=1;j<=n;j++)
                        if(strcmp(p,a[j])==0)
                        {
                            viz[i]=j;
                            for(int r=1;r<=n;r++)
                                if(r!=j) c[i][r]=1;
                        }
                }
             else
                {
                    p=strtok(chat[i],",. !?");
                    while(p)
                    {
                        for(j=1;j<=n;j++)
                            if(strcmp(p,a[j])==0)
                                c[i][j]=1;
                        p=strtok(NULL,",. !?");
                    }
                    int ok=1;
                    for(int r=1;r<=n;r++)
                    {
                        if(!c[i][r]&&ok) viz[i]=r,ok=0;
                        else if(!c[i][r]&&!ok) viz[i]=0;
                    }
                }

            for(i=1;i<=5;i++)
            {
                if(viz[1]) c[2][viz[1]]=1;
                else
                {
                    int ok=1;
                        for(int r=1;r<=n;r++)
                            {
                                if(!c[1][r]&&ok) viz[1]=r,ok=0;
                                else if(!c[1][r]&&!ok) viz[1]=0;
                            }
                }
                if(viz[m]) c[m-1][viz[m]]=1;
                else
                {
                    int ok=1;
                        for(int r=1;r<=n;r++)
                            {
                                if(!c[m][r]&&ok) viz[m]=r,ok=0;
                                else if(!c[m][r]&&!ok) viz[m]=0;
                            }
                }
                for(j=2;j<m;j++)
                    if(viz[j]) c[j-1][viz[j]]=1,c[j+1][viz[j]]=1;
                else
                    {
                        int ok=1;
                        for(int r=1;r<=n;r++)
                            {
                                if(!c[j][r]&&ok) viz[j]=r,ok=0;
                                else if(!c[j][r]&&!ok) viz[j]=0;
                            }
                    }
            }
    int ok=1;
    for(i=1;i<=m;i++)
       if(!viz[i]) ok=0;
    if(!ok) g<<"Impossible"<<endl;
    else
    {
        for(i=1;i<=m;i++)
        {
            int ok=1;
            g<<a[viz[i]];
            for(j=0;j<strlen(rez[i]);j++)
                {
                    if(!ok) g<<rez[i][j];
                    if(rez[i][j]==':') ok=0,g<<":";
                }
            g<<endl;
        }
    }
     for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        c[i][j]=0;
    }

    return 0;
}
