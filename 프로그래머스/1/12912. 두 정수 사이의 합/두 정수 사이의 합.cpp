#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int minval = std::min(a,b);
    int maxval = std::max(a,b);
    for(minval; minval <= maxval; minval++)
        answer += minval;
    return answer;
}