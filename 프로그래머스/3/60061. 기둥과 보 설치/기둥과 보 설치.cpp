#include <bits/stdc++.h>
using namespace std;

struct Pos {
    int x;
    int y;
    int type;

    Pos(int _x, int _y, int _type) : x(_x), y(_y), type(_type) {}

    bool operator<(const Pos& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return type < other.type;
    }
};

std::set<Pos> builds;

bool PossiblePillar(int x, int y) {
    if (y == 0) return true; // 바닥에 설치
    if (builds.find({x, y - 1, 0}) != builds.end()) return true; // 아래에 기둥이 있음
    if (builds.find({x - 1, y, 1}) != builds.end()) return true; // 왼쪽에 보가 있음
    if (builds.find({x, y, 1}) != builds.end()) return true; // 같은 위치에 보가 있음
    return false;
}

bool PossibleBeam(int x, int y) {
    if (y == 0) return false; // 기둥이 없으면 설치 불가
    if (builds.find({x, y - 1, 0}) != builds.end()) return true; // 왼쪽 기둥
    if (builds.find({x + 1, y - 1, 0}) != builds.end()) return true; // 오른쪽 기둥
    if (builds.find({x - 1, y, 1}) != builds.end() && builds.find({x + 1, y, 1}) != builds.end()) return true; // 양쪽에 보가 있음
    return false;
}

bool DeletePossiblePillar(int x, int y) {
    if (builds.find({x, y + 1, 0}) != builds.end() && !PossiblePillar(x, y + 1)) return false;
    if (builds.find({x, y + 1, 1}) != builds.end() && !PossibleBeam(x, y + 1)) return false;
    if (builds.find({x - 1, y + 1, 1}) != builds.end() && !PossibleBeam(x - 1, y + 1)) return false;
    return true;
}

bool DeletePossibleBeam(int x, int y) {
    if (builds.find({x, y, 0}) != builds.end() && !PossiblePillar(x, y)) return false;
    if (builds.find({x + 1, y, 0}) != builds.end() && !PossiblePillar(x + 1, y)) return false;
    if (builds.find({x - 1, y, 1}) != builds.end() && !PossibleBeam(x - 1, y)) return false;
    if (builds.find({x + 1, y, 1}) != builds.end() && !PossibleBeam(x + 1, y)) return false;
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for (const auto& iter : build_frame) {
        int x = iter[0];
        int y = iter[1];
        int a = iter[2]; // 0: 기둥, 1: 보
        int b = iter[3]; // 1: 설치, 0: 삭제

        if (b == 1) { // 설치
            if (a == 0) { // 기둥
                if (PossiblePillar(x, y))
                    builds.insert({x, y, a});
            } else { // 보
                if (PossibleBeam(x, y))
                    builds.insert({x, y, a});
            }
        } else { // 삭제
             builds.erase({x, y, a});
            if (a == 0) { // 기둥
                if (!DeletePossiblePillar(x, y))
                    builds.insert({x, y, a});
                    
            } else { // 보
                if (!DeletePossibleBeam(x, y))
                    builds.insert({x, y, a});
            }
        }
    }

    vector<vector<int>> answer;
    for (const auto& iter : builds)
        answer.push_back({iter.x, iter.y, iter.type});

    std::sort(answer.begin(), answer.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
                return a[2] < b[2];
            } else {
                return a[1] < b[1];
            }
        } else {
            return a[0] < b[0];
        }
    });

    return answer;
}
