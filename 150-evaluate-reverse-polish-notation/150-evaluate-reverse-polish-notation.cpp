class Solution {
public:
    bool notOperation(string t){
        if(t == "+" || t == "-" || t == "*" || t == "/")return false;
        else return true;
    }
    /*int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto& t : tokens){
		    if(t == "+" || t == "-" || t == "*" || t == "/") {
			    int op1 = s.top(); s.pop();
			    int op2 = s.top(); s.pop();
			    if(t == "+") op1 = op2 + op1;
			    if(t == "-") op1 = op2 - op1;
			    if(t == "/") op1 = op2 / op1;
			    if(t == "*") op1 = op2 * op1;   
			    s.push(op1);
		    }
		    else s.push(stoi(t));    // stoi - converts from string to int 
        }    
	    return s.top();
    TC = O(N) SC = O(N) for the stack
    }*/
    int evalRPN(vector<string>& tokens){
        int top=0;
        for(auto &a : tokens){
            if(notOperation(a))tokens[top++]=a;
            else{
                int op1 = stoi(tokens[--top]);
                int op2 = stoi(tokens[--top]);
                if(a == "+") op1 = op2 + op1;
			    if(a == "-") op1 = op2 - op1;
			    if(a == "/") op1 = op2 / op1;
			    if(a == "*") op1 = op2 * op1;
                tokens[top++]=to_string(op1);
            }
        }
        return stoi(tokens[0]);
    }
};