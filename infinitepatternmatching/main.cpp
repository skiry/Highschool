#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream f("infinitepatternmatching.in");
ofstream g("infinitepatternmatching.out");
char b[100],a[5000],v[600];
int ok=1,ok1,ok2,viz,pp,poz,ok3;
int main()
{
    f.get(b,1000);
    for(int i=1;i<=1000&&ok;i++)
    {
         pp=strlen(a)-strlen(b)+1;
         itoa(i,v,2);
         strcat(a,v);

        if(strlen(a)>=(strlen(b))&&!viz)
        {
            ok1=1;
            for(int j=0;j<=strlen(a)-strlen(b)&&ok1;j++)
                {
                    ok2=1;
                    for(int k=0;k<strlen(b)&&ok2;k++)
                        if(a[k+j]!=b[k]) ok2=0;

                    if(ok2) ok1=0,poz=j;
                }
            viz=1;
            if(ok1==0) ok=0,g<<poz+strlen(b);
        }

        if(strlen(a)>=(strlen(b))&&viz&&ok1)
        {
            ok1=1;
            for(int j=pp;j<strlen(a)-strlen(b)&&ok1;j++)
            {
                ok2=1;
                for(int k=0;k<strlen(b)&&ok2;k++)
                if(a[k+j]!=b[k]) ok2=0;
                if(ok2) ok1=0,poz=j;
            }
            if(ok1==0) ok=0,g<<poz+strlen(b);
        }


    }
    char z[10];
int q=5;
itoa(q,z,2);

q=atoi(z);
g<<q;
    return 0;
}
