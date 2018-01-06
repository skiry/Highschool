#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int s[100],top,b,i=1,pd,pi,r[100];
char op;
int main()
{
    while(f>>op)
    {
        if(op=='p')
            {
        f>>b;
        if(b==1) top++,s[top]=1,pd++;
        else if(b==2) top++,s[top]=2,pi++;
            }
        if(op=='e')
        {
            if(s[top]==1) pd--;
            else if(s[top]==2) pi--;
            top--;i--;
        }

        if(pd>=pi) r[i]=pd-pi;
        else if(pi>pd) r[i]=-1;
        if(pi==pd&&r[i-1]!=-1) g<<"1";
        else g<<"0";
        if(op=='p') i++;


    }
    return 0;
}
