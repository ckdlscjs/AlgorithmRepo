#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b, int c, int d) 
{
    std::map<int, int> inputs;
    inputs[a]++;
    inputs[b]++;
    inputs[c]++;
    inputs[d]++;
    int answer = 1;
    switch(inputs.size())
    {
        case 4:
            {
                answer = inputs.begin()->first;
            }break;
        case 3:
            {
                for(const auto& iter : inputs)
                {
                    if(iter.second == 2)
                        continue;
                    answer *= iter.first;
                }
            }break;
        case 2:
            {
                std::vector<int> pq;
                for(const auto& iter : inputs)
                    pq.push_back(iter.first);
                if(inputs[pq[0]] == 2)
                {
                    answer = (pq[0] + pq[1]) * std::abs(pq[0]-pq[1]);
                }
                else
                {
                    int p = inputs[pq[0]] == 3 ? pq[0] : pq[1];
                    int q = p == pq[0] ? pq[1] : pq[0];
                    answer = (10*p + q) * (10*p+q);
                }
            }break;
        case 1:
            {
                answer = a * 1111;
                
            }break;
    }
    return answer;
}