#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) 
{
    std::sort(numbers.begin(), numbers.end());
    return std::max(numbers[0]*numbers[1], numbers[numbers.size()-1] * numbers[numbers.size()-2]);
}