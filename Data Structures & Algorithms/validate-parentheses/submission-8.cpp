class Solution {
public:
    bool isValid(string s) {
        if(s.length() <= 1)
            return false;
        stack<char> st;
        for(int i = 0 ; i < s.length(); i++){
            char temp = s[i];
            if(temp == '[' || temp == '(' || temp == '{'){
                st.push(temp);
            }
            else if(!st.empty() && ((temp == ']' && st.top() == '[') || (temp == '}' && st.top() == '{') || (temp == ')' && st.top() == '('))){
                st.pop();
            }else{
                return false;
            }
                
            
        }
        return st.empty();
    }
};
