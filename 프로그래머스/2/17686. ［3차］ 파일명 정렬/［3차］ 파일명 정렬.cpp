#include <bits/stdc++.h>
using namespace std;
bool compare(const std::string& a, const std::string& b)
{
    int idx = 0;
    std::string temp = "";
    std::string file1[3] = {"", "", ""};
    std::string file2[3] = {"", "", ""};
    for(const auto& iter : a)
    {
        if(idx == 0 && '0' <= iter &&  iter <= '9')
        {
            file1[idx++] = temp;
            temp.clear();
        }
        else if(idx == 1 && !('0' <= iter && iter <= '9'))
        {
            file1[idx++] = temp;
            temp.clear();
        }
        temp += iter;
    }
    if(idx < 2)
    {
        file1[idx++] = temp;
        temp.clear();
    }
    file1[idx] = temp;
    temp.clear();
    idx = 0;

    
    for(const auto& iter : b)
    {
        if(idx == 0 && '0' <= iter && iter <= '9')
        {
            file2[idx++] = temp;
            temp.clear();
        }
        else if(idx == 1 && !('0' <= iter && iter <= '9'))
        {
            file2[idx++] = temp;
            temp.clear();
        }
        temp += iter;
    }
    if(idx < 2)
    {
        file2[idx++] = temp;
        temp.clear();
    }
    file2[idx] = temp;
    
    /*
    for(const auto& iter : file1)
    {
        std::cout << iter << ' ';
    }
    std::cout << ":";
    for(const auto& iter : file2)
    {
        std::cout << iter << ' ';
    }
    std::cout <<'\n';
    */
    int len = std::min(file1[0].size(), file2[0].size());
    for(int i = 0; i < len; i++)
    {
        int f_ch1 = 0, f_ch2 = 0;
        if(('A' <= file1[0][i] && file1[0][i]<='Z') || ('a' <= file1[0][i] && file1[0][i] <= 'z'))
            f_ch1 = file1[0][i] >= 'a' ? file1[0][i] -'a' : file1[0][i] -'A';
        else
            f_ch1 = file1[0][i];
            
        if(('A' <= file2[0][i] && file2[0][i]<='Z') || ('a' <= file2[0][i] && file2[0][i] <= 'z'))
            f_ch2 = file2[0][i] >= 'a' ? file2[0][i] -'a' : file2[0][i] -'A';
        else
            f_ch2 = file2[0][i];
    
        if(f_ch1 == f_ch2)
            continue;
        return f_ch1 < f_ch2;    
    }
    if(file1[0].size() != file2[0].size())
        return file1[0].size() < file2[0].size();
    
    //std::cout << std::stoi(file1[1]) << ":" << std::stoi(file2[1]) <<'\n';
    if(std::stoi(file1[1]) != std::stoi(file2[1]))
        return std::stoi(file1[1]) < std::stoi(file2[1]);
}
vector<string> solution(vector<string> files) 
{
    std::stable_sort(files.begin(), files.end(), compare);
    return files;
}