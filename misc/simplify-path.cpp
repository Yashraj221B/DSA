#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        vector<string> dirs;
        string dir = "";
        for(int i = 0; i < path.length(); i++){
            if(path[i] == '/'){
                if(dir.length() != 0) dirs.push_back(dir);
                if(i + 2 < len && path[i+1] == '.' && path[i+2] == '/') i+= 1;
                if(i + 3 < len && path[i+1] == '.' && path[i+2] == '.' && path[i+3] == '/'){
                    if(dirs.size() != 0) dirs.pop_back();
                    i+=2;
                }
                dir = "";
            }else{
                dir.push_back(path[i]);
            }
        }
        if(dir.length() != 0){
            if(dir == ".."){
                if(!dirs.empty()) dirs.pop_back();
            }
            else if(dir != "" && dir != "."){
                dirs.push_back(dir);
            }
        }
        if(dirs.size() == 0) return "/";
        string str = "";
        for(auto x: dirs){
            str+=('/'+x);
        }
        return str;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string path;
    while (getline(cin, path)) {
        Solution sol;
        cout << sol.simplifyPath(path) << '\n';
    }
    return 0;
}