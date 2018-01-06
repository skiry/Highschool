#include <iostream>

using namespace std;
int n,a=2,b,OK,d,nr=0;
int main()
{cout<<"Cate perechi de nr naturale prime vreti sa se afiseze ? ";
cin>>n;
while(nr<n)
 {a=a+1;
 b=a-1;
 OK=1;
 for(d=2;d<=b/2&&OK==1;d++)
    if(b%d==0) OK=0;
 if(OK==1)
 {nr=nr+1;
     cout<<a<<" "<<b<<" ; ";}

 }


    return 0;
}
