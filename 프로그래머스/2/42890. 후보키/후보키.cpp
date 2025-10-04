#include <bits/stdc++.h>
using namespace std;
std::unordered_set<int> res;
void Check(const std::vector<std::vector<std::string>>& relations, const int size, int cur, int idx, int* arr)
{
    if(cur >= size)
    {
        std::unordered_set<std::string> chks;
        for(int i = 0; i < relations.size(); i++)
        {
            std::string str;
            for(int j = 0; j < size; j++)
            {
                str += relations[i][arr[j]] + " ";
            }
            chks.insert(str);
        }

        if(chks.size() >= relations.size())
        {
            int mask = 0;
            for(int i = 0; i < size; i++) 
                mask |= (1 << arr[i]);
            for(const auto& iter : res)
            {
                if((mask & iter) == iter) return;
            }
            res.insert(mask);
        }
    }
    else
    {
        for(int i = idx; i < relations[0].size(); i++)
        {
            arr[cur] = i;
            Check(relations, size, cur+1, i+1, arr);
        }
    }
}
int solution(vector<vector<string>> relation) 
{
    int arr[10];
    for(int size = 1; size <= relation[0].size(); size++)
    {
        Check(relation, size, 0, 0, arr);
    }
    return res.size();
}