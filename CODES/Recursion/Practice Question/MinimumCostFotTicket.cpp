class Solution {
public:

    int mincostTicketHelper(vector<int>&days, vector<int> &costs, int i) {
        //base case
        if(i >= days.size()) 
            return 0;

        //sol for one case
        //1 day pass taken
        int cost1 = costs[0] + mincostTicketHelper(days, costs, i+1);

        //7 days pass taken
        int passEndDay = days[i] + 7-1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + mincostTicketHelper(days, costs, j);

        // 30 days pass taken
        passEndDay = days[i] + 30-1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + mincostTicketHelper(days, costs, j);

        return min(cost1, min(cost7, cost30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return mincostTicketHelper(days, costs, 0);
    }
};