class Solution {
public:
    int totalMoney(int n) {
        // Total weeks 
        int k = n/7;
        // Difference in each week
        int d = 7;
        // First term Arithematic Sequence
        int first_term = 28;
        int last_term = first_term + (k-1)*7;

        // First sequence were all weeks 7 days complete
        int arithmaticSum = k * (first_term + last_term)/2;

        int monday = k+1;
        int finalweek = 0;

        // Second Sequnce for the last week with < 7 days

        for(int day=0; day<n % 7;day++){
            finalweek+=monday+day;
        }
        // Sum of First Sequnce and last week
        int total_money = finalweek + arithmaticSum;

        return total_money;

    }
};