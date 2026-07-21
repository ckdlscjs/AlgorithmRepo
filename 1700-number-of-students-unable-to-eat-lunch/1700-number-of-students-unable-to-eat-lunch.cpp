auto fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
class Solution 
{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        std::queue<int> q(students.begin(), students.end());
        for(const auto& iter : sandwiches)
        {
            int cnt = q.size();
            while(!q.empty() && q.front() != iter && cnt)
            {
                q.push(q.front());
                q.pop();
                cnt--;
            }
            if(cnt > 0)
                q.pop();
            else
                break;
        }
        return q.size();
    }
};