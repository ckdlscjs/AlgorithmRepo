#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) 
{
    int a = 0, b = 0;
    for(const int& num : num_list)
    {
        if(num%2)
            b++;
        else
            a++;
    }
    return {a,b};
}