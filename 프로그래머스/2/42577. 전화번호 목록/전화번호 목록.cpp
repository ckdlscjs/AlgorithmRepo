#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    Trie* nodes[10];
    bool finish = false;
    Trie()
    {
        finish = false;
        std::fill_n(nodes, 10, nullptr);
    }
    ~Trie()
    {
        for(int i = 0; i < 10; i++)
            if(nodes[i]) 
                delete nodes[i];
    }
    void Insert(const std::string& str, int idx)
    {
        if(idx >= str.size())
        {
            finish = true;
            return;
        }
        int cur = str[idx] - '0';
        if(nodes[cur] == nullptr) nodes[cur] = new Trie();
        nodes[cur]->Insert(str, idx+1);
    }
    bool Find(const std::string& str, int idx)
    {
        if(idx >= str.size()) return true;
        int cur = str[idx] - '0';
        if(nodes[cur] == nullptr) return false;
        return nodes[cur]->Find(str, idx+1);
    }
};
bool solution(vector<string> phone_book) 
{
    Trie trie;
    std::sort(phone_book.begin(), phone_book.end(), [](std::string& a, std::string& b)->bool{
        return a.size() > b.size();
    });
    for(const auto& iter : phone_book)
    {
        if(trie.Find(iter, 0)) return false;
        trie.Insert(iter, 0);
    }
    
    return true;
}