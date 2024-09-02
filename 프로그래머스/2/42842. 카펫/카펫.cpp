#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int height = 3, width = 3;
    for(height; height <= std::sqrt(brown+yellow); height++)
    {
        if((brown+yellow) % height != 0)
            continue;
        width = (brown+yellow)/height;
        int b = width*2 + height*2-4;
        int y = brown+yellow-b;
        if(b == brown && y == yellow && width*height == brown+yellow)
            break;
    }
    return {width, height};
}