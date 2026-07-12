    #include <bits/stdc++.h>
    using namespace std;

    void solve(int idx ,unordered_map<char , string>mp ,string &temp , string &digits,vector<string>&result ){
        if(idx >=(int)digits.length()){
            result.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];

        for(int i=0;i < str.length();i++){

            temp.push_back(str[i]);

            solve(idx+1 , mp , temp , digits , result);

            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;
       unordered_map<char , string>mp;

       mp['2']="abc";
       mp['3']="def";
       mp['4']="ghi";
       mp['5']="jkl";
       mp['6']="mno";
       mp['7']="pqrs";
       mp['8']="tuv";
       mp['9']="wxyz";
       
       string temp="";

       solve(0,mp,temp,digits,result);
       return result;

    }

    int main(){
        string digits="234";
        vector<string>ans = letterCombinations(digits);

        for(string x:ans){
            cout<<x<<" "<<endl;
        }
        return 0;
    }
