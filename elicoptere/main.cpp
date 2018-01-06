#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
ifstream f("elicoptere.in");
ofstream g("elicoptere.out");
int n,k,i,v;
double m[101][101];
struct triunghi
{
    int x1,x2,x3,y1,y2,y3;
    double A1,B1,C1,A2,B2,C2,A3,B3,C3;
};
triunghi p;
vector <triunghi> a;
int det(int v1,int v2,int v3,int v4,double v5,double v6)
{
    return (v1*v4+v2*v5+v3*v6-v4*v5-v2*v3-v1*v6);
}
void cautare(int b,int c)
{
    double yrez=0,xrez=0;
    for(int j=0;j<n;j++)///daca b1=0 iei punctul y mai apropiat
        if(i!=j)///daca nu iese, pune c=y+1,respectiv la y1=y2 b=x+1
    {///AM LUAT CELE 3 LATURI ALE TRIUNGHIULUI SI O DREAPTA VERTICALA
        if(!a[j].B1)
        {
            xrez=b;
            yrez=min(abs(c-a[j].y1),abs(c-a[j].y2));
        }
        else if(a[j].A1)
        {
            yrez=(a[j].C1*(-c)-a[j].A1*b*c)/(a[j].B1*c);
            xrez=(a[j].B1*yrez+a[j].C1)/a[j].A1;
            xrez*=(-1);
        }
        else if(!a[j].A1)
        {
            yrez=a[j].C1/a[j].B1;
            yrez*=(-1);
            xrez=c;
        }
        if(det(a[j].x1,a[j].y1,a[j].x2,a[j].y2,b,c)*det(a[j].x1,a[j].y1,a[j].x2,a[j].y2,xrez,yrez))
        {
            if(a[j].A1)
            {
                yrez=(a[j].C1*(max(a[j].y1,a[j].y2)+1-c)-a[j].A1*(b*c-b*(max(a[j].y1,a[j].y2)+1)))/(a[j].B1*(max(a[j].y1,a[j].y2)+1-c));
                yrez*=(-1);
                xrez=(a[j].B1*yrez+a[j].C1)/a[j].A1;
                xrez*=(-1);
            }
            else if(!a[j].A1)
            {
                yrez=a[j].C1/a[j].B1;
                yrez*=(-1);
                xrez=(b*c-b*(max(a[j].y1,a[j].y2)+1))/(max(a[j].y1,a[j].y2)+1-c);
                xrez*=(-1);
            }
        }
        if(((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c))<=(k*k))
            if(!m[i][j]) m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
            else if(m[i][j]&&((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c)<=(m[i][j]*m[i][j])))
                m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
        if(!a[j].B2)
        {
            xrez=b;
            yrez=min(abs(c-a[j].y3),abs(c-a[j].y1));
        }
        else if(a[j].A2)
        {
            yrez=(a[j].C2*(-c)-a[j].A2*b*c)/(a[j].B2*c);
            xrez=(a[j].B2*yrez+a[j].C2)/a[j].A2;
            xrez*=(-1);
        }
        else if(!a[j].A2)
        {
            yrez=a[j].C2/a[j].B2;
            yrez*=(-1);
            xrez=c;
        }
        if(det(a[j].x1,a[j].y1,a[j].x3,a[j].y3,b,c)*det(a[j].x1,a[j].y1,a[j].x3,a[j].y3,xrez,yrez))
        {
            if(a[j].A2)
            {
                yrez=(a[j].C2*(max(a[j].y1,a[j].y3)+1-c)-a[j].A2*(b*c-b*(max(a[j].y1,a[j].y3)+1)))/(a[j].B2*(max(a[j].y1,a[j].y3)+1-c));
                yrez*=(-1);
                xrez=(a[j].B2*yrez+a[j].C2)/a[j].A2;
                xrez*=(-1);
            }
            else if(!a[j].A2)
            {
                yrez=a[j].C2/a[j].B2;
                yrez*=(-1);
                xrez=(b*c-b*(max(a[j].y1,a[j].y3)+1))/(max(a[j].y1,a[j].y3)+1-c);
                xrez*=(-1);
            }
        }
        if(((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c))<=(k*k))
            if(!m[i][j]) m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
            else if(m[i][j]&&((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c)<=(m[i][j]*m[i][j])))
                m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
        if(!a[j].B3)
        {
            xrez=b;
            yrez=min(abs(c-a[j].y3),abs(c-a[j].y2));
        }
        else if(a[j].A3)
        {
            yrez=(a[j].C3*(-c)-a[j].A3*b*c)/(a[j].B3*c);
            xrez=(a[j].B3*yrez+a[j].C3)/a[j].A3;
            xrez*=(-1);
        }
        else if(!a[j].A3)
        {
            yrez=a[j].C3/a[j].B3;
            yrez*=(-1);
            xrez=c;
        }
        if(det(a[j].x2,a[j].y2,a[j].x3,a[j].y3,b,c)*det(a[j].x2,a[j].y2,a[j].x3,a[j].y3,xrez,yrez))
        {
            if(a[j].A3)
            {
                yrez=(a[j].C3*(max(a[j].y2,a[j].y3)+1-c)-a[j].A3*(b*c-b*(max(a[j].y2,a[j].y3)+1)))/(a[j].B3*(max(a[j].y2,a[j].y3)+1-c));
                yrez*=(-1);
                xrez=(a[j].B3*yrez+a[j].C3)/a[j].A3;
                xrez*=(-1);
            }
            else if(!a[j].A3)
            {
                yrez=a[j].C3/a[j].B3;
                yrez*=(-1);
                xrez=(b*c-b*(max(a[j].y2,a[j].y3)+1))/(max(a[j].y2,a[j].y3)+1-c);
                xrez*=(-1);
            }
        }
        if(((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c))<=(k*k))
            if(!m[i][j]) m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
            else if(m[i][j]&&((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c)<=(m[i][j]*m[i][j])))
                m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
        ///AM LUAT CELE 3 LATURI ALE TRIUNGHIULUI SI O DREAPTA ORIZONTALA
        if(a[j].A1)
        {
            yrez=b*c;
            xrez=(a[j].B1*yrez+a[j].C1)/a[j].A1;
            xrez*=(-1);
        }
        else if(!a[j].A1)
        {
            yrez=c;
            xrez=min(abs(b-a[j].x1),abs(b-a[j].x2));
        }
        if(det(a[j].x1,a[j].y1,a[j].x2,a[j].y2,b,c)*det(a[j].x1,a[j].y1,a[j].x2,a[j].y2,xrez,yrez))
        {
            if(a[j].A1)
            {
                yrez=(a[j].A1*b*(max(a[j].x1,a[j].x2)+1)-b*c)/((b-max(a[j].x1,a[j].x2)+1)*a[j].A1);
                yrez*=(-1);
                xrez=(a[j].B1*yrez+a[j].C1)/a[j].A1;
                xrez*=(-1);
            }
            else if(!a[j].A1)
            {
                yrez=c;
                xrez=min(abs(b-a[j].x1),abs(b-a[j].x2));
            }
        }
        if(((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c))<=(k*k))
            if(!m[i][j]) m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
            else if(m[i][j]&&((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c)<=(m[i][j]*m[i][j])))
                m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
        if(a[j].A2)
        {
            yrez=b*c;
            xrez=(a[j].B2*yrez+a[j].C2)/a[j].A2;
            xrez*=(-1);
        }
        else if(!a[j].A2)
        {
            yrez=c;
            xrez=min(abs(b-a[j].x1),abs(b-a[j].x3));
        }
        if(det(a[j].x1,a[j].y1,a[j].x3,a[j].y3,b,c)*det(a[j].x1,a[j].y1,a[j].x3,a[j].y3,xrez,yrez))
        {
            if(a[j].A2)
            {
                yrez=(a[j].A2*b*(max(a[j].x1,a[j].x3)+1)-b*c)/((b-max(a[j].x1,a[j].x3)+1)*a[j].A2);
                yrez*=(-1);
                xrez=(a[j].B2*yrez+a[j].C2)/a[j].A2;
                xrez*=(-1);
            }
            else if(!a[j].A2)
            {
                yrez=c;
                xrez=min(abs(b-a[j].x1),abs(b-a[j].x3));
            }
        }
        if(((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c))<=(k*k))
            if(!m[i][j]) m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
            else if(m[i][j]&&((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c)<=(m[i][j]*m[i][j])))
                m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
        if(a[j].A3)
        {
            yrez=b*c;
            xrez=(a[j].B3*yrez+a[j].C3)/a[j].A3;
            xrez*=(-1);
        }
        else if(!a[j].A3)
        {
            yrez=c;
            xrez=min(abs(b-a[j].x3),abs(b-a[j].x2));
        }
        if(det(a[j].x2,a[j].y2,a[j].x3,a[j].y3,b,c)*det(a[j].x2,a[j].y2,a[j].x3,a[j].y3,xrez,yrez))
        {
            if(a[j].A3)
            {
                yrez=(a[j].A3*b*(max(a[j].x2,a[j].x3)+1)-b*c)/((b-max(a[j].x2,a[j].x3)+1)*a[j].A3);
                yrez*=(-1);
                xrez=(a[j].B3*yrez+a[j].C3)/a[j].A3;
                xrez*=(-1);
            }
            else if(!a[j].A3)
            {
                yrez=c;
                xrez=min(abs(b-a[j].x2),abs(b-a[j].x3));
            }
        }
        if(((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c))<=(k*k))
            if(!m[i][j]) m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
            else if(m[i][j]&&((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c)<=(m[i][j]*m[i][j])))
                m[i][j]=m[j][i]=sqrt((xrez-b)*(xrez-b)+(yrez-c)*(yrez-c));
    }
}
int main()
{
    f>>v;
    f>>n>>k;
    for(i=1;i<=n;i++)
        {
            f>>p.x1>>p.y1>>p.x2>>p.y2>>p.x3>>p.y3;
            p.A1=p.y2-p.y1;
            p.A2=p.y3-p.y1;
            p.A3=p.y3-p.y2;
            p.B1=p.x1-p.x2;
            p.B2=p.x1-p.x3;
            p.B3=p.x2-p.x3;
            p.C1=p.x2*p.y1-p.x1*p.y2;
            p.C2=p.x3*p.y1-p.x1*p.y3;
            p.C3=p.x3*p.y2-p.x2*p.y3;
            ///AB:A1x+B1y+C1=0;
            ///BC:A2x+B2y+C2=0;
            ///AC:A3x+B3y+C3=0;
            a.push_back(p);
        }
    for(i=0;i<n;i++)
    {
        cautare(a[i].x1,a[i].y1);
        cautare(a[i].x2,a[i].y2);
        cautare(a[i].x3,a[i].y3);
    }
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++)
        g<<m[i][j]<<" ";g<<endl;}
    g<<endl;
    for(i=0;i<n;i++)
        g<<a[i].x1<<" "<<a[i].y1<<" "<<a[i].x2<<" "<<a[i].y2<<" "<<a[i].x3<<" "<<a[i].y3<<endl;
    g<<endl;
    for(i=0;i<n;i++)
        g<<a[i].A1<<" "<<a[i].B1<<" "<<a[i].C1<<"   "<<a[i].A2<<" "<<a[i].B2<<" "<<a[i].C3<<"   "<<a[i].A3<<" "<<a[i].B3<<" "<<a[i].C3<<endl;
    return 0;
}
