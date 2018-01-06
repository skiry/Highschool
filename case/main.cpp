#include <fstream>

using namespace std;
ifstream f("case.in");
ofstream g("case.out");
int n,i,j;
int main()
{
    f>>n;
    j=5;
    for(int ok=1;ok<=n;i++)
    {
        j++;
        for(int k=2;k<j;k++)
            if(k*(k-1)/2==j*(j+1)/2-k*(k+1)/2) ok++,g<<j<<" "<<k<<endl;
    }
    return 0;
}
