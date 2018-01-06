#include <iostream>

using namespace std;
int a[100],n,i,x=1,m,n1,p,c;
int main()
{cout<<"Numar de cifre (<10) = ";
cin>>n;
    for(i=1;i<=n;i++) {cout<<"a["<<i<<"]=";
    cin>>a[i];}
    for(i=1;i<=n-1;i++) x=x*10;
    for(i=1;i<=n;i++) {m=a[i]*x+m;
    x=x/10;}
    n1=m;
    while(n1!=0)
    {c=n1%10;
    n1=n1/10;
    p=p*10+c;
    }
    cout<<"Suma nr formate cu cifrele din vector citite de la stanga la dreapta , si invers este "<<m+p;
    return 0;
}
