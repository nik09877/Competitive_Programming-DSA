class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        unordered_set<char>dist_chars;
        unordered_set<string>dict;
        vector<vector<int>>valid_ideas(26,vector<int>(26,0));
        
        for(string& idea:ideas)
        {
            dist_chars.insert(idea[0]);
            dict.insert(idea);
        }
        
        for(string& idea:ideas)
        {
            char first_letter_of_idea = idea[0];
            for(char other_first_letter:dist_chars)
            {
                
                if(first_letter_of_idea == other_first_letter)
                    continue;
                
                // string new_idea = other_first_letter + idea.substr(1);
                if(dict.count(other_first_letter + idea.substr(1))==0)
                {
                    valid_ideas[first_letter_of_idea-'a'][other_first_letter-'a'] += 1; 
                }
                
            }    
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j)
                    continue;
                ans+=(valid_ideas[i][j]*1ll*valid_ideas[j][i]);
            }
        }
        return ans;
    }
};