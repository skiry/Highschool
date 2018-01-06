#include <fstream>
#include <string.h>
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
char c[101];
int s,s1,s2,linie,coloana,lin1,lin2,col1,col2;
struct nod
{
    int st,dr;
}rez[101];
int main()
{
    char alf[]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
    for(int i=0;i<10;i++) rez[alf[i]-'A'].st=1,rez[alf[i]-'A'].dr=i+1;
    for(int i=0;i<10;i++) rez[alf[i+10]-'A'].st=2,rez[alf[i+10]-'A'].dr=i+1;
    for(int i=0;i<7;i++) rez[alf[i+20]-'A'].st=3,rez[alf[i+20]-'A'].dr=i+1;
    cin.getline(c,100);
    lin1=2;
    col1=4;
    lin2=2;
    col2=7;
    for(int i=0;i<strlen(c);i++)
    {
        s1=0;s2=0;
            linie=rez[c[i]-'A'].st;
            coloana=rez[c[i]-'A'].dr;
            s1=max(lin1,linie)-min(lin1,linie)+max(col1,coloana)-min(col1,coloana);
            s2=max(lin2,linie)-min(lin2,linie)+max(col2,coloana)-min(col2,coloana);
            if(s1<s2)
            {
                lin1=linie;
                col1=coloana;
                s+=s1;
            }
            else
            {
                lin2=linie;
                col2=coloana;
                s+=s2;
            }
    }
    cout<<s;
    return 0;
}
