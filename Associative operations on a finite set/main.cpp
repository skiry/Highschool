#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[10][10],i,j,finver[3],nr,n,rez[10],sum,ok;
int check(int term1,int term2,int term3)/// checks if one operation with 3 terms is associative
{
    if (a[a[term1][term2]][term3]==a[term1][a[term2][term3]]) /// checks if (a*b)*c = a*(b*c)
       return 1;
    return 0;
}
void backt(int poz) /// this function computes all possibilities for a1,a2,a3 => a1*a1*a1 , a1*a1*a2 etc.
{
    if(ok==0)
    for(int i = 0; i < n; i++)
     {
        finver[poz]=rez[i];
        if (poz == 2)
        {
            int partialResult=0;
            partialResult=check(finver[0],finver[1],finver[2]);
            if (partialResult == 1) /// if some operation is associative, we increase the 'sum' variable
                sum+=partialResult;
            else ok=1; /// but if one operation is not associative, we give up checking the remaining possibilities
        }
        else backt(poz+1);
     }
}
void ver(int poz1,int poz2) /// compute the n^(n^2) possibilities
{
    for(int i = 0; i < n; i++)
    {
        a[poz1][poz2]=rez[i]; /// compute the matrix with all the values

        if (poz1 == n-1 && poz2 == n-1)
        {
            sum=ok=0;
            backt(0); /// if we reached the end of the matrix, check if this matrix is an associative table

            if(sum == n*n*n) /// if the number of associative operations on a matrix is n^3 this means all the possibilities
                            /// with 3 terms compute associative operations => the matrix represents an associative table.
            {
                nr++;
                /** g<<"   ";
            for(int i = 1; i <= n; i++)
                g<<"a"<<i<<"  ";
            g<<endl;
            for(int i = 0; i < n; i++)          ///print the associative table
            {
                g<<"a"<<i+1<<"|";
                for(int j = 0; j < n; j++)
                    g<<"a"<<a[i][j]+1<<"  ";
                g<<endl;
            }
            g<<endl;*/
            }
        }
        else
        {
            if (poz2 == n-1) /// if we are on the last element of the actual line, we go to the next line
                ver(poz1+1,0);
            else ver(poz1,poz2+1); /// otherwise, we increase the position on the actual line
        }
    }
}
int main()
{
    f>>n;
    for(i = 0; i < n; i++)
        rez[i]=i;
    ver(0,0);
    g<<endl<<"The number of associative operations on the set A={a1";
    for(i = 2;i <= n; i++)
        g<<", a"<<i;
    g<<"}"<<" is ***"<<nr<<"***";

    return 0;
}
