#include <fstream>

using namespace std;
ifstream f("bucket.in");
ofstream g("bucket.out");
long n,a[100001][3];
int m,i,sol[100000],nr,k,ok,ok1,val;
int main()
{
   f>>n>>m;
   for(i=1;i<=m;i++)
    f>>a[i][1]>>a[i][2];
    ok=1;
    for(i=1;i<m&&ok;i++)
        if(a[i][2]>a[i+1][2]) ok=0;
    if(ok==1) val=1;

    for(k=2;k<n;k++)
    {
        ok=1;
        ok1=0;
           for(i=1;i<m&&ok;i++)
   {
    if(((((a[i][1]-1)/k+1)>(a[i+1][1]-1)/k+1)) || ((((a[i][1]-1)/k+1) == (a[i+1][1]-1)/k+1)) && (((a[i][2]-1)/k+1)>(a[i+1][2]-1)/k+1))
                        ok=0;
    if((((a[i][1]-1)/k+1)==((a[i+1][1]-1)/k+1))&&(((a[i][2]-1)/k+1)==((a[i+1][2]-1)/k+1)))
                        ok1++;
   }
   if(ok1==m-1&&val==0) ok=0;
      if(ok||((ok1==m-1)&&val)) sol[++nr]=k;


    }
    g<<nr<<endl;
    for(i=1;i<=nr;i++)
        g<<sol[i]<<" ";
        g<<endl<<4+5%7*2<<" "<<5%7;
    return 0;
}
