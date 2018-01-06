#include <bits/stdc++.h>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
long long n,a,i,nr;
int main() {
	f>>n;
	for(i=1;i<=n;i++)
    {
        f>>a;
        for(nr=1;nr<a;nr<<=1);
        g<<nr<<endl;
    }
	return 0;
}
