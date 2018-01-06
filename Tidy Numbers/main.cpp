#include <fstream>
#include <string.h>
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int t,i,j,poz,ok;
char s[20];
int main()
{
    cin>>t;
    cin.get();
    for(j=1;j<=t;j++)
    {
        cin.getline(s,20);
        cout<<"Case #"<<j<<": ";
        if(strlen(s)==1) cout<<s;
        else
        {
            ok=0;
            poz=0;
            for(i=0;i<strlen(s)-1&&!ok;i++)
                if(s[i]>s[i+1]) poz=i,ok=1;
            while(poz>0&&s[poz]==s[poz-1]) poz--;

            if(ok)
            {
                for(i=0;i<poz;i++) cout<<s[i]-'0';
            if(s[poz]-1-'0') cout<<s[poz]-1-'0';
            for(i=poz+1;i<strlen(s);i++) cout<<"9";
            }
            else cout<<s;
        }
        cout<<'\n';
    }
    return 0;
}
