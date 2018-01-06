#include <bits/stdc++.h>

using namespace std;
vector <int> a;
vector <int>::iterator it;
int main()
{
    a.push_back(3);
    a.push_back(4);
    a.push_back(6);
    a.push_back(8);
    a.push_back(11);
    it=lower_bound(a.begin(),a.end(),7);
    cout<<*it;
    return 0;
}
