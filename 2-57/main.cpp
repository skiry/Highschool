#include <iostream>

using namespace std;
int n,i,a,d,OK,r,s=0,s1=0;
int main()
{cout<<"Cate numere vreti sa cititi ? ";
cin>>n;
for(i=1;i<=n;i++)
{cout<<"Dati o valoare numarului : ";
cin>>a;
    OK=1;
    for(d=2;d<=a/2&&OK==1;d++)
        if(a%d==0) OK=0;
    if(OK==1) {s=s+a;
    s1=s1+1;


    }

}
   r=s/s1;
    cout<<"Media aritmetica a  numerelor prime este : "<<r;
    return 0;
}
