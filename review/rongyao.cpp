//
// Created by 53110 on 2022/9/1.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
//    string line;
//    string tmp_str;
//    vector<string> v_str;
//    map<string, int> temp;
//    int res = 0;
//    while (getline(cin, line))
//    {
//        stringstream sstream(line);
//
//        while (getline(sstream, tmp_str, ','))
//        {
//            v_str.push_back(tmp_str);
//        }
//        char num = v_str[1][0];
//        temp[v_str[0]] = num - '0';
//        v_str.clear();
//    }
//
//
//    for(auto t:temp){
//        if (t.second > 10){
//            res ++;
//        }
//    }
//    cout<<res<<endl;

//    string a;
//    int b;
//    map<string, int> temp;
//    int res = 0;
//    while(cin>>a>>b){
//        a.erase(-1);
//
//        temp[a] += 1;
//    }
//    for(auto t:temp){
//        if (t.second > 10){
//            res ++;
//        }
//    }
//
//    return 0;
//    string line;
//    int res = 0;
//    map<string, int> temp;
//    while(cin>>line){
//        int pos = line.find(',');
//        if(pos == -1) break;
//        string key = line.substr(0, pos);
//        string value = line.substr(pos + 1);
////        cout<<"key:"<<key;
//        int num = stoi(value);
//        temp[key] += num;
//    }
//    for(auto t:temp){
//        if (t.second >= 10){
//            res ++;
//        }
//    }
////    string a = "b,\""
//    cout<<res<<endl;
//    const char *str1 = "hello";
//    cout<< sizeof(str1);
//    return 0;
//
//    vector<int> arr;
//    int a;
//    while(cin>>a){
//        arr.push_back(a);
//        if(cin.get() == '\n') break;
//    }
//    int k = arr.back();
//    arr.pop_back();
//    int temp = 0;
//    int res = 0;
//    int i = 0;
//    int j = 1;
//    cout<< k << endl;
//    while(i != arr.size()){
//        if(arr[i] > arr[j % arr.size()]){
//            // swap(arr[i], arr[j % arr.size()]);
//            temp ++;
//            j++;
//            if(temp == k){
//                res = arr[i];
//                break;
//            }
//        }else{
//            i ++;
//            j = i + 1;
//            temp = 1;
//        }
//    }

    unsigned char *p1;
    unsigned long *p2;
    p1 = (unsigned char *) 0x801000;
    p2 = (unsigned long *) 0x810000;
    p1 = p1 + 5;
    p2 = p2 + 5;
//    cout<< p1 << endl;
//    cout<< p2 + 5 << endl;
    return 0;
//    cout<<res<<endl;
}