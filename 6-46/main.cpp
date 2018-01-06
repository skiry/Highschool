#include <iostream>

using namespace std;
int a,b,i,d=0;
int main()
{cout<<"Dati o valoare primului numar : ";
cin>>a;
cout<<"Dati o valoare celui de-al doilea numar : ";
cin>>b;
    for(i=1;i<=b;i++)
    {
    d=d+a;

    }
    cout<<"A x B = "<<d<<endl;
    return 0;
}
