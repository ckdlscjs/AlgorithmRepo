#include <bits/stdc++.h>
#define ll long long
using namespace std;
std::vector<ll> nums;
std::vector<char> ops;
std::unordered_map<char, int> opers;
int orders[3] = {0, 1, 2};
ll Check(std::vector<ll> _nums, std::vector<char> _ops)
{
    int _order = 2;
    while(_order >= 0)
    {
        std::vector<ll> next_nums;
        std::vector<char> next_ops;
        for(int i = 0; i < _ops.size(); i++)
        {
            if(opers[_ops[i]] < _order)
            {
                next_nums.push_back(_nums[i]);
                next_ops.push_back(_ops[i]);
                continue;
            }
            if(_ops[i] == '+')
            {
                _nums[i+1] =  _nums[i] + _nums[i+1];
                //std::cout << '+' << _nums[i+1] << '\n';
            }
            else if(_ops[i] == '-')
            {
                _nums[i+1] = _nums[i] - _nums[i+1];
                //std::cout << '-' << _nums[i+1] << '\n';
            }
            else if(_ops[i] == '*')
            {
                _nums[i+1] = _nums[i] * _nums[i+1];
                //std::cout << '*' << _nums[i+1] << '\n';
            }
        }
        next_nums.push_back(_nums.back());
        _nums = next_nums;
        _ops = next_ops;
        _order--;
    }
    
    return std::abs(_nums.back());
}
long long solution(string expression) 
{
    std::string num;
    for(const auto& iter : expression)
    {
        if(std::isdigit(iter))
        {
            num += iter;
        }
        else
        {
            nums.push_back(stoll(num));
            num = "";
            ops.push_back(iter);
        }
    }
    nums.push_back(stoll(num));
    long long answer = 0;
    
    do
    {
        opers['+'] = orders[0];
        opers['-'] = orders[1];
        opers['*'] = orders[2];
        answer = std::max(answer, Check(nums, ops));
    }while(std::next_permutation(orders, orders+3));
    
    return answer;
}