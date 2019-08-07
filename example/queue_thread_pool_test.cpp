//
// Created by guoxi on 2019/8/7.
//
//#include <iostream>
//#include "../blocks/trans_form_block.h"
//using namespace std;
//int main(int argc, char* argv[]){
//    int a=10;
//    trans_form_block<int,double > blocks([](int a){
//        std::this_thread::sleep_for(std::chrono::seconds(20));
//        return sqrt(a);
//    },block_option{10});
//    for (int i = 0; i < 1000; ++i) {
//        blocks.Post(i);
//    }
//    std::this_thread::sleep_for(std::chrono::minutes(3));
//    return 0;
//}