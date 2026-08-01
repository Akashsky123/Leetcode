class MedianFinder {
public:
    priority_queue<int> maxHeap; // Stores smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Stores larger half

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Step 1: Add to maxHeap
        maxHeap.push(num);

        // Step 2: Move the largest element of maxHeap to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: Balance the heaps
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};