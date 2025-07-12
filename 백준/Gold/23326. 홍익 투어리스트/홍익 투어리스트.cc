/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, Q, C;
std::set<int> chks;
bool arr[500'005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> Q;
    for(int n = 0; n < N; n++)
    {
        std::cin >> arr[n];
        if(arr[n]) chks.insert(n);
    }
    for(Q; Q > 0; Q--)
    {
        int order;
        std::cin >> order;
        if(order == 1)
        {
            int x;
            std::cin >> x;
            x--;
            if(arr[x])
            {
                chks.erase(x);
                arr[x] = false;
            }
            else
            {
                chks.insert(x);
                arr[x] = true;
            }
        }
        else if(order == 2)
        {
            long long x;
            std::cin >> x;
            x += C;
            x %= N;
            C = x;
        }
        else
        {
            if(chks.size() <= 0)
            {
                std::cout << -1 << '\n';
                continue;
            }
            auto iter = chks.lower_bound(C);
            if(iter == chks.end()) std::cout << N - C + *chks.begin() << '\n';
            else  std::cout << *iter - C << '\n';
        }
    }
	return 0;
}

