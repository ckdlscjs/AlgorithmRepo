#include <bits/stdc++.h>

using namespace std;
std::unordered_map<std::string, std::string> nums;
int solution(string s) {
    nums["zero"] = "0";
    nums["one"] = "1";
    nums["two"] = "2";
    nums["three"] = "3";
    nums["four"] = "4";
    nums["five"] = "5";
    nums["six"] = "6";
    nums["seven"] = "7";
    nums["eight"] = "8";
    nums["nine"] = "9";
    for(const auto& iter : nums)
    {
        while(s.find(iter.first) != std::string::npos)
        {
            s.replace(s.find(iter.first), iter.first.size(), iter.second);
        }
    }
    return std::stoi(s);
}