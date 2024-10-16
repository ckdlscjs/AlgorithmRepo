//https://school.programmers.co.kr/learn/courses/30/lessons/17681
#include <bits/stdc++.h>
using namespace std;
std::string arr[20];
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    for(int i = 0; i < arr1.size(); i++)
        for(int j = n-1; j >= 0; j--)
            arr[i] += arr1[i] & 1 << j ? '#' : ' ';
    for(int i = 0; i < arr2.size(); i++)
        for(int j = n-1; j >= 0; j--)
            arr[i][n - j - 1] = arr2[i] & 1 << j ? '#' : arr[i][n - j - 1];
    vector<string> answer(arr, arr + n);
    return answer;
}