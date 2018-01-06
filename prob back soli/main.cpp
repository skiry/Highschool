#include <iostream>
using namespace std;
int n,viz[20],afis[10],numar,total;
void backt(int nr)
{
    if(nr==numar+1)
    {
        for(int i=1;i<=numar;i++)
                cout<<afis[i];
        total++;
        cout<<endl;
    }
    else
    {
        for(int i=0;i<=9;i++)
            if(viz[i])
        {
            afis[nr]=i;
            --viz[i];
            backt(nr+1);
            ++viz[i];
        }
    }
}
int main()
{
    cin>>n;
    while(n)
    {
        viz[n%10]++;
        n/=10;
        numar++;
    }
    backt(1);
    cout<<"Sunt "<<total<<" numere.";
    return 0;
}
