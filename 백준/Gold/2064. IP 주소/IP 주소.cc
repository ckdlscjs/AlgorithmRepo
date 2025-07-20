/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N;
std::vector<unsigned int> ips;
unsigned int common = 0xffffffff, diff;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::string str;
        std::cin >> str;
        str += '.';
        auto iter = str.find('.');
        unsigned int curip = 0;
        int shift = 24;
        while(iter != std::string::npos)
        {
            unsigned int num = std::stoi(str.substr(0, iter));
            num <<= shift;
            curip |= num;
            shift -= 8;
            //std::cout << shift << ' ';
            str = str.substr(iter+1);
            iter = str.find('.');
        }
        ips.push_back(curip);
        common &= curip;
    }
    for(const auto& iter : ips) 
        diff |= common^iter;
    unsigned int shift = 0;
    while(diff)
    {
        shift++;
        diff >>= 1;
    }
    unsigned int bitmask = shift < 32 ? 0xffffffff << shift : 0;
    unsigned int first = bitmask & common;
    std::function<std::string(unsigned int)> func = [](unsigned int ip) -> std::string {
        return std::to_string((ip >> 24) & 255) + "." + std::to_string((ip >> 16) & 255) + "." + std::to_string((ip >> 8) & 255) +"."+ std::to_string(ip & 255);
    };
    std::cout << func(first) << '\n' << func(bitmask);
	return 0;
}

