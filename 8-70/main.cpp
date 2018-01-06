#include <iostream>

using namespace std;
int n,c,nr,nr1,nr2,nr3,OK;
int main()
{cout<<"n=";
cin>>n;
OK=1;
while(n!=0&&OK==1)
{c=n%10;
n=n/10;
if(c>=4) OK=0;
if(c==0) nr++;
if(c==1) nr1++;
if(c==2) nr2++;
if(c==3) nr3++;

}
  if(OK==1) {cout<<"Numarul este corect si frecventa cifrelor este urmatoarea : "<<endl;
  cout<<"-cifra 0 de "<<nr<<" ori"<<endl;
  cout<<"-cifra 1 de "<<nr1<<" ori"<<endl;
  cout<<"-cifra 2 de "<<nr2<<" ori"<<endl;
  cout<<"-cifra 3 de "<<nr3<<" ori"<<endl;}
else cout<<"Numarul nu este corect ! ";
    return 0;
}
