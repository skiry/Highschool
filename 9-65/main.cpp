#include <iostream>

using namespace std;
int n,a,OK,d,nr=0;
int main()
{cout<<"Vreti sa afisati primele ... numere prime : ";
cin>>n;
a=2;
while(nr!=n)
 {
 OK=1;
     for(d=2;d<=a/2&&OK==1;d++)
        if(a%d==0) OK=0;

     if(OK==1) {nr++;
     cout<<a<<" ";}
     a++;


 }

    return 0;
}
