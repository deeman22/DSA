class Solution{
public:
    vector<string> ans;
    unordered_map<string,bool> mp;
   
//   vector<string> helper(string str,int i,int j){
//       vector<string> ans;
       
//       string temp = str.substr(i,j-i+1);
//       if(mp[temp]) ans.push_back(temp);
       
//       for(int k = i; k < j; k++){
//           string left = str.substr(i,k-i+1);
//           if(mp[left]){
//               vector<string> v = helper(str,k+1,j);
//               for(auto right: v){
//                   ans.push_back(left + " " + right);
//               }
//           }
//       }
       
//       return (ans);
//   }
   
   void solve(string &s,string &v,int pos)
  {
      if(pos==s.size())
      {
          v.pop_back();
          ans.push_back(v);
          return;
      }
      
      string temp="";
      for(int i=pos;i<s.size();++i)
      {
          temp+=s[i];
          if(mp.find(s.substr(pos,i-pos+1))!=mp.end())
          {
              string p=v+temp+" ";
              solve(s,p,i+1);
             
          }
      }
  }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        for(auto str: dict){
           mp[str] = true;
       }
       //return helper(s,0,s.length()-1);
        string str;
        solve(s,str,0);
        return ans;
    }
};
