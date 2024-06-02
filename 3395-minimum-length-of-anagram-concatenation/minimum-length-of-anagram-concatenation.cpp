class Solution {
public:
    bool check(string& s,int len){
        int n = s.size();
        vector<int>cnt(26,0);
        for(int i=0;i<len;i++)
            cnt[s[i]-'a']++;
        
        for(int i=len;i+len<=n;i+=len){
            vector<int>temp(cnt);
            
            string str = s.substr(i,len);

            for(auto c:str)
                temp[c-'a']--;
            
            for(auto count:temp)
                if(count!=0)
                    return false;
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n = s.size();
        int ans = n;

        for(int i=1;i*i<=n;i++){
            if(n%i!=0)
                continue;
            if(check(s,i))
                ans = min(ans,i);
            if(n/i != i and check(s,n/i))
                ans = min(ans,n/i);
        }
        return ans;
    }
};