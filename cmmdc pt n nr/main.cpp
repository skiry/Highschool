#include <iostream>

using namespace std;
int a,n,i,b;
int main()
{cout<<"Cate nr vreti sa cititi? ";
cin>>n;
cout<<"Dati o valoare numarului : ";
cin>>a;
for(i=2;i<=n;i++)
{cin>>b;
while(a!=b)
    if(a>b) a=a-b;
    else b=b-a;
}
    cout << "CMMDC este " <<a<< endl;
    return 0;
}
