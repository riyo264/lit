class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }
        vector<int>hash(256,0);

        int l=0,r=0,minlen=INT_MAX,sind=-1,cnt=0;

        int n=s.size(),m=t.size();

        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }

        while(r<n){

            if(hash[s[r]]>0){
               cnt++;
            }
            hash[s[r]]--;
            
            while(cnt==m){

                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sind=l;
                }
                hash[s[l]]++;

                if(hash[s[l]]>0){
                    cnt=cnt-1;
                }

                l++;
            }
            r=r+1;
        }
        
        return sind==-1?"":s.substr(sind,minlen);
    }
};