class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if(strs==null || strs.length==0)return new ArrayList<>();
        HashMap<String,List<String>> m =  new HashMap<>();
        for(String s:strs){
            char[] ca = new char[26];
            for(char c:s.toCharArray())ca[c-'a']++;
            String key = String.valueOf(ca);
            if(!m.containsKey(key))m.put(key,new ArrayList<>());
            m.get(key).add(s);
        }
        return new ArrayList<>(m.values());
    }
}