#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
class Solution {
public:
    
    const string vowel="aeiou"; 
    const  int vowels = sz(vowel);
    
    
    int count(int ind,int words,int n){
        if(ind>vowels || words==n)return 1;
        
        int sum=0;
        
        for(int i=ind;i<vowels;i++){
            sum+=count(i,words+1,n);
        }
        
        return sum;
    }
    
    int countVowelStrings(int n) {
        return count(0,0,n);
    }
};