#include <fstream>
#include <vector>
using namespace std;
ifstream f("expand.in");
ofstream g("expand.out");
int n,i,j;
char lit,cuvant[16],l,c[16];
vector <string> a[30];
void backt(int nr,int maxim)
{

}
int main()
{
    f>>lit>>cuvant;
    f>>n;
    for(i=1;i<=n;i++)
        f>>l>>c,a[l-'a'].push_back(c);
    backt(1,strlen(cuvant));
    return 0;
}
