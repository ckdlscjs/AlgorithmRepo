#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int a = std::max(n, 6);
    int b = std::min(n, 6);
    while(a % b != 0)
    {
        int gcd = a % b;
        a = b;
        b = gcd;
    }
    return (n * 6 / b) / 6;
}