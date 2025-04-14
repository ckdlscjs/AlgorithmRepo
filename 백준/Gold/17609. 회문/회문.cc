#include <bits/stdc++.h>
using namespace std;
int T;
std::string str;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> T;
    while(T--)
    {
        std::cin >> str;
        int l = 0, r = str.size()-1;
        std::function<int(int, int, int)> isPalindrome = [&](int l, int r, int cnt) -> int {
            while(l <= r)
            {
                if(str[l] == str[r])
                {
                    l++;
                    r--;
                    continue;
                }
                if(cnt >= 1)
                    return 2;
                if(isPalindrome(l+1, r, cnt+1) == 0 || isPalindrome(l, r-1, cnt+1) == 0)
                    return 1;
                else
                    return 2;
            }
            return 0;
        };
        std::cout << isPalindrome(l, r, 0) << '\n';
    }
    return 0;
}
