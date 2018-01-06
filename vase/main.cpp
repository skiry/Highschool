#include <fstream>
#include <string.h>
using namespace std;
ifstream f("vase.in");
ofstream g("vase.out");
int n,i,a[100001],b[100001];
long long s,x,s1;
char l;
int main()
{f>>n;
for(i=1;i<=n;i++) {f>>a[i]>>l; s+=a[i];
                    if(l=='S') b[i]=1;
                          else b[i]=2;
                  }
f>>x;
s=s/2;
g<<s;g<<endl;
if(n==1) {g<<a[1]/2<<" S";g<<endl;g<<a[1]/2<<" D";}
else{
if(b[x]==1)
    {for(i=x+1;i<=n;i++) if(b[i]==1) s1+=a[i];
    if(s-s1>0)
        {
    g<<s-s1<<" S"<<endl;
    if((s-s1)<a[x]) g<<a[x]-(s-s1)<<" D";
    else if((s-s1)>a[x]) g<<-a[x]+(s-s1)<<" S";
    else if((s-s1)==a[x]) g<<"0 S";
        }
    else {g<<(s-s1)*(-1)<<" D"<<endl;
    g<<a[x]+((s-s1)*(-1))<<" D";
         }
    }
if(b[x]==2)
    {for(i=x+1;i<=n;i++) if(b[i]==2) s1+=a[i];
   if(s-s1>0)
        {
    g<<s-s1<<" D"<<endl;
    if((s-s1)<a[x]) g<<a[x]-(s-s1)<<" S";
    else if((s-s1)>a[x]) g<<-a[x]+(s-s1)<<" D";
    else if((s-s1)==a[x]) g<<"0 D";

        }
    else {g<<(s-s1)*(-1)<<" S"<<endl;
    g<<a[x]+((s-s1)*(-1))<<" S";
         }
    }}
/**  f>>l; g<<l;g<<endl;
  f>>l1; g<<l1;g<<endl;
  f.get();
  f.get(l2,100); g<<l2;g<<endl;
  g<<l2[18]<<" "<<strlen(l2);*/
    return 0;
}
