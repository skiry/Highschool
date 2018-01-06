#include <iostream>

using namespace std;
int n,d,OK,nr,a,m,x,c,s=0;
int main()
{cout<<"Vreti sa afisati primele ... numere prime : ";
cin>>n;
cout<<"Cat vreti sa fie m ? ";
cin>>m;
nr=0;
a=2;
while(nr<n)
{OK=1;
    for(d=2;d<=a/2&&OK==1;d++)
    {
        if(a%d==0) OK=0;

    }
if(OK==1)
{x=a;
s=0;
    while(x!=0)
    {
        c=x%10;
        x=x/10;
        s=s+c;
    }
    if(s<m) {nr++;
    cout<<a<<" ";}

}
a++;}

    return 0;
}

