#include <iostream>

using namespace std;
int n,a,c=1,cmax,cmin,media,s=0,x;
int main()
{cout<<"Cati membri sunt in comisia de notare : ";
cin>>n;
cout<<"Dati nota : ";
cin>>a;
x=a;
n=n-1;
    while (a!=0 && n!=0)
{
n--;
    c=c+1;
    if (a>cmax) cmax=a;
    if (a<cmin) cmin=a;
    s=s+a;


        cout<<"Dati o alta nota : ";
        cin>>a;


} s=s+x;
s=s-cmin-cmax;
     media=s/(c-2);
cout<<"Media celor "<<c<<"numere este "<<media<<endl;
    return 0;
}
