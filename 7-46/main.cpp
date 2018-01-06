#include <iostream>

using namespace std;
int a,b,c,nr=1;
int main()
{cout<<"a=";
cin>>a;
cout<<"b=";
cin>>b;
 c=a-b;

 while(b<c)
 {
     a=c;
     c=a-b;
     nr=nr+1;

 }
 cout<<"Restul este "<<c<<" Iar catul este "<<nr<<endl;
    return 0;
}
