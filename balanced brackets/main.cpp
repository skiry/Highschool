#include <fstream>
#include <string.h>
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int queries,i,a[1001],j,ok;
char c[1001];
int main()
{
    cin>>queries;
    for(int query=1;query<=queries;query++)
    {
        ok=0;
        cin.get();
        cin.get(c,1001);
        int prim=0;
        for(i=0;i<strlen(c);i++)
        if(c[i]=='{') a[++prim]=3;
        else if(c[i]=='[') a[++prim]=2;
        else if(c[i]=='(') a[++prim]=1;
        else if(c[i]=='}') if(a[prim]==3) prim--;
        else {
            ok=1;
            break;
        }
        else if(c[i]==']') if(a[prim]==2) prim--;
        else {
            ok=1;
            break;
        }
        else if(c[i]==')') if(a[prim]==1) prim--;
        else {
            ok=1;
            break;
        }


        if(!ok&&prim==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for(i=0;i<=501;i++) a[i]=0;
    }
    return 0;
}
