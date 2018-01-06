#include <iostream>

using namespace std;
int a,cmin=9999999,b;
int main()
{cout<<"Dati o valoare lui a : ";
cin>>a;
cout<<"Dati o valoare lui b : ";
    cin>>b;
while(a!=0)
{
    while(a!=b)
        {if(a>b) a=a-b;
    else b=b-a;
    if(b<cmin) cmin=b;}
    cout<<"Dati o alta valoare lui a,pana cand ii dati valoarea 0 : ";
    cin>>a;
}cout<<"CMMDC este "<<cmin<<endl;

    return 0;
}
