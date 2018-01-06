#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,vc[8];
char a[100001];
int main()
{
    f.get(a,100001);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='B') vc[1]++;
        if(a[i]=='u') vc[2]++;
        if(a[i]=='l') vc[3]++;
        if(a[i]=='b') vc[4]++;
        if(a[i]=='a') vc[5]++;
        if(a[i]=='s') vc[6]++;
        if(a[i]=='r') vc[7]++;
    }
    int minim=99999;
    if(vc[1]<minim) minim=vc[1];
    if((vc[2]/2)<minim) minim=vc[2]/2;
    if(vc[3]<minim) minim=vc[3];
    if(vc[4]<minim) minim=vc[4];
    if((vc[5]/2)<minim) minim=vc[5]/2;
    if(vc[6]<minim) minim=vc[6];
    if(vc[7]<minim) minim=vc[7];

    if(minim!=99999) g<<minim;
    else g<<"0";
    return 0;
}
