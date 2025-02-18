#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int calc_dist(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
{
    return std::abs(p1.first - p2.first) + std::abs(p1.second - p2.second);
}
struct Robot
{
    std::pair<int, int> c;
    std::queue<std::pair<int, int>> q;
    Robot(const std::vector<std::vector<int>>& points, const std::vector<int>& routes)
    {
        c = std::make_pair(points[routes[0]-1][0], points[routes[0]-1][1]);
        for(int i = 0; i < routes.size(); i++)
            q.push(std::make_pair(points[routes[i]-1][0], points[routes[i]-1][1]));
    }
};
int solution(vector<vector<int>> points, vector<vector<int>> routes) 
{
    int answer = 0;
    std::vector<Robot> robots;
    for(int i = 0; i < routes.size(); i++) robots.push_back(Robot(points, routes[i]));
    int cnt = robots.size();
    while(cnt > 0)
    {
        std::map<std::pair<int, int>, int> collisions;
        for(auto& robot : robots)
        {
            if(robot.q.empty()) continue;
            int dist_cur = calc_dist(robot.c, robot.q.front());
            if(dist_cur <= 0)
            {
                robot.q.pop();
                collisions[robot.c]++;
                continue;
            }
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = robot.c.first + dy[dir];
                int nx = robot.c.second + dx[dir];
                if(ny < 0 || nx < 0 || ny > 100 || nx > 100) continue;
                std::pair<int, int> npos = std::make_pair(ny, nx);
                int dist_npos = calc_dist(npos, robot.q.front());
                if(dist_npos >= dist_cur) continue;
                robot.c = npos;
                if(dist_npos <= 0)
                {
                    robot.q.pop();
                    if(robot.q.empty()) cnt--;
                }
                collisions[robot.c]++;
                break;
            }
        }
        for(const auto& iter : collisions)
        {
            //std::cout << iter.first.first << ' ' << iter.first.second << ", ";
            if(iter.second >= 2)
            {
                //std::cout << "!!!";
                answer++;
            }
        }
        //std::cout<< '\n';
    }
    
    return answer;
}