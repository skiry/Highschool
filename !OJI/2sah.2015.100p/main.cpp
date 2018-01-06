#include <fstream>

using namespace std;
ifstream f("2sah.in");
ofstream g("2sah.out");
#define MOD 100003
long long p,n,k,i,v[4][4],rez[4][4],interm[10];
int putere(long long a,int b)
{
    int rez=1;
    for(;b;b>>=1)
    {
        if(b&1)
        {
            rez=((rez%MOD)*(a%MOD))%MOD;
        }
        a=((a%MOD)*(a%MOD))%MOD;
    }
    return rez;
}
void tribonacci(int a)
{
    for(;a;a>>=1)
    {
        if(a&1)
        {
            int contor=0;
            for(int j=1;j<=3;j++)
            {
                for(int h=1;h<=3;h++)
                {
                    ++contor;
                    for(int l=1;l<=3;l++)
                        interm[contor]+=(rez[j][l]%MOD*v[l][h]%MOD)%MOD;
                }
            }
            for(int j=1,contor=0;j<=3;j++)
                for(int h=1;h<=3;h++)
                    rez[j][h]=interm[++contor]%MOD,interm[contor]=0;
        }
        int contor=0;
        for(int j=1;j<=3;j++)
        {
            for(int h=1;h<=3;h++)
            {
                ++contor;
                for(int l=1;l<=3;l++)
                    interm[contor]+=((v[j][l]%MOD)*(v[l][h]%MOD))%MOD;
            }
        }
        for(int j=1,contor=0;j<=3;j++)
            for(int h=1;h<=3;h++)
                v[j][h]=interm[++contor]%MOD,interm[contor]=0;;

    }
}
int main()
{
    f>>p;
    f>>n>>k;
    if(p==1) g<<putere(3,k-1);
    else if(p==2)
    {
        int nr=n-k+1;
        if(nr==1) g<<"1";
        if(nr==2) g<<"2";
        if(nr==3) g<<"4";
        if(nr>3)
        {
            v[1][1]=0;  v[1][2]=0;  v[1][3]=1;
            v[2][1]=1;  v[2][2]=0;  v[2][3]=1;
            v[3][1]=0;  v[3][2]=1;  v[3][3]=1;
            rez[1][1]=1;  rez[1][2]=0;  rez[1][3]=0;
            rez[2][1]=0;  rez[2][2]=1;  rez[2][3]=0;
            rez[3][1]=0;  rez[2][3]=0;  rez[3][3]=1;
            tribonacci(nr-3);
            g<<(rez[1][3]%MOD+2*rez[2][3]%MOD+4*rez[3][3]%MOD)%MOD<<endl;
        }
    }
    return 0;
}
