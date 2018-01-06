#include <fstream>
#include <string.h>
using namespace std;
char s[10001];
int t,n,k,i,j,ok,nr,contor,p;
int main()
{
    cin>>t;
    cin.get();
    for(j=1;j<=t;j++)
    {
        cin.getline(s,10001);
        ok=0;
        nr=0;
        k=0;
        contor=1;
        p=1;
        while(s[strlen(s)-contor]>='0'&&s[strlen(s)-contor]<='9')
        {
            k+=p*(s[strlen(s)-contor]-'0');
            p*=10;
            contor++;
        }
        for(i=0;i<strlen(s)-k-1;i++)
        {
            if(s[i]=='-')
            {
                nr++;
                for(int l=i;l<=i+k-1;l++)
                    if(s[l]=='+') s[l]+=2;
                else s[l]-=2;
            }
        }
        for(i=strlen(s)-k-1;i<strlen(s)-2;i++) if(s[i]=='-') ok=1;
        cout<<"Case #"<<j<<": ";
        if(ok) cout<<"IMPOSSIBLE";
        else cout<<nr;
        cout<<'\n';
    }
    return 0;
}
