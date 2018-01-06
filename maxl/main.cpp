#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("maxl.in");
ofstream g("maxl.out");
int n,v,c,i,q,maxim;
vector <int> a;
int main()
{
    f>>n;
    for(i=1;i<=(1<<n);i++)
        f>>v,a.push_back(v);
    f>>q;
    for(i=1;i<=q;i++)
        {
            f>>v>>c;
            maxim=*max_element(a.begin()+v,a.begin()+c);
            g<<maxim<<endl;
        }
    return 0;
}
