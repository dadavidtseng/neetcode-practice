class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int result = stoi(tokens[0]);
        int const tokensSize = static_cast<int>(tokens.size());
        stack<int> s;

        if (tokensSize == 1) {
            return result;
        }

        for (int i = 0; i < tokensSize; ++i) {
            if (tokens[i] == "+") {
                int const a = s.top();
                s.pop();
                int const b = s.top();
                s.pop();
                result = (b + a);
                s.push(result);
            } else if (tokens[i] == "-") {
                int const a = s.top();
                s.pop();
                int const b = s.top();
                s.pop();
                result = (b - a);
                s.push(result);
            } else if (tokens[i] == "*") {
                int const a = s.top();
                s.pop();
                int const b = s.top();
                s.pop();
                result = (b * a);
                s.push(result);
            } else if (tokens[i] == "/") {
                int const a = s.top();
                s.pop();
                int const b = s.top();
                s.pop();
                result = (b / a);
                s.push(result);
            } else {
                s.push(stoi(tokens[i]));
            }
        }

        return result;
    }
};
