#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) 
{
    int sqr = std::sqrt(brown+yellow);
    int width = sqr, height = sqr;
    int b = 0, y = 0;
    while(width*height != (brown+yellow) || b != brown || y != yellow)
    {
        b = width*2 + (height*2)-4;
        y = brown+yellow-b;   
        if(width*height < brown+yellow)
        {
            width++;
        }
        else if(width * height > brown+yellow)
        {
            height--;
        }
        else
        {
            if(b < brown)
                width++;
            else if(b > brown)
                width--;
            if(y < yellow)
                height++;
            else if(y > yellow)
                height--;
        }
    }
    return {width, height};
}