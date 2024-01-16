
#include <bits/stdc++.h>
using namespace std;

int solution(string A, string B) 
{
    if(A == B)
        return 0;
    for(int i = 1; i <= A.size(); i++)
    {
        A = A.substr(A.size()-1, 1) + A.substr(0, A.size()-1);
        std::cout << A <<'\n';
        if(A == B)
            return i;
    }
    return -1;
}