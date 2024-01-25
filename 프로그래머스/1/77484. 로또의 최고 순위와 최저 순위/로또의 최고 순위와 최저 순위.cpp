#include <string>
#include <vector>

using namespace std;
int check[70];
int rating[10];
vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    rating[6] = 1;
    rating[5] = 2;
    rating[4] = 3;
    rating[3] = 4;
    rating[2] = 5;
    rating[1] = 6;
    rating[0] = 6;
    for(const int& num : lottos)
        check[num]++;
    int count = 0;
    for(const int& num : win_nums)
    {
        if(check[num])
            count++;
    }
    
    return {rating[count+check[0]], rating[count]};
}