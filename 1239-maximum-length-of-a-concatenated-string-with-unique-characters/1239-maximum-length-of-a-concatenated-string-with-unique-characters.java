class Solution {
    public int maxLength(List<String> arr) {
        int n = arr.size(), res=0, tot = 1<<n;
        for(int mask=0;mask<tot;mask++){
            int seen = 0, len=0;
            boolean valid = true;
            for(int i=0;i<n;i++){
                if(((mask>>i)&1) == 0)continue;
                String temp = arr.get(i);
                for(char c:temp.toCharArray()){
                    int j = c-'a';
                    if(((seen>>j)&1)==1){
                        valid = false;
                        break;
                    }
                    len++;
                    seen|=(1<<j);
                }
                if(!valid)break;
            }
            if(valid && len>res)res=len;
        }
        return res;
    }
}