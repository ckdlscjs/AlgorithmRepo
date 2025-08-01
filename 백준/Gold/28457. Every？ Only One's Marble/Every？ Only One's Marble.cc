/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
//N 보드의크기, S시작시돈, W월급 G황금열쇠카드개수
int N, S, W, G, I, player, mflag, amount, gidx;
bool lands[40];
std::vector<std::pair<int, int>> GS;
std::vector<std::pair<char, int>> boards;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> S >> W >> G;
    int length = 4*N - 4;
    for(int g = 0; g < G; g++)
    {
        int x, y;
        std::cin >> x >> y;
        GS.push_back({x, y});
    }
    for(int i = 1; i <= length; i++)
    {
        if(i == 1)
        {
            boards.push_back({'s', 0});
        }
        else if(i == N)
        {
            boards.push_back({'m', 0});
        }
        else if(i == (2*N - 1))
        {
            boards.push_back({'a', 0});
        }
        else if(i == (3*N - 2))
        {
            boards.push_back({'p', 0});
        }
        else
        {
            char c;
            std::cin >> c;
            if(c == 'G')
            {
                boards.push_back({'G', 0});
            }
            else
            {
                int v;
                std::cin >> v;
                boards.push_back({'L', v});
            }
        }
    }
    /*
    std::cout << S << W << '\n';
    for(int i = 0; i < boards.size(); i++)
    {
        std::cout << boards[i].first<<boards[i].second << '\n';
    }
    std::cout << '\n';
    */
    std::cin >> I;
    S -= W;
    for(int i = 0; i < I; i++)
    {
        std::pair<int, int> dice;
        std::cin >> dice.first >> dice.second;
        if(player == 0)
            S += W;
        if(mflag)
        {
            if(dice.first == dice.second) 
                mflag = 0;
            else
                mflag--;
            continue;
        }
        player += dice.first + dice.second;
        //std::cout << player << ' ';
        if(player >= length)
        {
            S += W * (player/length);
            player %= length;
        }
        if(boards[player].first == 'L')
        {
            if(lands[player]) continue;
            else if(S < boards[player].second) continue;
            S -= boards[player].second;
            lands[player] = true;
        }
        else if(boards[player].first == 'G')
        {
            auto cur = GS[gidx++];
            gidx %= GS.size();
            int x = cur.first;
            int y = cur.second;
            if(x == 1)
            {
                S += y;
            }
            else if(x == 2)
            {
                S -= y;
                if(S < 0)
                {
                    std::cout << "LOSE";
                    return 0;
                }
            }
            else if(x == 3)
            {
                S -= y;
                amount += y;
                if(S < 0)
                {
                    std::cout << "LOSE";
                    return 0;
                }
            }
            else if(x == 4)
            {
                player += y;
                if(player >= length)
                {
                    S += W * (player/length);
                    player %= length;
                    if(player == 0)
                    S -= W;
                }
                if(boards[player].first == 'L')
                {
                    if(lands[player]) continue;
                    else if(S < boards[player].second) continue;
                    S -= boards[player].second;
                    lands[player] = true;
                }
                else if(boards[player].first == 'p')
                {
                    player = 0;
                }
                else if(boards[player].first == 'm')
                {
                    mflag = 3;
                }
            }
        }
        else if(boards[player].first == 'm')  //무인도
        {
            mflag = 3;
        }
        else if(boards[player].first == 'a') //기금
        {
            S += amount;
            amount = 0;
        }
        else if(boards[player].first == 'p')  //우주여행
        {
            player = 0;
        }
        //std::cout << player << boards[player].first << lands[player] << ' ' << S << i << '\n';
    }
    if(S < 0)
    {
        std::cout << "LOSE";
        return 0;
    }
    for(int i = 0; i < length; i++)
    {
        if(boards[i].first == 'L' && !lands[i])
        {
            std::cout << "LOSE";
            return 0;
        }
    }
    std::cout << "WIN"; 
	return 0;
}

