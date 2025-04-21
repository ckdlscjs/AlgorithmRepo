#include <bits/stdc++.h>
using namespace std;
int S, P, cnts[4], needs[4], cnt;
std::string str;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> S >> P >> str;
    for(int i = 0; i < 4; i++) std::cin >> needs[i];
    for(int i = 0; i < P-1; i++)
    {
        if(str[i] == 'A') cnts[0]++;
        else if(str[i] == 'C') cnts[1]++;
        else if(str[i] == 'G') cnts[2]++;
        else if(str[i] == 'T') cnts[3]++;
    }
    for(int l = 0; l + P <= S; l++)
    {
        if(str[P-1+l] == 'A') cnts[0]++;
        else if(str[P-1+l] == 'C') cnts[1]++;
        else if(str[P-1+l] == 'G') cnts[2]++;
        else if(str[P-1+l] == 'T') cnts[3]++;
        if(cnts[0] >= needs[0] && cnts[1] >= needs[1] && cnts[2] >= needs[2] && cnts[3] >= needs[3])
            cnt++;
        if(str[l] == 'A') cnts[0]--;
        else if(str[l] == 'C') cnts[1]--;
        else if(str[l] == 'G') cnts[2]--;
        else if(str[l] == 'T') cnts[3]--;
    }
    std::cout << cnt;
    return 0;
}