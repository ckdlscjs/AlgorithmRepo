#include <bits/stdc++.h>
using namespace std;
int diff;
std::vector<int> res;
void Check(const std::vector<int>& apeach, int sum_a, std::vector<int>& lion, int sum_l, int i, int n)
{
    if(i >= apeach.size())
    {
        if(sum_l - sum_a > 0 && sum_l - sum_a >= diff)
        {
            if(diff == sum_l-sum_a)
            {
                for(int j = lion.size()-1; j >= 0; j--)
                {
                    if(lion[j] == res[j]) continue;
                    if(lion[j] > res[j])
                    {
                        res = lion;
                        return;
                    } 
                    return;
                }
            }
            else
            {
                diff = sum_l - sum_a;
                res = lion;
            }
        }
    }
    else
    {   lion[i] = 0;
        if(lion[i] == apeach[i])
            Check(apeach, sum_a, lion, sum_l, i+1, n);
        Check(apeach, sum_a + 10 - i, lion, sum_l, i+1, n);
        int wincnt = apeach[i] + 1;
        if(n >= wincnt)
        {
            lion[i] = wincnt;
            Check(apeach, sum_a, lion, sum_l + 10-i, i+1, n - wincnt);
        }
        lion[i] = n;
        Check(apeach, sum_a + 10 - i, lion, sum_l, i+1, 0);
    }
}

vector<int> solution(int n, vector<int> info) 
{
    std::vector<int> lion(11, 0);
    Check(info, 0, lion, 0, 0, n);
    return res.size() ? res : std::vector<int>(1, -1);
}