//
// Created by 15216 on 2022/10/18.
//
#include "local_algorithm.h"
#include<iostream>
#include<windows.h>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::iterator;

int binary_search(vector<int> v,int target){
    //默认元素是升序的
    auto begin = v.begin();
    auto end = v.end();
    auto middle = begin + v.size()/2;
    //只有当begin和end相等时才会有middle==end，所以，middle!=end也作为循环条件
    while(middle != end && *middle != target){
        if(target > *middle){
            begin = middle + 1;
        }
        else{
            end = middle;
        }
        middle = begin + (end - begin)/2;
    }
    if(*middle == target){
        return middle - v.begin();//返回index
    }
    else{
        return -1;//表示未找到
    }
}
//迭代法
size_t fibonacci_sequence(int n){
    if(n == 1 or n == 2){
        return 1;
    }
    else if(n > 2){
        int a = 1;
        int b = 1;
        int c = 1;
        for(int i = 3;i <= n;i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}