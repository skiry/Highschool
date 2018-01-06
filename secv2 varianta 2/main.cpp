#include <fstream>
#include <vector>
using namespace std;
ifstream f("secv2.in");
ofstream g("secv2.out");
int n,i,k,el,suma,poz,fin,maxim;
vector <int> s;
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++)
    {
        f>>el;
        s.push_back(el);
        if(i>1) s[i-1]+=s[i-2];
        if(s[i-1]>maxim) maxim=s[i-1],fin=i;
    }
    suma=s[fin-1];
    maxim=0;
    for(i=fin-2;i>=0;i--)
    {
        suma+=s[i]-s[i-1];
        if(suma>maxim) maxim=suma,poz=i+1;
    }
    g<<poz<<" "<<fin<<" "<<maxim;
    return 0;
}
