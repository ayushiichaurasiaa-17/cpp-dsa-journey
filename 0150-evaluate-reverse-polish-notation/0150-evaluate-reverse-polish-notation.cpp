class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> str;
        for(string token: tokens){
            if(token=="+"||token=="-"||token=="*"||token=="/"){
                long long b=str.top();
                str.pop();
                long long a=str.top();
                str.pop();
                
                if(token=="+")
                    str.push(a+b);
                else if(token=="-")
                    str.push(a-b);
                else if(token=="*")
                    str.push(a*b);
                else if(token=="/")
                    str.push(a/b);
            }
            else
                str.push(stoll(token));
        }
        return (int)str.top();
    }
};