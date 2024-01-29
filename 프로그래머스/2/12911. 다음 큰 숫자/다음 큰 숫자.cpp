#include <string>
#include <vector>

using namespace std;
int count(int num)
{
    int result = 0;
    while(num)
    {
        result += num%2;
        num /= 2;
    }
    return result;
}
int solution(int n) 
{
    int ncount = count(n++);
    while(ncount != count(n++))
    {
        
    }
    return n-1;
}