//
// Created by 53110 on 2022/4/13.
//

#include <unordered_map>
#include <vector>
#include <random>
#include <ctime>
using namespace std;
class Solution380{
private:
    vector<int> nums;
    unordered_map<int, int> indices;
public:
    void RandomizedSet(){
        srand((unsigned) time(nullptr));
    }
    bool insert(int val){
        if (indices.count(val)){
            return false;
        }
        int index = nums.size();
        indices[val] = index;
        nums.emplace_back(val);
        return true;
    }

    bool remove(int val){
        if(!indices.count(val)) return false;
        int index = indices[val];
        int temp = nums.back();
        nums[index] = temp;
        indices[temp] = index;
        nums.pop_back();
        indices.erase(val);
        return true;
    }
    int getRandom(){
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }

};