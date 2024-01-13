#include <string>
#include <vector>

using namespace std;
int arr[205];
int solution(vector<vector<int>> lines) 
{
    int count = 0;
    for(const auto& iter : lines)
    {
        for(int i = iter[0] + 100; i < iter[1] + 100; i++)
        {
            arr[i]++;
        }
    }
    for(int i = 0; i <= 200; i++)
        if(arr[i] >= 2)
            count++;

    return count;
}