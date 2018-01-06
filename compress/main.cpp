#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int n,m,i,j,k,rez,r,numar,valori[20],h;
char a,b,c;
int main()
{
    cin>>n>>m;
    for(i=0;i<=15;i++)
    {
        valori[i]+=i;
        valori[i]*=16;
        valori[i]+=i;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>c;cout<<"#";
            for(k=1;k<=3;k++)
            {
                cin>>a>>b;
                numar=0;
                if(strchr("0123456789",a)) numar+=a-'0';
                else numar+=a-'A'+10;
                numar*=16;
                if(strchr("0123456789",b)) numar+=b-'0';
                else numar+=b-'A'+10;

                for(h=0;valori[h]<numar;h++);
                    if(h){
                        if(valori[h]-numar<numar-valori[h-1])
                        {
                            if(h>=0&&h<=9) cout<<h;
                            else cout<<char(h+'A'-10);
                        }
                        else
                        {
                            h--;
                            if(h>=0&&h<=9) cout<<h;
                            else cout<<char(h+'A'-10);
                        }
                    }else cout<<0;
            }cout<<" ";
        }cout<<endl;
    }
    return 0;
}
