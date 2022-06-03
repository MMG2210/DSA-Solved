class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] cnt = new int[26];
        int e=0,maxCnt=-1,sz=tasks.length;
        for(char t:tasks)cnt[t-'A']++;
        for(int i=0;i<26;i++){
            maxCnt=Math.max(maxCnt,cnt[i]);
        }
        for(int i=0;i<26;i++)if(cnt[i]==maxCnt)e++;
        return Math.max(sz,(maxCnt-1)*(n+1)+e);
    }
}