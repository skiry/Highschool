#include <fstream>

using namespace std;
ifstream f("case1.in");
ofstream g("case1.out");
int n,i,a[55],s1,s2,s3,nr=1000,j;
int main()
{f>>n;
for(i=1;i<=n;i++)
    f>>a[i];

for(i=1;i<=n;i++) if(a[i]/nr%10==1) s1++;
else if(a[i]/nr%10==2) s2++;
else if(a[i]/nr%10==3) s3++;
nr/=10;
    g<<s1<<endl;
    g<<s2<<endl;
    g<<s3<<endl;
    s1=0;
    s2=0;
    s3=0;

     for(i=1;i<=n;i++) s1+=a[i]/100%10;
     for(i=1;i<=n;i++) s2+=a[i]/10%10;
    for(i=1;i<=n;i++) s3+=a[i]%10;

g<<s1<<endl;
g<<s2<<endl;
g<<s3;
    return 0;
}
