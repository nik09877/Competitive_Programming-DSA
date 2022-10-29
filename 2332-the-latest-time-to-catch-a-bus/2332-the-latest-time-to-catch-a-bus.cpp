class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& a, vector<int>& b, int cap) {
        map<int,int>mp;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(auto x:b)mp[x]++;
        int m = b.size();
        int j=0,rem;
        for(int i=0;i<a.size();i++){
            rem = cap;
            while(j<m and b[j]<=a[i] and rem){
                rem--;
                j++;
            }
        }
        if(rem==0)
        {
            j--;
            int x = b[j];
            while(mp[x])
                x--;
            return x;
        }
        int x = a.back();
        while(mp[x])
            x--;
        return x;
    }
};