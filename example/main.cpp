#include <iostream>
//#include "../base/i_source.h"
//#include <boost/thread.hpp>
//#include <boost/bind.hpp>
#include <boost/asio/thread_pool.hpp>
using namespace std;
using namespace boost::asio;


//#include <iostream>
#include "../blocks/trans_form_block.h"
#include "../blocks/action_block.h"
using namespace std;
int main(int argc, char* argv[]){
    int a=10;
    trans_form_block<int, double> operate_block([](int a) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        double sqrt_reuslt = sqrt(a);
        std::cout << "operate action " << sqrt_reuslt << std::endl;
        return sqrt_reuslt;
    }, block_option{10, 200});
    action_block<double> display_block([](double d) {
        std::cout << "display action " << pow(d, 2) << std::endl;
    }, block_option{3, 200});
//    operate_block.link_to(display_block);
//    operate_block.set_target_function([&display_block](double d) {
//        return display_block.Post(d);
//    });
    for (int i = 0; i < 1000; ++i) {
        bool result = operate_block.Post(i);
        std::cout<<"post result:"<<result<<" "<<i<<std::endl;
    }
    std::this_thread::sleep_for(std::chrono::minutes(1));
    return 0;
}