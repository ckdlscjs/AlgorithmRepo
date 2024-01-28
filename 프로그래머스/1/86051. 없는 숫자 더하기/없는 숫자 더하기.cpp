#include <string>
#include <vector>

using namespace std;
bool checks[10];
int solution(vector<int> numbers) {
    int answer = 0;
    for(const int& num : numbers)
    {
        checks[num] = true;
    }
    for(int i = 0; i < 10; i++)
        if(!checks[i])
            answer += i;
    return answer;
}