#include <iostream>
int a,i,n,c,sc=0,s=0,catul,restul;
using namespace std;
int main()
{
    cout << "n="; cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"Introduceti valorea lui a="; cin>>a;
        s=s+a;
        while(a!=0)
        {
            c=a%10;
            a=a/10;
            sc=sc+c;
        }
    }
        catul=s/sc;
        restul=s-(sc*catul);
        cout<<"Catul impartiriei sumei numerelor("<<s<<")la suma cifrelor numarului("<<sc<<") este "<<catul<< " iar restul este "<<restul<<endl;
    return 0;
}
