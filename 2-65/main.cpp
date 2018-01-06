#include <iostream>

using namespace std;
int n,d,OK,nr,a;
int main()
{cout<<"Vreti sa afisati primele ... numere prime : ";
cin>>n;
nr=0;
a=2;
while(nr<n)
{OK=1;
    for(d=2;d<=a/2&&OK==1;d++)
    {
        if(a%d==0) OK=0;

    }
if(OK==1){nr=nr+1;
cout<<a<<" ";}
a++;}

cout<<nr<<endl;
    return 0;
}
