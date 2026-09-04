class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : kth(k) {

        for (auto num : nums)
        {
            que.push(num);
        }
    }
    
    int add(int val) {

        int kthElement = 0;

        que.push(val);

        std::vector<int> popped;

        // pop element off until we get to the kth element
        for (int i=0; i  < kth; ++i)
        {
            if (i == kth-1)
            {
                std::cout <<  que.top() <<  " ";
                kthElement = que.top();    
            }
            else
            {
                std::cout <<  que.top() <<  " ";
                popped.push_back(que.top());
                que.pop();
            }
        }

        std::cout << std::endl; 

        // push elements back onto the que
        for (auto p: popped)
        {
            que.push(p);
        }

        return kthElement; 
    }

    std::priority_queue<int> que;    
    int kth = 0;
};
