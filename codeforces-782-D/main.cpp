#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
//ifstream cin("date.in");
//ofstream cout("date.out");
int n,i,j,ok;
char c1[1001][31],c2[1001][31];
deque <char> q;
int main()
{
    cin>>n;
    for(i=1;i<=n&&!ok;i++)
    {
        cin>>c1[i]>>c2[i];
        for(j=1;j<i;j++)
            if(strcmp(c1[j],c1[i])==0&&c2[j][0]==c2[i][0]) ok=1;
    }
    if(ok) cout<<"NO";
    else{cout<<"YES"<<'\n';for(i=1;i<=n;i++)
         cout<<c1[i][0]<<c1[i][1]<<c2[i][0]<<'\n';

    }

    return 0;
}
