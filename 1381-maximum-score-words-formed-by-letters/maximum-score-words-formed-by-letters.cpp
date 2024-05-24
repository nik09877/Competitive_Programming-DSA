class Solution {
public:
   int solve(vector<string>& words, vector<int>& freq, vector<int>& score, int idx){
       if(idx==words.size())
           return 0;
       //if we don't include word at index 'idx'
       int sNo=solve(words,freq,score,idx+1);
       
       //if we include word at index 'idx'
       int sYes=0;
       int scoreOfWord=0;
       int flag=1; 
       //calculate below
       for(int i=0;i<words[idx].length();i++){
           char c=words[idx][i];
           
           if(freq[c-'a']==0)  //char 'c' not left in freq
               flag=0;
           freq[c-'a']--;
           scoreOfWord+=score[c-'a'];
       }
       
       if(flag==1){
           sYes=scoreOfWord+solve(words,freq,score,idx+1);
       } 
       //restore the freq array 
       for(int i=0;i<words[idx].length();i++){
           char c=words[idx][i];
           freq[c-'a']++;
           
       }
       return max(sNo,sYes);
       
   }
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        for(int i=0;i<letters.size();i++){
            freq[letters[i]-'a']++;
        }
        return solve(words,freq,score,0);
        
    }
};