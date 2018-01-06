#include <fstream>

using namespace std;
ifstream f("immortal.in");
ofstream g("immortal.out");
int n,col,k,i,j,a[25][25],x,y,nr,sens[25],v[25],sf;
struct nemuritori
{
    int l,c;
};
nemuritori m[25],coada[25]; ///in m[i].l am linia nemuritorului i, iar in m[i].c coloana. In coada imi tin parcurgerile.
void afis()
{
     for(int i=1;i<nr;i++)
            {
                g<<coada[i].l<<" "<<coada[i].c<<" ";
                if(sens[i]==1) coada[i].c+=2;
                else if(sens[i]==2) coada[i].c-=2;
                else if(sens[i]==3) coada[i].l+=2;
                else if(sens[i]==4) coada[i].l-=2;
                g<<coada[i].l<<" "<<coada[i].c<<" "<<endl;
            }

}
void backt(int k)
{//g<<k<<endl;
    if(sf) return;
    if(k==nr)
        {
            sf=1;
            afis();
            return;
        }
    for(int i=1;i<=nr;i++)
        if(!v[i]) ///daca nemuritorul i este nevizitat, fac verificari
    {
        x=m[i].l;
        y=m[i].c;
        if(a[x][y-1]>0&&a[x][y+1]==0) ///daca am deasupra un nemuritor care poate sari in jos peste actualul nemuritor
        {
            v[i]=1; ///vizitez nemuritorul actual
            sens[k]=1; ///imi pastrez in sens[i] valorile {1,2,3,4} pentru a putea afisa ulterilor solutia
            coada[k].l=x;
            coada[k].c=y-1;                 ///pun in coada nemuritorul care l-a omorat pe actualul
            m[a[x][y-1]].c+=2;   ///actualizez locul atacatorilui in lista nemuritorilor
            a[x][y+1]=a[x][y-1]; ///actualizez locul atacatorului in matrice
            a[x][y]=a[x][y-1]=0; ///golesc locurile nemuritorilor
            backt(k+1);
            v[i]=0; ///devizitez
            m[a[x][y-1]].c-=2; ///pun inapoi nemuritorul de unde a plecat
            a[x][y]=i;
            swap(a[x][y-1],a[x][y+1]);
        }
        if(a[x][y+1]>0&&a[x][y-1]==0)
        {
            v[i]=1;
            sens[k]=2;
            coada[k].l=x;
            coada[k].c=y+1;
            m[a[x][y+1]].c-=2;
            a[x][y-1]=a[x][y+1];
            a[x][y]=a[x][y+1]=0;
            backt(k+1);
            v[i]=0;
            m[a[x][y+1]].c+=2;
            a[x][y]=i;
            swap(a[x][y+1],a[x][y-1]);
        }
        if(a[x-1][y]>0&&a[x+1][y]==0)
        {
            v[i]=1;
            sens[k]=3;
            coada[k].l=x-1;
            coada[k].c=y;
            m[a[x-1][y]].l+=2;
            a[x+1][y]=a[x-1][y];
            a[x][y]=a[x-1][y]=0;
            backt(k+1);
            v[i]=0;
            m[a[x-1][y]].l-=2;
            a[x][y]=i;
            swap(a[x-1][y],a[x+1][y]);
        }
        if(a[x+1][y]>0&&a[x-1][y]==0)
        {
            v[i]=1;
            sens[k]=4;
            coada[k].l=x+1;
            coada[k].c=y;
            m[a[x+1][y]].l-=2;
            a[x-1][y]=a[x+1][y];
            a[x][y]=a[x+1][y]=0;
            backt(k+1);
            v[i]=0;
            m[a[x+1][y]].l+=2;
            a[x][y]=i;
            swap(a[x+1][y-1],a[x-1][y]);
        }
        /*for(int h=1;h<=n;h++){
            for(j=1;j<=col;j++)
                g<<a[h][j]<<" ";g<<endl;
        }g<<endl;*/
    }
}
int main()
{
    f>>n>>col>>nr;
    for(i=0;i<=n+1;i++) a[i][0]=a[i][col+1]=-1;
    for(i=1;i<=col;i++) a[0][i]=a[n+1][i]=-1;
    for(i=1;i<=nr;i++)
        f>>x>>y,a[x][y]=i,m[i].l=x,m[i].c=y;
    backt(1);
    return 0;
}
