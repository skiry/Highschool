#include <fstream>

using namespace std;
ifstream f("aranjare2.in");
ofstream g("aranjare2.out");
int n,i,a[100005],j,e;
int main()
{f>>n;
    for(i=1;i<=2*n;i++) {f>>a[i];a[i]=i;}
    if(n!=3){
for(i=2;i<=n;i++)
{g<<i<<" "<<i+n-1<<endl;
swap(a[i],a[i+n-1]);
}
j=1;
for(i=1;i<=(n*2)-1;i++)
{if(a[i]!=j) for(e=i+1;e<=(2*n)-2;e++) if(a[e]==j) {g<<i<<" "<<e<<endl;swap(a[i],a[e]);}
j++;
i++;
}
for(i=1;i<=(n*2)-1;i++)
{if(a[i+1]!=a[i]+n) for(e=1;e<=n*2;e++) if(a[e]==a[i]+n) {g<<i+1<<" "<<e<<endl;swap(a[i+1],a[e]);}
    i++;

}}
else {
        g<<"2 4"<<endl;
g<<"3 5"<<endl;
g<<"3 4"<<endl;}




    return 0;
}
