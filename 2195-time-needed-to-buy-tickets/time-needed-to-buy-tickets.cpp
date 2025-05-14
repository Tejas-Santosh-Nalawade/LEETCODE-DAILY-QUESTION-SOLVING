class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> queue;
        int time = 0;
        for (int i = 0; i < n; ++i)
        {
            queue.push(i);
        }
        while (tickets[k] > 0)
        {
            int currentPerson = queue.front();
            queue.pop();
            tickets[currentPerson]--;
            time++;

            if (tickets[currentPerson] > 0)
            {
                queue.push(currentPerson);
            }
        }
        return time;
    }
};