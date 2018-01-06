#include <iostream>

using namespace std;
int a,i,c,p=1;
int main()
{cin>>a;
while(a)
{c=a%2;
a=a/2;
i=i+p*c;
p=p*10;
}
cout<<i;

    return 0;
}
