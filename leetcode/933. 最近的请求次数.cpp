#include <vector>
#include <queue>
using namespace std;

class RecentCounter {
private:
    vector<int> requests;
public:
    // queue<int> que;

    RecentCounter() {}

    int ping(int t) {
        // que.push(t);
        // while(que.front() < t - 3000){
        //     que.pop();
        // }
        // return que.size();
        requests.push_back(t);
        int res = BinSerch(requests, t - 3000);
        return requests.size() - res;
    }

    int BinSerch(vector<int> &requests, int target){
        int L = 0;
        int R = requests.size();
        while(L < R){
            int mid = L + (R - L) / 2;
            if(requests[mid] >= target){
                R = mid;
            }else{
                L = mid + 1;
            }
        }
        return L;
    }

};
