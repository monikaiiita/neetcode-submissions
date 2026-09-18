class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // time complexity --> O(N* N*log(k))
        // with sorting of the string -> O(N* Klog(K))
        // with hash array O(Nlog(N))
         vector<vector<string>>res;
        if(strs.empty()) return res;
        map<map<char,int>,vector<string>>output;
        for(string str:strs){
            map<char,int>frmp;
            for (char ch :str){
                 if(frmp.find(ch)!=frmp.end())frmp[ch]++;
                 else frmp[ch]=1;
            }
            vector<string>st;
            if(output.find(frmp)!=output.end())
            output[frmp].push_back(str);
            else{
                st.push_back(str);
                output[frmp]=st; 
                }
        }
       
        for(auto &p: output){
            res.push_back(p.second);
            }
        return res;
    }


};
