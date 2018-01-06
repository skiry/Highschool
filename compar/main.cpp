#include <fstream>

using namespace std;
ifstream f("compar.in");
ofstream g("compar.out");
int nr,i=1,m,n=1;
char a[100005];
int main()
{while(f>>a[i]) {nr++;i++;}
g<<nr+1;
g<<'\n';
m=nr+1;
for(i=1;i<=nr;i++) if(a[i]=='>') {g<<m<<" ";m--;}
else if (a[i]=='<') {g<<n<<" ";n++;}
if(a[nr]=='>') g<<n;
else if (a[nr]=='<') g<<m;


    return 0;
}
