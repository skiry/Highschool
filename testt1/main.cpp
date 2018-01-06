#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.txt");
int main()
{
    int x,y,save=0,dist=1;
    f>>x;
    while(f>>y)
    {
        if(x==y) dist++;
        else
        {
            if(dist%2&&(!save||save>=x)) save=x;
            dist=1;
        }
        x=y;
    }
    if(save) cout<<save;
    else cout<<"nu exista";
    return 0;
}
