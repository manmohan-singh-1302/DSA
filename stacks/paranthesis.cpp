#include<bits/stdc++.h>
using namespace std;
string check(string s){
    stack<char> st;
    if(s[0]==')' || s[0]=='}' || s[0] == ']')
        return "not balanced";
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else{
                if(!st.empty()){
                    if((s[i]==')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))
                        st.pop();
                    else
                        break;
                }
            }
        }
        if(st.empty())
            return "balanced";
        else
            return "not balanced";
}
int main(){
    string s;
    cin>>s;
    cout<<check(s);
    return 0;
}