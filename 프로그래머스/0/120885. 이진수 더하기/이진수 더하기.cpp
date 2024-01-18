#include <bits/stdc++.h>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int idx1 = bin1.size()-1;
    int idx2 = bin2.size()-1;
    int carry = 0;
    while(idx1 >= 0 || idx2 >= 0)
    {
        int num1 = idx1 >= 0 ? bin1[idx1] - '0' : 0;
        int num2 = idx2 >= 0 ? bin2[idx2] - '0' : 0;
        int num = num1 + num2 + carry;
        carry = 0;
        if(num >= 2)
        {
            num -= 2;
            carry = 1;
        }
        answer += std::to_string(num);
        if(idx1 >= 0) idx1--;
        if(idx2 >= 0) idx2--;
    }
    if(carry)
        answer += std::to_string(carry);
    std::reverse(answer.begin(), answer.end());
    return answer;
}