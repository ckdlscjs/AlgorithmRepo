#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    int val_max = std::max(n, m);
    int val_min = std::min(n, m);
    while(val_max % val_min)
    {
        int gcd = val_max % val_min;
        val_max = val_min;
        val_min = gcd;
    }
    return {val_min, n*m/val_min};
}