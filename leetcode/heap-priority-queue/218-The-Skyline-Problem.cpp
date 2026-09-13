struct building
{
    int x;
    int y;
    int height;
};
class cmp
{
    public:
        bool operator()(building a,building b)
        {
            if(a.x>b.x)
            {
                return true;
            }
            if(a.x==b.x && a.y<b.y)
            {
                return true;
            }
            if(a.x==b.x && a.y==b.y && a.height<b.height)
            {
                return true;
            }
            return false;
        }
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<building,vector<building>,cmp>pq;
        for(auto b:buildings)
        {
            pq.push({b[0],1,b[2]});
            pq.push({b[1],-1,b[2]});
        }
        vector<vector<int>>ans;
        map<int,int>mp;
        mp[0]=1;
        int prev=0;
        while(!pq.empty())
        {
            int curr_x=pq.top().x;
            while(!pq.empty() && pq.top().x==curr_x)
            {
                building curr=pq.top();
                pq.pop();
                if(curr.y==1)
                {
                    mp[curr.height]++;
                }
                else
                {
                    mp[curr.height]--;
                    if(mp[curr.height]==0)
                    {
                        mp.erase(curr.height);
                    }
                }
            }
            int height=mp.rbegin()->first;
            if(height!=prev)
            {
                ans.push_back({curr_x,height});
                prev=height;
            }
        }
        return ans;
    }
};