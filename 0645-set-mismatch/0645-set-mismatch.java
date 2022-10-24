class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int[] cnt  = new int[n+1];
        Arrays.fill(cnt,0);
        for(int i:nums)cnt[i]++;
        int[] res = new int[2];
        for(int i=1;i<=n;i++){
            if(cnt[i]==2)res[0]=i;
            else if(cnt[i]==0)res[1]=i;
        }
        return res;
    }
}