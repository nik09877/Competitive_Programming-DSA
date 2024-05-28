class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        List<Integer> a = new ArrayList<>();
        for(int i=0;i<s.length();i++){
            int cost = (int) Math.abs(s.charAt(i) - t.charAt(i));
            a.add(cost);
        }
        int mxLen = 0;
        int L = 0, R = 0, sum = 0;
        for(;R < s.length();R++){
            sum += a.get(R);
            while(sum > maxCost){
                sum -= a.get(L);
                L++;
            }
            mxLen = Math.max(mxLen,R-L+1); 
        }
        return mxLen;
    }
}