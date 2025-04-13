#include <bits/stdc++.h>
using namespace std;
int N;
std::string str;
std::vector<std::string> inputs;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> str;
        inputs.push_back(str);
    }
    std::sort(inputs.begin(), inputs.end(), [](const std::string& a, const std::string& b) -> bool {return a.size() > b.size();});
    std::vector<std::string> results;
    std::function<bool(const std::vector<std::string>&, const std::string&)> func = [](const std::vector<std::string>& res, const std::string& word)->bool{
        for(const auto& iter : res)
        {
            auto pos = iter.find(word);
            if(pos != std::string::npos && pos == 0) return false;
        }
        return true;
    };
    for(const auto& iter : inputs)
    {
        if(func(results, iter))
        {
            results.push_back(iter);
        }
    }
    std::cout << results.size();
    return 0;
}
