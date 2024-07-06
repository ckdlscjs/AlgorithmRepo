#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
    std::vector<int> answer;
    int i_start = left / n;
    int j_start = left % n;
    int i_end = right / n;
    int j_end = right%n;
    while(i_start * n + j_start <= i_end*n + j_end)
    {
        int num = std::max(i_start, j_start);
        answer.push_back(num+1);
        j_start++;
        if(j_start >= n)
        {
            i_start++;
            j_start = 0;
        }
    }
    return answer;
}