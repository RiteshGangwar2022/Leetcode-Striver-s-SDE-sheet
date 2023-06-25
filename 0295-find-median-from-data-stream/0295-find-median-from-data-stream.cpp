class MedianFinder {
public:
    
  
    
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    
    MedianFinder() {
        
         // vector<int>nums;
    /*we can solve it using priority_queue
    1)take two priority queue and push the elements accoding to conditions
      *maxheap will store all the smaller elements and min-heap will store all the greater element
    */
         return;
    }
    
    void addNum(int num) {
       /* nums.push_back(num);
        return;*/
        
        //using max and min heap
        
        //if there is no element in maxheap or num is smaller than the top of max-heap, then ,push it into maxi , else into mini,
        //TC -=>O(nlogn), performing push operation on n elements
      if(maxHeap.empty() or maxHeap.top() > num)
        {
          maxHeap.push(num);
        }
        else
        {
          minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size()+1)
        {
          minHeap.push(maxHeap.top());
          maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1)
        {
          maxHeap.push(minHeap.top());
          minHeap.pop();
        }
            
    }
    
    double findMedian() {
        
        //TLE=.taking O(n*nlogn), performing sorting on n elements
       /* sort(nums.begin(),nums.end());
        int size=nums.size();
        if(size%2!=0){
             int mid=size/2;
             double ans=nums[mid];
            return ans;
        }
        else{
            int mid=size/2;
            double first=nums[mid];
            double second=nums[mid-1];
            double ans=double(first+second)/2;
            return ans;
        }*/
        
        
        //finding median using priority_queue
        
        if(maxHeap.size() == minHeap.size())
        {
          if(maxHeap.empty())
          {
            return 0;
          }
          else
          {
            double avg = double(maxHeap.top() + minHeap.top()) / 2;
            return avg;
          }
        }
        else {
                
            if(maxHeap.size()>minHeap.size()){
                
                double ans=maxHeap.top();
                return ans;
            }
            else{
                double ans=minHeap.top();
                return ans;
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */