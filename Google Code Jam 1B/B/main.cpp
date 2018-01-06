#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,u,i,a[19],b[19],x,y;
char c[19],j[19];
int main()
{
    f>>t;
     for(u=1;u<=t;u++)
    {
        f>>c>>j;
       if(c[0] == '?' && j[0] == '?')
          a[0]=0,b[0]=0,x=0,y=0;
       else if(c[0] == '?' && j[0] != '?')
            {
                a[0]=j[0]-'1'+1;
                b[0]=j[0]-'1'+1;
                x=j[0]-'1'+1;
                y=j[0]-'1'+1;
            }
        else if(j[0] == '?' && c[0] != '?')
        {
                a[0]=c[0]-'1'+1;
                b[0]=c[0]-'1'+1;
                x=c[0]-'1'+1;
                y=c[0]-'1'+1;
        }
        else if(j[0]!='?' && c[0]!='?')
        {
                a[0]=c[0]-'1'+1;
                b[0]=j[0]-'1'+1;
                x=c[0]-'1'+1;
                y=j[0]-'1'+1;

        }
         for(i=1;i<strlen(c);i++)
        {
            if(c[i] == '?' && j[i] == '?')
                {
                    if(x == y)
                        a[i]=0,b[i]=0,x=x*10+0,y=y*10+0;
                    else if(x < y) a[i]=9,b[i]=0,x=x*10+9,y=y*10+0;
                    else if(x > y) a[i]=0,b[i]=9,x=x*10+0,y=y*10+9;
                }
            else if(c[i] == '?' && j[i] != '?')
            {
                    if(x == y)
                        a[i]=j[i]-'1'+1,b[i]=j[i]-'1'+1,x=x*10+j[i]-'1'+1,y=y*10+j[i]-'1'+1;
                    else if(x < y) a[i]=9,b[i]=j[i]-'1'+1,x=x*10+9,y=y*10+j[i]-'1'+1;
                    else if(x > y) a[i]=0,b[i]=j[i]-'1'+1,x=x*10+0,y=y*10+j[i]-'1'+1;
            }
            else if(j[i] == '?' && c[i] != '?')
            {
                    if(x == y)
                        a[i]=c[i]-'1'+1,b[i]=c[i]-'1'+1,x=x*10+c[i]-'1'+1,y=y*10+c[i]-'1'+1;
                    else if(x < y) a[i]=c[i]-'1'+1,b[i]=0,x=x*10+c[i]-'1'+1,y=y*10+0;
                    else if(x > y) a[i]=c[i]-'1'+1,b[i]=9,x=x*10+c[i]-'1'+1,y=y*10+9;
            }
             else if(j[i]!='?' && c[i]!='?')
        {
                a[i]=c[i]-'1'+1;
                b[i]=j[i]-'1'+1;
                x=c[i]-'1'+1;
                y=j[i]-'1'+1;

        }
        }
        g<<"Case #"<<u<<": ";
        for(i=0;i<strlen(c);i++)
            g<<a[i];
        g<<" ";
        for(i=0;i<strlen(c);i++)
            g<<b[i];
        //for(i=0;i<19;i++) a[i]=0,b[i]=0;
        g<<endl;
    }


    return 0;
}
