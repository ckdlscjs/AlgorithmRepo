#include <bits/stdc++.h>
using namespace std;
int N, cnt;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int i = 1; i <= N; i++)
    {
        std::string str = std::to_string(i);
        if(str.size() <= 2) 
        {
            cnt++;
        }
        else if(str.size() == 3)
        {
            if(str[0] - str[1] == str[1] - str[2]) cnt++;
        }
        else if(str.size() == 4)
        {
            if(str[0] - str[1] == str[1] - str[2] && str[1] - str[2] == str[2] - str[3]) cnt++;
        }
    }
    std::cout << cnt;
    return 0;
}
