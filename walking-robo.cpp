#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, max_dist = 0, dir = 0;
        set<pair<int,int>> obs;
        for (auto &&cmd : commands)
        {
            switch (cmd)
            {
            case -1:
                if(dir == 3) dir = 0;
                else dir++;
                break;
            case -2:
                if(dir == 0) dir = 3;
                else dir--;
                break;
            default:
                switch (dir)
                {
                case 0:
                    for (size_t i = 0; i < cmd; i++)
                    {
                        if(obs.find({x, y+1}) != obs.end()) break;
                        y++;
                    }
                    break;
                case 1:
                    for (size_t i = 0; i < cmd; i++)
                    {
                        if(obs.find({x+1, y}) != obs.end()) break;
                        x++;
                    }
                    break;
                case 2:
                    for (size_t i = 0; i < cmd; i++)
                    {
                        if(obs.find({x, y-1}) != obs.end()) break;
                        y--;
                    }
                    break;
                case 3:
                    for (size_t i = 0; i < cmd; i++)
                    {
                        if(obs.find({x-1, y}) != obs.end()) break;
                        x--;
                    }
                    break;
                }
                max_dist = max(max_dist, x*x + y*y);
            }
        }
        return max_dist;
    }
};