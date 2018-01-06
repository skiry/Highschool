#include <iostream>
#include <algorithm>
using namespace std;
int n,i,j,a,numar,valll;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        int unu=-1,zero=-1,val=1,numar;
        if(a|0) numar=1;
        for(j=0;j<32&&numar<a;j++)
        {
            if(a&(1<<j))
            {
                if(unu<0) unu=j;
                if(j) numar+=val;
            }
            else zero=max(zero,j);
            val*=2;
        }
        if(unu<zero&&unu!=-1&&zero!=-1) valll=1<<unu,a^=valll,valll=0,valll=1<<zero,a^=valll;
        cout<<a<<" ";
    }
    return 0;
}
