class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int result = stoi(tokens[0]);
        stack<string> s;

        if (tokens.size() == 1) {
            return result;
        }

        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                result = (b + a);
                s.push(std::to_string((b + a)));
            } else if (tokens[i] == "-") {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                result = (b - a);
                s.push(std::to_string((b - a)));
            } else if (tokens[i] == "*") {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                result = (b * a);
                s.push(std::to_string((b * a)));
            } else if (tokens[i] == "/") {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                result = (b / a);
                s.push(std::to_string((b / a)));
            } else {
                s.push(tokens[i]);
            }
        }

        return result;
    }
};
