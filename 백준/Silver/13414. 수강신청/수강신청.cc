#include <bits/stdc++.h>
using namespace std;
#define pis std::pair<int, std::string>
int K, L;
std::map<std::string, int> orders;
std::priority_queue<pis, std::vector<pis>, std::greater<pis>> pq;
std::string str;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> K >> L;
    for(int l = 0; l < L; l++)
    {
        std::cin >> str;
        orders[str] = l;
    }
    for(const auto& iter : orders)
    {
        pq.push({iter.second, iter.first});
    }
    for(int k = 0; k < K; k++)
    {
        if(pq.size())
        {
            std::cout << pq.top().second << '\n';
            pq.pop();
        }
    }
    return 0;
}
