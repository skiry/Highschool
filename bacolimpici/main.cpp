#include <bits/stdc++.h>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
char s[101],cuv[100][100],note[7][4]={"DO","RE","MI","FA","SOL","LA","SI"},*p;
int viz[100],k,i,j;
struct vf
{
    float x,y;
};
struct poligon
{
    int numar;
    vf varf[100];
}pi;
int main()
{
    f.get(s,101);
    p=strtok(s," ");
    while(p)
    {
        strcpy(cuv[i++],p);
        p=strtok(NULL," ");
    }
    for(j=0;j<i;j++)
        for(k=0;k<7&&!viz[j];k++)
        if(strstr(cuv[j],note[k])) viz[j]++;
    for(j=0;j<i;j++)
        if(viz[j]) g<<cuv[j]<<endl;

    pi.numar=10;
    pi.varf[0].x=1;
    pi.varf[0].y=5;
    g<<pi.numar<<" "<<pi.varf[0].x<<" "<<pi.varf[0].y<<endl;
    return 0;
}
