#include <fstream>
#include <string.h>
using namespace std;
ifstream f("gray.in");
ofstream g("gray.out");
char c,x[1230000];
long a[1230000],numar;
int n,nr,i,j;
void divide(long a[1230000])
{
    unsigned long R=0;

  for (int i=a[0];i;i--)
    {
        a[i]=(R=10*R+a[i])/32;
        R%=32;
    }
  while (!a[a[0]] && a[0]>1) a[0]--;
}
void inmultire(long a[1230000],int inmultit)
{
    unsigned long R=0;
   for(int i=1;i<=a[0];i++)
   {
       a[i]=a[i]*inmultit+R;
       R=a[i]/10;
       a[i]%=10;
   }
   while(R)
   {
       a[++a[0]]=R%10;
       R/=10;
   }

}
int main()
{
    f>>c>>n;
    f.get();
    f.get(x,12300000);
    a[0]=strlen(x);
    for(i=strlen(x)-1,j=1;i>=0;i--,j++)
        a[j]=x[i]-'0';

    while(a[0]>6) divide(a),nr++;
    for(i=a[0];i;i--)
        numar=numar*10+a[i];
    n=0;
    if(c=='C')
       n=numar^(numar>>1);
    else if(c=='D')
        while(numar)
        {
            n^=numar;
            numar>>=1;
        }
    if(nr==0) g<<n;
    else
    {
        i=1;
        while(n)
        {
            a[i++]=n%10;
            n/=10;
        }
        a[0]=i-1;
        while(nr)
            inmultire(a,32),nr--;
        for(i=a[0];i;i--)
            g<<a[i];
    }
    return 0;
}
