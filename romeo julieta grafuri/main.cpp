#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],r,j,dr[100],tr[100],sr[100],dj[100],tj[100],sj[100],n,m,i,k,l,c;
int cauta_minim_r() /// se cauta cel mai aproapiat nod nevizitat, fata de Romeo
{
    int minim=99999,vf=0;
    for(int i=1;i<=n;i++)
    {
        if(sr[i]==0)
            if(dr[i]<minim)
                minim=dr[i],vf=i;

    }
    sr[vf]=1;
    return vf;
}
int cauta_minim_j()///se cauta cel mai aproapiat nod nevizitat, fata de Julieta
{
    int minim=99999,vf=0;
    for(i=1;i<=n;i++)
    {
        if(!sj[i])
            if(dj[i]<minim)
                minim=dj[i],vf=i;

    }
    sj[vf]=1;
    return vf;
}
void imb_drum_r(int vf)///se cauta imbunatatiri pt toate legaturile nodului returnat mai sus
{
    for(int i=1;i<=n;i++)
        if(!sr[i])
            if(dr[i]>dr[vf]+a[vf][i])
                dr[i]=dr[vf]+a[vf][i],tr[i]=vf;


}
void imb_drum_j(int vf)
{
    for(i=1;i<=n;i++)
        if(!sj[i]&&dj[i]>dj[vf]+a[vf][i])
            dj[i]=dj[vf]+a[vf][i],tj[i]=vf;

}
void drum_r(int i)///se afiseaza drumul
{
    if(tr[i]) drum_r(tr[i]);
    g<<i<<" ";
}
void drum_j(int i)
{
    if(tj[i]) drum_j(tj[i]);
    g<<i<<" ";
}
int main()
{
    f>>n>>m;

    for(i=1;i<=n;i++)   ///se completeaza matricea
        for(l=1;l<=n;l++)
            if(i==l) a[i][l]=0;
            else a[i][l]=99999;

    for(k=1;k<=m;k++) f>>i>>l>>c,a[i][l]=c;
    f>>j>>r;

    for(i=1;i<=n;i++)
    {
       dr[i]=a[r][i];
       if(a[r][i]&&a[r][i]!=99999) tr[i]=r;
       dj[i]=a[j][i];
       if(a[j][i]&&a[j][i]!=99999) tj[i]=j;
    }
    sr[r]=sj[j]=1;

    for(k=1;k<n;k++)
    {
       imb_drum_r(cauta_minim_r());
       imb_drum_j(cauta_minim_j());
    }
    int intersectie=99999;
    for(i=1;i<n;i++)    ///se cauta nodul in care cei doi ajung in cel mai scurt timp
        if(dr[i]+dj[i]<intersectie&&dr[i]&&dj[i])
            intersectie=i;

        g<<"Intersectia : "<<intersectie<<endl;
        g<<"Julieta merge : "<<dj[intersectie]<<endl;
        g<<"Romeo merge : "<<dr[intersectie]<<endl;
        g<<"Traseul Julietei : ";drum_j(intersectie);
        g<<endl;
        g<<"Traseul lui Romeo : ";drum_r(intersectie);

    /**for(i=1;i<=n;i++)
    g<<sr[i]<<" ";
    g<<endl;

    for(i=1;i<=n;i++)
    g<<dr[i]<<" ";
    g<<endl;

    for(i=1;i<=n;i++)
    g<<tr[i]<<" ";
    g<<endl;

    for(i=1;i<=n;i++)
    g<<sj[i]<<" ";
    g<<endl;

    for(i=1;i<=n;i++)
    g<<dj[i]<<" ";
    g<<endl;

    for(i=1;i<=n;i++)
    g<<tj[i]<<" ";
    */

    return 0;
}
