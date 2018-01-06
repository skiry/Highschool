#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
char a[100],b[100],nume[100][100];
int n,i,j,nr=0;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a;
        f>>b;
        if(b[strlen(b)-9]=='g'&&b[strlen(b)-8]=='m'&&b[strlen(b)-7]=='a'&&b[strlen(b)-6]=='i'&&b[strlen(b)-5]=='l'&&b[strlen(b)-10]=='@')
            nr++,strcpy(nume[nr],a);
    }
    for(i=1;i<nr;i++)
        for(j=i+1;j<=nr;j++)
            if(nume[i][0]>nume[j][0]) swap(nume[i],nume[j]);
            else if(nume[i][0]==nume[j][0])
            {
                int k=0;
                while(nume[i][k]==nume[j][k])
                {
                    k++;
                    if(nume[i][k]>nume[j][k])
                    {
                        swap(nume[i],nume[j]);
                        break;
                    }

                }
            }
    for(i=1;i<=nr;i++) g<<nume[i]<<endl;
    char a[10],*p;
    strcpy(a,"alexandru");
    g<<endl<<endl<<a<<endl;
    p=a;
    strcpy(p+4,p+6);
    g<<a;
    return 0;
}
