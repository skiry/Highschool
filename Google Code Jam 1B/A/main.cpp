#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,i,a[30],v[400],l;
char c[2001];

int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>c;
        for(int u=0;u<strlen(c);u++)
        {
            a[int(c[u])-64]++;
        }
        l=1;
        //for(int u=1;u<=26;u++) g<<a[u]<<" ";g<<endl;
        g<<"Case #"<<i<<": ";
        while(a[26])
        {
            v[l]=0;
            l++;
            a['Z'-64]--;
            a['E'-64]--;
            a['R'-64]--;
            a['O'-64]--;
        }
        while(a['S'-64] && a['I'-64] && a['X'-64])
        {
            v[l]=6;
            l++;
            a['S'-64]--;
            a['I'-64]--;
            a['X'-64]--;
        }
        while(a['W'-64])
        {
            v[l]=2;
            l++;
            a['W'-64]--;
            a['T'-64]--;
            a['O'-64]--;
        }
        while(a['E'-64] && a['I'-64] && a['G'-64] && a['H'-64] && a['T'-64])
        {
            v[l]=8;
            l++;
            a['E'-64]--;
            a['I'-64]--;
            a['G'-64]--;
            a['H'-64]--;
            a['T'-64]--;
        }

        while(a['F'-64] && a['O'-64] && a['U'-64] && a['R'-64])
        {
            v[l]=4;
            l++;
            a['F'-64]--;
            a['O'-64]--;
            a['U'-64]--;
            a['R'-64]--;
        }
        while(a['S'-64] && a['E'-64] && a['V'-64] && a['N'-64])
        {
            v[l]=7;
            l++;
            a['S'-64]--;
            a['E'-64]--;
            a['E'-64]--;
            a['V'-64]--;
            a['N'-64]--;
        }
        while(a['F'-64] && a['I'-64] && a['V'-64] && a['E'-64])
        {
            v[l]=5;
            l++;
            a['F'-64]--;
            a['I'-64]--;
            a['V'-64]--;
            a['E'-64]--;
        }


        while(a['T'-64] && a['H'-64] && a['E'-64] && a['R'-64])
        {
            v[l]=3;
            l++;
            a['T'-64]--;
            a['H'-64]--;
            a['E'-64]--;
            a['E'-64]--;
            a['R'-64]--;
        }
        while(a['N'-64] && a['I'-64] && a['E'-64])
        {
            v[l]=9;
            l++;
            a['I'-64]--;
            a['N'-64]--;
            a['E'-64]--;
            a['N'-64]--;
        }
        while(a['O'-64] && a['N'-64] && a['E'-64])
        {
            v[l]=1;
            l++;
            a['O'-64]--;
            a['N'-64]--;
            a['E'-64]--;
        }

        for(int u=1;u<l-1;u++)
            for(int j=u+1;j<l;j++)
                if(v[u]>v[j]) swap (v[u],v[j]);
        for(int u=1;u<l;u++) g<<v[u];
        //for(int u=1;u<=26;u++) if(a[u]>0) g<<"ESTI UN PROST !!!!!!!!!"<<a[u]<<" "<<(char)(u+64);
        //for(int u=1;u<=26;u++) a[u]=0;
        g<<endl;
    }
    return 0;
}
