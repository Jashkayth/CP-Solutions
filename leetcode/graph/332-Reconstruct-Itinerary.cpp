using pq = priority_queue<string,vector<string>,greater<string>>;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,pq>mp;
        for(auto it:tickets)
        {
            mp[it[0]].push(it[1]);
        }
        vector<string>res;
        stack<string>st;
        st.push("JFK");
        while(!st.empty())
        {
            string front=st.top();
            if(mp[front].empty())
            {
                res.push_back(front);
                st.pop();
            }
            else
            {
                st.push(mp[front].top());
                mp[front].pop();
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};