#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int line[2];
    int idx = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = i + 1; j < 3; j++)
        {
            if(dots[i][0] == dots[j][0])
            {
                line[idx++] = std::abs(dots[i][1] - dots[j][1]);
            }
            else
            {
                line[idx++] = std::abs(dots[i][0] - dots[j][0]);
            }
            if(idx >= 2)
                return line[0] * line[1];
        }
    }
}