#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,n,i,a[30],s;
char c;
int main()
{
   f>>t;
   for(int u=1;u<=t;u++)
   {
       s=0;
       g<<"Case #"<<u<<": ";
       f>>n;
       for(i=1;i<=n;i++)
        f>>a[i],s+=a[i];
       while(s>0)
       {
           int m=0,l=0,m1=0,l1=0;
           if(s!=3)
           {
               for(i=1;i<=n;i++)
                if(a[i]>m) m=a[i],l=i;
               for(i=1;i<=n;i++)
                if(a[i]>m1&&i!=l) m1=a[i],l1=i;
            c=l+'A'-1;
            a[l]--;
            g<<c;
            if(m1!=0)
                {
                    c=l1+'A'-1;
                    a[l1]--;
                    g<<c<<" ";
                }
            s-=2;
           }
           else
           {
            for(i=1;i<=n;i++)
                if(a[i]>m) m=a[i],l=i;
            c=l+'A'-1;
            a[l]--;
            g<<c<<" ";
            s--;
           }
            //g<<l<<" "<<l1<<endl;
            //g<<m<<" "<<m1<<endl;


       }
       g<<endl;
   }
    return 0;
}
