#include <iostream>

using namespace std;
int n,a,OK,d,nr=0;
int main()
{cout<<"Dati o valoare lui n : ";
cin>>n;
a=n;
while(nr<1)
 {

     OK=1;
     for(d=2;d<=a/2&&OK==1;d++)
        if(a%d==0) OK=0;
     if(OK==1) nr=nr+1;
     else a--;


 }
cout<<" Cel mai mare numar prim,mai mic decat "<<n<<" este "<< a;
    return 0;
}
