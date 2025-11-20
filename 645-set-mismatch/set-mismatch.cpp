class Solution {
public:
/*
    Observation 

    We use the isPoosible bool array as help for calculating
    the duplicate value and the missing value 
    and ans array for final answer storing

    its size is n+1 because number start from 1 to n so n+1

    First traverse we check duplicate value were were check 
    the isPossible array and index are the value of main 
    array if it came false then set true  and if true then insert into 
    ans vector 

    Second Traverse we check what is missing will check isPoosible array 
    check from 1 index as number are natutal number and add into ans vector 
    were value is false and break 

    Through these 2 traverse and isPoosible  bool vector 
    return ans



*/
vector<int> findErrorNums(vector<int>&nums){
    int n = nums.size();
    vector<int> isPossible(n+1, false);
    vector<int>ans;
    // For adding the duplicate value in ans vector
    for(int i=0; i<n; i++){
        if(isPossible[nums[i]]){
            ans.push_back(nums[i]);
        }
        isPossible[nums[i]] = true;
    }

    // For adding the removed Element 

    for(int i=1; i<isPossible.size(); i++){
        if(!isPossible[i]){
            ans.push_back(i);
            break;
        }
    }
    return ans;
    }
};