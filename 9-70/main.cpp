#include <iostream>

using namespace std;
int k,n,s=0;
int main()
{cout<<"baza=";
cin>>k;
cout<<"Dati o valoare pana la "<<k<<" n=";
cin>>n;
while(n<=k)
{if(n%2==0) s=s+n;
cout<<"n=";
cin>>n;

}
    cout<<"Suma cifrelor pare este "<<s;
    return 0;
}
