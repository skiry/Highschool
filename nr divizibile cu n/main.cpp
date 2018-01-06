#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");
int n,nr,ok;
int main()
{
    cin>>n;
    while(f>>nr)
        if(!(nr%n)) cout<<nr<<" ",++ok;
    if(!ok) cout<<"NU EXISTA";
    return 0;
}
