class Solution {
public:
    bool val(char c, stack<char>& s) {
        if(!s.size())return false;
        if (c == ')') {
            if (s.top() == '(') {
                return true;
            }
        }
        if (c == '}') {
            if (s.top() == '{') {
                return true;
            }
        }
        if (c == ']') {
            if (s.top() == '[') {
                return true;
            }
        }
        return false;
    }
    bool isValid(string s) {
        if(s.size()<=1){
            return false;
        }
        stack<char> stack;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (val(c, stack)){
                stack.pop();
            }else{
                stack.push(c);
            }
        }
        if(stack.size()){
            return false;
        }
        return true;
    }
};