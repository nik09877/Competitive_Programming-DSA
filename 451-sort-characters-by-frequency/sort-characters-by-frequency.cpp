class Solution {
public:
    string frequencySort(string s) {
       priority_queue<pair<int,char>>pq;
       unordered_map<char,int>mp;
       for(char ch:s)
        mp[ch]++;
        for(auto [ch,cnt]:mp){
            pq.push({cnt,ch});
        }
        string ans="";
        while(pq.size()){
            auto [cnt,ch] = pq.top();
            pq.pop();
            while(cnt--)
                ans+=ch; 
        }
        return ans;
    }
};