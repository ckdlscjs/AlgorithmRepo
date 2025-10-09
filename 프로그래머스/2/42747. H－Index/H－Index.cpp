#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr) 
{
    int hindex = 0;
    std::sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] >= arr.size() - i)
            hindex = std::max(hindex, (int)arr.size() - i);
    }
        
    return hindex;
}