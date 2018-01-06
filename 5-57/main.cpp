#include <iostream>

using namespace std;
int a,b,ogl,nr=0,c,x,i,y,s=0;
float r;
int main()
{cout<<"Dati o valoare primului nr. din interval : ";
cin>>a;
cout<<"Dati o valoare ultimului nr. din interval : ";
cin>>b;
if (a>b) {x=a;
a=b;
b=x;}
for(i=a;i<=b;i++)
{y=i;ogl=0;
while(y!=0)
{c=y%10;
y=y/10;
ogl=ogl*10+c;}
if(i==ogl) {nr=nr+1;
s=s+i;}



}
r=s/nr;

cout<<"Media aritmetica a tuturor palindroamelor din intervalul ["<<a<<","<<b<<"] este "<<r<<endl;

    return 0;
}
