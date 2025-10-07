#include <bits/stdc++.h>

using namespace std;
std::unordered_set<int> chks;
std::vector<int> psums;
int solution(vector<int> elements) 
{
    psums.resize(elements.size() * 2 + 1, 0);
    for(int i = 0; i < elements.size(); i++)
    {
        psums[i+1] = elements[i];
        psums[i+1] += psums[i];
    }
    for(int i = 0; i < elements.size(); i++)
    {
        psums[elements.size() + i+1] = elements[i];
        psums[elements.size() + i+1] += psums[elements.size() + i];
    }
    for(int i = 1; i <= elements.size(); i++)
    {
        for(int j = 1; j <= elements.size(); j++)
        {
            chks.insert(psums[j+i] - psums[j]);
        }
    }
    return chks.size();
}