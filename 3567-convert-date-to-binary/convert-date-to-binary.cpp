class Solution {
public:
    string convertDateToBinary(string date) {
        stringstream ss(date);
        string part, res = "";
        vector<string> parts;
        while (getline(ss, part, '-')) parts.push_back(part);
        for (int i = 0; i < parts.size(); i++) {
            int num = stoi(parts[i]);
            string bin = bitset<32>(num).to_string();
            bin = bin.substr(bin.find('1'));
            res += bin;
            if (i != parts.size() - 1) res += "-";
        }
        return res;
    }
};