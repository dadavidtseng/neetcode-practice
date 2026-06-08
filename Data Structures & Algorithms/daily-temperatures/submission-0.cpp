class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> s;

        for (int i = 0; i < static_cast<int>(temperatures.size()); ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int const idx = s.top();

                s.pop();
                result[idx] = i - idx;
            }

            s.push(i);
        }

        return result;
    }
};
