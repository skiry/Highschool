#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,i,j,p,s,k,s1,sum;
int main()
{
    f>>t;
    for(int u=1;u<=t;u++)
    {
        g<<"Case #"<<u<<": ";
        f>>j>>p>>s>>k;
        s1=s;
        sum=0;
        //if(j*p*s<k)
        if(k>=s)
            {
                g<<j*p*s<<endl;
                for(int o=1;o<=j;o++)
                    for(int l=1;l<=p;l++)
                        for(int d=1;d<=s;d++)
                            g<<o<<" "<<l<<" "<<d<<endl;
            }
        else
        {
            for(i=1;i<=j;i++)
            {
                if(s1>1)
                    sum+=p*k;
                else sum+=p;
                s1-=k;
            }
            g<<sum<<endl;
            if(k!=1)
            {
                int b=-1;
                for(int o=1;o<=j;o++)
                {
                    b=o*k-1;
                    for(int l=1;l<=p;l++)
                    {
                        if((l-1)%k==0&&(l-1)!=0) b+=k;
                        for(int d=b;d<=b+k-1;d++)
                            if(b+k-1<=s)
                            g<<o<<" "<<l<<" "<<d<<endl;
                        //if(l>k) b-=2;
                    }
                }
            }
            else
            {
                int b=-1;
                for(int o=1;o<=j;o++)
                {
                    b+=2;
                    for(int l=1;l<=p;l++)
                    {
                        if((l-1)%k==0&&(l-1)!=0) b+=k;
                        for(int d=b;d<=b+k-1;d++)
                            if(b+k-1<=s)
                            g<<o<<" "<<l<<" "<<d<<endl;
                        //if(l>k) b-=2;
                    }
                }
            }
        }
    }
    return 0;
}
