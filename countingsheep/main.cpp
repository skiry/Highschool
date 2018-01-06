#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,viz[11],nr,i;
long long a,b,c;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        nr=0;
        f>>a;
        c=a;
        b=a;
        if(a)
            {
                while(nr!=10)
                    {
                        while(b)
                            {
                                if(!viz[b%10]) viz[b%10]=1,nr++;
                                b/=10;
                                if(nr==10) break;
                            }
                        if(nr==10) g<<"Case #"<<i<<": "<<a<<'\n';
                        a+=c;
                        b=a;
                    }
            }
        else
            {
                g<<"Case #"<<i<<": INSOMNIA"<<'\n';
            }
        for(int j=0;j<=9;j++) viz[j]=0;
    }
    return 0;
}
