class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        int totalWords = words.size();
        if (totalWords == 0) return answer;
        int wordLength = words[0].size();
        int concatLength = wordLength * totalWords;
        if (s.size() < concatLength) return answer;

        unordered_map<string, int> freq;
        for (const string& word : words) freq[word]++;

        for (int offset = 0; offset < wordLength; offset++) {
            unordered_map<string, int> seen;
            int left = offset, count = 0;
            for (int right = offset; right + wordLength <= s.size(); right += wordLength) {
                string word = s.substr(right, wordLength);
                if (freq.count(word)) {
                    seen[word]++;
                    count++;
                    while (seen[word] > freq[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seen[leftWord]--;
                        left += wordLength;
                        count--;
                    }
                    if (count == totalWords) answer.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = right + wordLength;
                }
            }
        }
        return answer;
    }
};