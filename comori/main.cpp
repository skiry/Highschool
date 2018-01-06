#include <fstream>

using namespace std;
ifstream f("comori.in");
ofstream g("comori.out");
int n,d,p,i,b[1000],c[1000],X,Y;
int main()
{f>>n;
 for(i=1;i<=n;i++) {f>>b[i];f>>c[i];}
 for(p=1;p<=n;p++)
 {for(i=1;i<=c[p];i++)
 {if(b[p]==1) Y++;
 if(b[p]==2){X++;Y++;}
    if(b[p]==3) X++;
    if(b[p]==4) {X++;Y--;}
    if(b[p]==5) Y--;
    if(b[p]==6) {X--;Y--;}
    if(b[p]==7) X--;
    if(b[p]==8) {X--;Y++;}
 }





 }
 g<<X<<" "<<Y;
    return 0;
}
