#include <fstream>
#include <string.h>
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int t,n,i,k;
char a[1000],b[1000];
int main()
{
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cin.get();
        cin>>n;
        cin.get();
        cin>>a;
        int ok=1;
        for(i=2;i<=n;i++)
        {
            cin>>b;
            if(!strcmp(a,"cookie")&&strcmp(b,"milk")) ok=0;
            strcpy(a,b);
        }
        if(!strcmp(a,"cookie")) ok=0;
        if(ok) cout<<"YES";
        else cout<<"NO";
        if(k!=t) cout<<'\n';
    }
    return 0;
}
