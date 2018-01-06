#include <iostream>

using namespace std;
int i,x,ogl=0,c,d,OK;
int main()
{for(i=1000;i<=9999;i++)
{x=i;
OK=1;
for(d=2;d<=x/2&&OK==1;d++)
{if(x%d==0) OK=0;}
if (OK==1) {while(x!=0)
    {
        c=x%10;
        x=x/10;
        ogl=ogl*10+c;

    }
if(i==ogl) cout<<i<<" este un numar prim,cu inversul tot numar prim"<<endl;
}

}

    return 0;
}
