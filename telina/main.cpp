#include <fstream>
#include <deque>
#include <string.h>
using namespace std;
ifstream f("telina.in");
ofstream g("telina.out");
int i;
string s;
deque <char> c;
int main()
{
    f>>s;
    c.push_back(s[s.size()-1]);
    for(i=s.size()-2;i>=0;i--)
        if(s[i]<=c.front()) c.push_front(s[i]);
    else c.push_back(s[i]);
    for(i=0;i<c.size();i++)
        g<<c[i];
    return 0;
}
