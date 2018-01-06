#include <fstream>


using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
 int m,nr=2,i,j,n,viz[100],maxim=0,a[11][11];
void verifica(int i,int j,int nr)
{
    a[i][j]=nr;
    viz[nr]++;
    for(int k=0;k<8;k++)
        if(a[i+dx[k]][j+dy[k]]==1&&i+dx[k]>=0&&i+dx[k]<n&&j+dy[k]>=0&&j+dy[k]<m) verifica(i+dx[k],j+dy[k],nr);
}
int get_biggest_region(int a[11][11]) {
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(a[i][j]==1) verifica(i,j,nr),nr++;
    for(i=2;i<100;i++)
        if(viz[i]>maxim) maxim=viz[i];
    return maxim;
}

int main(){

    cin >> n;

    cin >> m;

    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> a[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(a) << endl;
    return 0;
}
