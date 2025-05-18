#include <bits/stdc++.h>
using namespace std;
int N;
std::vector<std::string> arr;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    arr.resize(N);
    for(int n = 0; n < N; n++) std::cin >> arr[n];
    std::sort(arr.begin(), arr.end(), [](const std::string& a, const std::string& b)->bool {
        if(a.size() == b.size())
        {
            int sum_a = 0;
            for(const auto& iter : a)
                if(std::isdigit(iter)) sum_a += iter - '0';
            int sum_b = 0;
            for(const auto& iter : b)
                if(std::isdigit(iter)) sum_b += iter - '0';
            if(sum_a == sum_b)
            {
                return a < b;
            }
            return sum_a < sum_b;
        }
        return a.size() < b.size();
    });
    for(const auto& iter : arr)
        std::cout << iter << '\n';
    return 0;
}
