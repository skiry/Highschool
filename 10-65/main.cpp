#include <iostream>

using namespace std;
int n,a,OK,d,nr=0,b,d1,OK1,nr1;
int main()
{cout<<"Dati o valoare lui n : ";
cin>>n;
a=n+1;
b=n-1;
while(nr<1)
 {

     OK=1;
     for(d=2;d<=a/2&&OK==1;d++)
        if(a%d==0) OK=0;
     if(OK==1) nr=nr+1;
     else a++;


 }
 while(nr1<1)
 {

     OK1=1;
     for(d1=2;d1<=b/2&&OK1==1;d1++)
        if(b%d1==0) OK1=0;
     if(OK1==1) nr1=nr1+1;
     else b--;


 }
cout<<" Numerele prime imediat vecine lui "<<n<<" sunt "<< b<<" si " <<a ;
    return 0;
}
