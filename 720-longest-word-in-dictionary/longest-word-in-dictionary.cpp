class TrieNode{
    public: 
        TrieNode* children[26];
        bool isEnd;
        string str;
        TrieNode()
        {
            isEnd = false;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
        }
};

class Solution {
public:
    void insert(TrieNode* root, string word)
    {
        TrieNode* curr =root;
        for(int i=0; i<word.size(); i++)
        {
            int index = word[i] -'a';
            if(curr->children[index]==NULL)
            {
                curr->children[index]= new TrieNode();
            }     
            curr = curr->children[index];
        } 
        curr->isEnd = true;
        curr->str = word;
    }

    void dfs(TrieNode*curr,string &ans){
        for(int i=0; i<26; i++)
        {
            if(curr->children[i]!=NULL && curr->children[i]->isEnd==true){
                if(ans.length() < curr->children[i]->str.length()){
                    ans = curr->children[i]->str;
                }
                else if(ans.length()==curr->children[i]->str.length()){
                    if(curr->children[i]->str < ans){
                        ans = curr->children[i]->str;
                    }
                }
                dfs(curr->children[i],ans);
            }
        }
        return;
    }


    string longestWord(vector<string>& words) {
        int n = words.size();
        TrieNode* root = new TrieNode();
        for(int i=0; i<n; i++)
        {
            insert(root,words[i]);
        }
        string ans =  "";
        dfs(root,ans);
        return ans;
    }
};