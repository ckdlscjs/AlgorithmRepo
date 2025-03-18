/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
int N;
bool Check666(int num)
{
    int cnt = 0;
    while(num)
    {
        if(num % 10 == 6)
            cnt++;
        else
            cnt = 0;
        if(cnt >= 3) break;
        num /= 10;
    }
    return cnt >= 3;
}
int main()
{
    std::cin >> N;
    int num = 666;
    while(N)
    {
        if(Check666(num)) N--;
        if(N == 0) break;
        num++;
    }
    std::cout << num;
    return 0;
}