#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int sum = 0;
    int coupon = chicken;
    while(coupon >= 10)
    {
        sum += coupon / 10;
        coupon = coupon / 10 + coupon %10;
    }
    return sum;
}