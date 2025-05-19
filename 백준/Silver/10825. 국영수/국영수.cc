//입력값을 튜플로 구성하여 정렬한다, 람다를 이용하여 입력조건에따른 별도구현을수행한다
//NlogN
#include <bits/stdc++.h>
using namespace std;
using tsiii = std::tuple<std::string, int, int, int>;
int N;
tsiii inputs[100'005];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++) std::cin >> std::get<0>(inputs[n]) >> std::get<1>(inputs[n]) >> std::get<2>(inputs[n]) >> std::get<3>(inputs[n]);
    std::sort(inputs, inputs + N, [](const tsiii& a, const tsiii& b) -> bool {
        if(std::get<1>(a) == std::get<1>(b))
        {
            if(std::get<2>(a) == std::get<2>(b))
            {
                if(std::get<3>(a) == std::get<3>(b))
                {
                    return std::get<0>(a) < std::get<0>(b);
                }
                return std::get<3>(a) > std::get<3>(b);
            }
            return std::get<2>(a) < std::get<2>(b);
        }
        return std::get<1>(a) > std::get<1>(b);
    });
    for(int i = 0; i < N; i++)
        std::cout << std::get<0>(inputs[i]) << '\n';
    return 0;
}
