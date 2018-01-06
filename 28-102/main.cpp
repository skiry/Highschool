#include <iostream>

using namespace std;
int st=1,dr=1,n,i=1,nr=1,ok;
int main()
{cin>>n;
cout<<st<<" ";
while(nr!=n)
{if(nr<n) { st=i*2+1;nr++; cout<<st<<" ";}
if(nr<n) {dr=i*3+1;nr++; cout<<dr<<" ";}
i=st;
}



    return 0;
}
