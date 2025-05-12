class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string current_dir;
        stringstream ss(path);

        while (getline(ss, current_dir, '/')) {
            if (current_dir == "" || current_dir == ".") {
                continue;
            } else if (current_dir == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(current_dir);
            }
        }

        string result = "";
        for (const string& dir : stk) {
            result += "/" + dir;
        }

        if (result.empty()) {
            return "/";
        }

        return result;
    }

};