class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String s1 = new String(), s2 = new String();
        for(String s:word1)s1+=s;
        for(String s:word2)s2+=s;
        int n1 = s1.length(), n2 = s2.length();
        if(n1!=n2)return false;
        for(int i=0;i<n1;i++){
            if(s1.charAt(i)!=s2.charAt(i))return false;
        }
        return true;
    }
}