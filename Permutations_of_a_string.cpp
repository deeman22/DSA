class solution
{
  public:
    vector<string> ans;
    void permutation(string &s, int indx){

              int n = s.length();
              if(indx == n){
                  ans.push_back(s);
                  return ;
              }
              for(int i =indx; i<n; i++){
                  swap(s[indx], s[i]);
                  permutation(s, indx+1);
                  swap(s[indx], s[i]);
              }
       }
	    
	    //
	    //int MAX = 5;
	    vector<string> ans2;
	    string st;
	    bool freq[5] = {0};
	    
	    void permute(string &s){
	        if(st.size() == s.size() ){
	            ans2.push_back(st) ;
	        }
	        
	        for(int i=0; i<s.size(); i++){
	            if(!freq[i]){
	                st.push_back(s[i]);
	                freq[i] = 1;
	                permute(s);
	                freq[i] = 0;
	                st.pop_back();
	            }
	        }
	      }



        vector<string>find_permutation(string S)
        {

                //permutation(S,0);
                //return ans;
                sort(S.begin(), S.end());
                permute(S);
                return ans2;

        }
};
