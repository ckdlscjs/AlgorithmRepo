#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    if(direction == "right")
    {
        numbers.insert(numbers.begin(), numbers[numbers.size()-1]);
        numbers.erase(numbers.begin() + numbers.size()-1);
    }
    else
    {
        numbers.push_back(numbers.front());
        numbers.erase(numbers.begin());
    }
    return numbers;
}