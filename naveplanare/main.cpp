#include <fstream>

using namespace std;
ifstream f("naveplanare.in");
ofstream g("naveplanare.out");
int n,k,i,j,ox[2001],oy[2001],nrlin,nrcol;
///ox[i] nr de pct de pe linia i
///oy[i] nr de pct de pe coloana i
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        if(!oy[x]) nrcol++;
        if(!ox[y]) nrlin++;
        oy[x]++;
        ox[y]++;
    }
    return 0;
}
