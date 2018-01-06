#include <iostream>

using namespace std;
char a[100];
int b[100],n,i,s,cmax,m,pi,pf;
int main()
{cout<<"Un nr impar : ";
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];

    for(i=1;i<=n/2;i++)
        s=int(m-i)+int(m+i);
    if(s>cmax) {cmax=s;pi=m-i;pf=m+i;}

    {cout<<a[pi]<<" "<<a[pf];}




    return 0;
}
