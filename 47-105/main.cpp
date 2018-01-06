#include <iostream>

using namespace std;
int a[100],n,i,m,j,nr=1,st,dr;
int main()
{cout<<"nr de el=";cin>>n;
cout<<endl;
for(i=1;i<=n;i++) cin>>a[i];
cout<<"nr de perechi=";cin>>m;
cout<<endl;
cout<<"primul nr al intervalului=";cin>>i;
cout<<endl;
cout<<"ultimul nr al intervalului=";cin>>j;
cout<<endl;
st=i;
dr=j;
while(st<dr)
    {swap(a[st],a[dr]);
    st++;
    dr--;}
    for(i=1;i<=n;i++) cout<<a[i]<<" ";
while(nr<m)
{cout<<"primul nr al intervalului=";cin>>i;
cout<<endl;
cout<<"ultimul nr al intervalului=";cin>>j;
cout<<endl;
st=i;
dr=j;
while(st<dr)
    {swap(a[st],a[dr]);
    st++;
    dr--;}
    nr++;}
for(i=1;i<=n;i++) cout<<a[i]<<" ";


    return 0;
}
