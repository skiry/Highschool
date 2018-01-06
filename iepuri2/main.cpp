#include <fstream>
#include <vector>
using namespace std;
ifstream f("iepuri2.in");
ofstream g("iepuri2.out");
int n,k,b,c,i,j,in[101];
vector <int> a[101];
long df(int i,int morcov)
{
    long sum=0,aux,rez;
    for(int j=morcov;j<=k;j++) ///luam toate posibilitatile de morcovi
    {
        rez=1;
        for(int h=0;h<a[i].size();h++) ///luam vecinii lui i
            {
                aux=df(a[i][h],j+1); ///faceam parcurgere in adancime in vecinul lui i cu un morcov mai mult
                ///in aux am numarul de posibilitati de morcovi pe care subordonatul lui i ii poate manca
                rez*=aux; ///pe nivelul i nr total de posibilitati=nr de posib de la fiecare iepure inmultit
                rez%=30011;
            }
        if(!rez) break; ///daca nu mai poate lua niciun morcov, adica este 0, nu mai cresc numarul de morcovi, adica j, si ma opresc
        sum+=rez;
        sum%=30011;
    }
    return sum;
}
int main()
{
    f>>n>>k;
    for(i=1;i<n;i++)
    {
        f>>b>>c;
        a[b].push_back(c);
        in[c]++;
    }
    for(i=1;i<=n;i++)
        if(!in[i])
         g<<df(i,1)%30011;
    return 0;
}
