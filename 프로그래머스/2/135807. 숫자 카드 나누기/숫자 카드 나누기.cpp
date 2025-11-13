#include <bits/stdc++.h>
using namespace std;
int GCD(int large, int small)
{
    return large % small ? GCD(small, large % small) : small; 
}
int solution(vector<int> arrayA, vector<int> arrayB) 
{
    int answer = 0;
    int gcdA = arrayA[0];
    for(int i = 1; i < arrayA.size(); i++)
    {
        int large = std::max(gcdA, arrayA[i]);
        int small = std::min(gcdA, arrayA[i]);
        gcdA = GCD(large, small);
    }
    
    
    int gcdB = arrayB[0];
    for(int i = 1; i < arrayA.size(); i++)
    {
        int large = std::max(gcdB, arrayB[i]);
        int small = std::min(gcdB, arrayB[i]);
        gcdB = GCD(large, small);
    }
    if(gcdA != 1)
    {
        int i = 0;
        for(i; i < arrayB.size(); i++)
        {
            if(arrayB[i] % gcdA == 0) break;
        }
        if(i >= arrayB.size())
            answer = std::max(answer, gcdA);
    }
    
    if(gcdB != 1)
    {
        int i = 0;
        for(i; i < arrayA.size(); i++)
        {
            if(arrayA[i] % gcdB == 0) break;
        }
        if(i >= arrayA.size())
            answer = std::max(answer, gcdB);
    }
    return answer;
}