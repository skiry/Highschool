#include <iostream>

using namespace std;
int a,s=1,c,c1;
int main()
{cout<<"a=";
cin>>a;
c1=a%10;
a=a/10;
while(a)
{c=a%10;
a=a/10;
if(c==c1) s++;
}
    cout<<"Cifra unitatilor apare de "<<s<<" ori in numar !";
    return 0;
}
