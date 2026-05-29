class MedianFinder {
   public:
    MedianFinder() = default;

    void addNum(int num) {
        if (!maxHeap.empty() && num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            int const top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        } else if (minHeap.size() > maxHeap.size() + 1) {
            int const top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
    }

    double findMedian() {
        double result;

        if (maxHeap.size() > minHeap.size()) {
            result = maxHeap.top();
        } else if (minHeap.size() > maxHeap.size()) {
            result = minHeap.top();
        } else {
            result = (maxHeap.top() + minHeap.top()) * 0.5;
        }

        return result;
    }

    priority_queue<int, vector<int>, less<>> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
};
