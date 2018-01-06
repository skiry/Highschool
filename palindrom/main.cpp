#include <bits/stdc++.h>
using namespace std;
ifstream f("palindrom.in");
ofstream g("palindrom.out");
deque <char> q;
deque <char> in;
char s;
int main()
{
    while(f>>s) q.push_front(s),in.push_back(s);
    while(in.size())
    {
        if(q.front()==in.front()) {g<<q.front();q.pop_front();in.pop_front();}
        else {g<<in.front();in.pop_front();}
    }
    while(q.size()) {g<<q.front();q.pop_front();}
    return 0;
}
