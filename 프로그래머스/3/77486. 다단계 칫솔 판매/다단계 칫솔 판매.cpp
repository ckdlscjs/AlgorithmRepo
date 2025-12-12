#include <bits/stdc++.h>

using namespace std;
//enroll    ->  판매원의이름
//referral  ->  판매원을 참여시킨 다른판매원의이름
//seller, amount -> 판매금액
std::unordered_map<std::string, std::string> parent;
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {  
    for(int i = 0; i < enroll.size(); i++)
    {
        parent[enroll[i]] = referral[i];
    }
    std::unordered_map<std::string, int> sell;
    for(int i = 0; i < seller.size(); i++)
    {
        auto str = seller[i];
        int price = amount[i] * 100;
        sell[str] += price;
        while(price && parent.find(str) != parent.end())
        {
            int carry = price * 0.1f;
            sell[str] -= carry;
            price = carry;
            //std::cout << str << ' ' << sell[str] << ", ";
            str = parent[str];
            sell[str] += price;
            //std::cout << str << ' ' << sell[str] << '\n';
        }
    }
    vector<int> answer;
    for(int i = 0; i < enroll.size(); i++)
    {
        //std::cout << enroll[i] << ' ' << sell[enroll[i]] << '\n';
        answer.push_back(sell[enroll[i]]);
    }
    
    return answer;
}