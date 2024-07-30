#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int sum = 0;
    std::string parent = "";
};
std::unordered_map<std::string, Node> trees;
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) 
{
    Node node;
    node.sum = 0;
    node.parent = "";
    trees["-"] = node;
    for(int i = 0; i < enroll.size(); i++)
    {
        node.parent = referral[i];
        trees[enroll[i]] = node;
    }
    
    for(int i = 0; i < seller.size(); i++)
    {
        std::string sel = seller[i];
        int price = amount[i] * 100;
  
        while(sel != "" && price)
        {
            float upper = price * 0.1;
            if(upper < 1.0)
            {
                trees[sel].sum += price;
                price = 0;
            }
            else
            {
                trees[sel].sum += price - (int)std::floor(upper);
                price = (int)std::floor(upper);
            }
            sel = trees[sel].parent;
        }
    }
    std::vector<int> answer;
    for(int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(trees[enroll[i]].sum);
    }
    
    
    return answer;
}