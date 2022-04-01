//
// Created by 53110 on 2022/4/1.
//
#include <iostream>
using namespace std;
/*
 请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折一次，压出折痕后展开。
 此条折痕是凹下去的，即折痕突起的方向指向纸条的背面。
 如果从纸条的下边向上方连续对着2次，压出折痕后展开，此时有三条折痕，从上倒下依次是
 下折痕，下折痕和上折痕。
 给定一个输入参数N，代表纸条都从下边向上方连续对折N次。
 请从上到下打印所有折痕的方向。
 例如：N=1时，打印down， N=2时，打印：down down up
 */

class PaperFolding{
public:
    void printProcess(int i, int N, bool down){
        if(i > N){
            return;
        }
        printProcess(i + 1, N, true);
        cout<< (down ? "down" : "up") <<" ";
        printProcess(i + 1, N, false);
    }
    void PrintAllFolds(int N){
        printProcess(1, N, true);
    }
};

int main(){
    PaperFolding().PrintAllFolds(3);
    return 0;
}