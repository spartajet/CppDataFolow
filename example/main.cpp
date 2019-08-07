#include <iostream>
//#include "../base/i_source.h"
//#include <boost/thread.hpp>
//#include <boost/bind.hpp>
#include <boost/asio/thread_pool.hpp>
using namespace std;
using namespace boost::asio;


//#include <iostream>
#include "../blocks/trans_form_block.h"
using namespace std;
int main(int argc, char* argv[]){
    int a=10;
    trans_form_block<int,double > blocks([](int a){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return sqrt(a);
    },block_option{10,200});
    for (int i = 0; i < 1000; ++i) {
        bool result=blocks.Post(i);
        std::cout<<"post result:"<<result<<" "<<i<<std::endl;
    }
    std::this_thread::sleep_for(std::chrono::minutes(1));
    return 0;
}