class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        vector<int> res;
        int N=arr.size();
        unordered_map<int,int> m;
        sort(arr.begin(),arr.end());
        for(int i=0;i<N;i++){
            //cout<<arr[i]<<' ';
            m[arr[i]]++;
        }
        for(int i=0;i<N;i++){
            if(m[arr[i]] && m[arr[i]<<1]){
                if(arr[i]==arr[i]*2){
                    if(m[arr[i]]<=1)continue;
                }
                m[arr[i]]--;
                res.push_back(arr[i]);
                m[arr[i]<<1]--;
                if(m[arr[i]]==0)m.erase(arr[i]);
                if(m[arr[i]<<1]==0)m.erase(arr[i]<<1);
            }
        }
        if(res.size()<<1==N)return res;
        else return {};
    }
};