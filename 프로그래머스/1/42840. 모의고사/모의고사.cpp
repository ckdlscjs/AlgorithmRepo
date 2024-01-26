#include <string>
#include <vector>

using namespace std;
int Pattern[3][40] =
{
    {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
};
vector<int> solution(vector<int> answers) {
    int count[3] = {0, };
    int result_max = 0;
    for(int i = 0; i < answers.size(); i++)
    {
        if(Pattern[0][i%40] == answers[i])
            count[0]++;
        if(Pattern[1][i%40] == answers[i])
            count[1]++;
        if(Pattern[2][i%40] == answers[i])
            count[2]++;
        result_max = std::max(result_max, count[0]);
        result_max = std::max(result_max, count[1]);
        result_max = std::max(result_max, count[2]);
    }
    std::vector<int> answer;
    for(int i = 0; i < 3; i++)
        if(result_max == count[i])
            answer.push_back(i+1);
    return answer;
}