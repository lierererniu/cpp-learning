//
// Created by Seven on 2022/2/15.
//

#include "iostream"
#include "string"

using namespace std;


template<class T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void mySort(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        int max = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        if (max != i) {
            mySwap(arr[max], arr[i]);
        }
    }
}

template<class T>
void myPrint(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01() {
    char arr[] = "abdea";
    int num = sizeof(arr) / sizeof(char);
    mySort(arr, num);
    myPrint(arr, num);
}

void test02()
{
    int arr[] = {6,5,4,2,5,6,7,2,367,1};
    int num = sizeof(arr) / sizeof(int);
    mySort(arr, num);
    myPrint(arr, num);
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}