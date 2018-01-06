#include <iostream>

using namespace std;
int n,cmax=0,nr=0;
int main()
{cin>>n;
while (n!=0)
    {
if (n>cmax) cmax=n;
if (n==cmax) nr=nr+1;
cin>>n;
    }
    cout<<"Valoarea maxima este"<<cmax<<"si apare de "<<nr<<"ori"<<endl;



    return 0;
}
