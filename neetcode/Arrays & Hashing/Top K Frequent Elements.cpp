
// my first solution O(Nlogn)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        map<int,vector<int>> ks;
        for (int i =0; i < nums.size(); i++) {
                counts[nums[i]]++;
        }
        for (auto&p:counts) {
            ks[p.second].push_back(p.first);
        }
        auto last = std::prev(ks.end());
        vector<int> result;
        if (last->second.size() >= k) {
            result.insert(result.end(), last->second.begin(), last->second.end());
        }
        else {
            int i = k;
            while (i >0) {
                result.insert(result.end(), last->second.begin(), last->second.end());
                i = i - last->second.size();
                last = std::prev(last);
            }
        }
        
        return result;
    }
};

// best solution O(N log k) and k = N and a priority queue is used

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) {return nums;}
        unordered_map<int,int> counts;
        for (int i =0; i < nums.size(); i++) {
                counts[nums[i]]++;
        }
        auto comp = [&counts](int n1, int n2) { return counts[n1] > counts[n2];};
        priority_queue<int,vector<int>, decltype(comp)> heap(comp); 
        // decltype tells compiler to use same time as comp
        // priority_queue<T(elements to store), Container, Compare>
        /*This passes your lambda instance into the priority queue constructor because the heap need a comparator object qand must store copy   of the lambda */
        for(pair<int,int>p :counts) {
            heap.push(p.first);
            if (heap.size() > k) heap.pop();
        }
        // whenever we add elemts comp gets called to re order the heap
        vector<int> result(k);
        for (int i = k - 1; i>= 0; i--) {
            result[i] = heap.top();
            heap.pop();
        }
        return result;
    }
};
