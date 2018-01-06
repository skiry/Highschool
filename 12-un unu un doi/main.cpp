#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int c[1000],c1[1000],nr,val,n,p,u,s,d,i;
int main()
{
    f>>n;
    p=u=s=d=0;
    g<<"1 ";
    c1[1]=1;
    c1[2]=1;
    for(i=1;i<=n;i++)
    {
        if(i&2==0)
        {
            while(s<=d)
            {
                nr=1;
                if(s!=d)
                {
                    while(c1[s+1]==c1[s]) nr++,c1[s]=-1,s++;
                    u++;
                    c[u]=nr;
                    u++;
                    c[u]=c1[s];
                }
                else if(s==d&&c1[s-1]==c1[s]) c1[s]=-1,s=1,d=0;
                else if(s==d&&c1[s-1]!=c1[s]) u++,c[u]=1,u++,c[u]=c1[s],c1[s]=-1,s=1,d=0;
                }
                for(int k=1;k<=u;k++) g<<c[k];
                g<<" ";
        }
        else if(i%2)
        {
            while(p<=u)
            {
                nr=1;
                if(p!=u)
                {
                    while(c[p+1]==c[p]) nr++,c[p]=-1,p++;
                    d++;
                    c1[d]=nr;
                    d++;
                    c1[d]=c[p];
                }
                else if(p==u&&c[p-1]==c[p]) c[p]=-1,p=1,u=0;
                else if(p==u&&c[p-1]!=c[p]) d++,c1[d]=1,d++,c1[d]=c[p],c[p]=-1,p=1,u=0;
            }
            for(int k=1;k<=d;k++) g<<c1[k];
            g<<" ";
        }
    }
    return 0;
}
