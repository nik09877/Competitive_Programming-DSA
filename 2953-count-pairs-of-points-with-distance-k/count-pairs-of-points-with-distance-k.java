class Solution {
    public int countPairs(List<List<Integer>> coordinates, int k) {
        Map<List<Integer>,Integer>hashedCoordinates = new HashMap<>();
        int ans = 0;
        for(var coordinate: coordinates ){
            int x = coordinate.get(0);
            int y = coordinate.get(1);
            for(int x_sum=0;x_sum<=k;x_sum++){
                int y_sum = k - x_sum;
                int pre_x = x ^ x_sum;
                int pre_y = y ^ y_sum;
                int cnt = hashedCoordinates.getOrDefault(Arrays.asList(pre_x,pre_y),0);
                ans+=cnt;
            }
            int cur_cnt = hashedCoordinates.getOrDefault(coordinate,0);
            hashedCoordinates.put(coordinate,cur_cnt+1);
        }
        return ans;
    }
}