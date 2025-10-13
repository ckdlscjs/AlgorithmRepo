#include <bits/stdc++.h>
using namespace std;
bool solution(vector<string> phone_book) 
{
    std::sort(phone_book.begin(), phone_book.end(), [](const std::string& a, const std::string& b)
              {
                  return a.size() < b.size();
              });
    std::unordered_set<std::string> chks;
    
    for(const auto& iter : phone_book)
    {
        std::string temp = "";
        for(int i = 0; i < iter.size(); i++)
        {
            temp += iter[i];
            if(chks.find(temp) != chks.end())
                return false;
        }
        chks.insert(iter);
    }
    return true;
}