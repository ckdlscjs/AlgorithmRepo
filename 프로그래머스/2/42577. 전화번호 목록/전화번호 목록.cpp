#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) 
{
    std::sort(phone_book.begin(), phone_book.end(), std::less<>());
    std::unordered_set<std::string> us;
    for(const auto& iter : phone_book)
    {
        if(us.size())
        {
            std::string it = "";
            for(int i = 0; i < iter.size(); i++)
            {
                it += iter[i];
                if(us.size() && us.find(it) != us.end())
                {
                    return false;
                }
            }
        }
        us.insert(iter);
    }
    return true;
}