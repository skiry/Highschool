#include <iostream>

using namespace std;
int n,a,x,y,nr=0;
int main()
{cout<<"Dati o valoare primului numar din interval : ";
cin>>x;
cout<<"Dati o valoare ultimului numar din interval : ";
    cin>>y;
    cout<<"Vreti sa afisati primele ... puteri ai lui 2 din intervalul ["<<x<<","<<y<<"] : " ;
    cin>>n;
    a=2;
    while(nr<n)
    {a=a*2;
    if(a>x) {nr++;
    cout<<a<<" ";}

    }



    return 0;
}
