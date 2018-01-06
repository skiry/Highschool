#include <iostream>

using namespace std;
int n,i,a,x;
int main()
{cout<<"Cat vreti sa fie n ? ";
cin>>n;
for(i=1;i<=n;i++)
    {x=n;
        a=i;
        while(a!=x)
        {
         if(a>x) a=a-x;
         else x=x-a;
        }
        if(a==1) cout<<i<<" Este prim cu "<<n<<endl;
    }
    return 0;
}
