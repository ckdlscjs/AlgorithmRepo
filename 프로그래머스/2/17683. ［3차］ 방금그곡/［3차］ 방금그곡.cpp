#include <bits/stdc++.h>

using namespace std;
//음악 제목, 재생이 시작되고 끝난 시각, 악보
//C, C#, D, D#, E, F, F#, G, G#, A, A#, B
std::unordered_map<std::string, char> beats;
std::vector<std::tuple<int, int, std::string>> inputs;
int convert_time(std::string st)
{
    int ret = 0;
    ret += std::stoi(st.substr(0, 2)) * 60;
    ret += std::stoi(st.substr(3, 2));
    return ret;
}
std::string convert_info(std::string info)
{
    std::string beat, ret_info;
    for(int i = info.size()-1; i >= 0; i--)
    {
        if(info[i] == '#')
        {
            beat += info[i];
        }
        else
        {
            beat += info[i];
            std::reverse(beat.begin(), beat.end());
            ret_info += beats[beat];
            beat = "";
        }
    }
    std::reverse(ret_info.begin(), ret_info.end());
    return ret_info;
    //std::cout << convert_info << '\n';
}

string solution(string m, vector<string> musicinfos) 
{
    beats["C"] =    'a';
    beats["C#"] =   'b';
    beats["D"] =    'c';
    beats["D#"] =   'd';
    beats["E"] =    'e';
    beats["F"] =    'f';
    beats["F#"] =   'g';
    beats["G"] =    'h';
    beats["G#"] =   'i';
    beats["A"] =    'j';
    beats["A#"] =   'k';
    beats["B"] =    'l';
    std::string convert_m = convert_info(m);
    for(int idx = 0; idx < musicinfos.size(); idx++)
    {
        auto iter = musicinfos[idx];
        int time_st = convert_time(iter.substr(0, 5));
        iter = iter.substr(6);
        int time_end = convert_time(iter.substr(0, 5));
        iter = iter.substr(6);
        auto dash = iter.find(',');
        std::string name = iter.substr(0, dash);
        std::string info = iter.substr(dash+1);
        //std::cout << time_st << ' ' << time_end << ' '<< name << ' ' <<info << '\n';
        std::string convert = convert_info(info);
        int diff = time_end - time_st - convert.size();
        std::string res_info = convert;
        if(diff > 0)
        {
            int cnt = diff / convert.size();
            for(int i = 0; i < cnt; i++) res_info += convert;
            res_info += convert.substr(0, diff % convert.size());
        }
        else
        {
            res_info = res_info.substr(0, convert.size() + diff);
        }
        //std::cout << res_info << '\n';
        if(res_info.find(convert_m) != std::string::npos)
        {
            inputs.push_back({time_end - time_st, idx, name});
        }
    }
    std::sort(inputs.begin(), inputs.end(), [](const std::tuple<int, int, std::string>& a, const std::tuple<int, int, std::string>& b)->bool{
        int adiff = std::get<0>(a);
        int bdiff = std::get<0>(b);
        int aidx = std::get<1>(a);
        int bidx = std::get<1>(b);
        if(adiff == bdiff)
        {
            return aidx < bidx;
        }
        return adiff > bdiff;
    });
    if(inputs.empty()) return "(None)";
    return std::get<2>(inputs[0]);
}