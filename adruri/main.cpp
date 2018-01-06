#include <fstream>

using namespace std;
ifstream f("daruri.in");
ofstream g("daruri.out");
int n,h,q,m;
int main()
{f>>n>>m;
h=n;q=m;
    while(n!=m)
    {if(n>m) n-=m;
    else m-=n;
    }
    if(n!=1)
    {g<<n;g<<endl;
    g<<h/n<<" "<<q/m;}
    else {g<<"0"<<endl;g<<"0 0";}
    return 0;
}
