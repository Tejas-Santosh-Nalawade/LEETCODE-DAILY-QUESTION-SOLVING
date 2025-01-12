class Solution {
public:
    bool canBeValid(string s, string locked) {
        int length= s.size();
        if(length%2==1){
            return false;
        }
        stack<int> openbrackets,unlocked;
        for(int i=0; i<length; i++){
            if(locked[i]=='0'){
                unlocked.push(i);
            }else if(s[i]=='('){
                openbrackets.push(i);
            } else if(s[i]==')'){
                if(!openbrackets.empty()){
                    openbrackets.pop();
                } else if(!unlocked.empty()){
                    unlocked.pop();
                } else{
                    return false; 
                }
            }
        }
        while(!openbrackets.empty() && !unlocked.empty() && openbrackets.top()<unlocked.top() ){
                openbrackets.pop();
                unlocked.pop();
            }
            if(! openbrackets.empty()){
                return false;
            }
             return true;
        }
       
};