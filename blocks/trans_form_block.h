//
// Created by guoxi on 2019/8/7.
//

#ifndef CPPDATAFOLOW_TRANS_FORM_BLOCK_H
#define CPPDATAFOLOW_TRANS_FORM_BLOCK_H


#include "../base/i_source.h"
#include "../base/i_target.h"
#include "functional"
#include <boost/lockfree/queue.hpp>
#include "../base/i_block.h"
#include <atomic>
#include <thread>
#include "../base/thread/threadpool.h"
#include <vector>

using namespace std;
using namespace boost;

template<typename T, typename V>
class trans_form_block : public i_source<T>, public i_target<V> {
    using operate_function=function<V(T)>;
private:
    operate_function f;
    boost::lockfree::queue<T> *source_queue;
//    boost::lockfree::queue<T> source_queue;

//    i_source<V> target = nullptr;
    block_option option;
    threadpool *_pool = nullptr;
    std::atomic_bool _run{true}; //是否运行
//    std::atomic_int _idl_number{0}; //当前空闲的线程数量
//    vector<std::thread> _threads; //线程池中的线程
    std::thread _manage_thread; //管理线程
public:
    /*
     * 管理线程的方法
     */
    void manage() {
        vector<future<V>> futures;
        while (_run) {
//            int queue_size = this->source_queue.
            if (this->source_queue->empty()) {
                continue;
            }
            futures.clear();
            for (int i = 0; i < this->option.thread_size; ++i) {
                T t;
                bool pop_result = this->source_queue->pop(t);
                if (!pop_result) {
                    break;
                }
                futures.emplace_back(_pool->commit(f, t));
            }
            for (auto &&future : futures) {
                V v = future.get();
                std::cout << "the result" << v << std::endl;
//                if (this->target) {
//                    target.Post(v);
//                }
            }
        }
    }

public:
    trans_form_block(const operate_function &f,
                     block_option option) : f(f), option(option) {
        if (option.thread_size < 1) {
            option.thread_size = 1;
        }
        this->source_queue = new boost::lockfree::queue<T>(option.source_queue_capacity);
        this->_pool = new threadpool(option.thread_size);
        this->_manage_thread = std::thread(&trans_form_block::manage, this);
        boost::lockfree::queue<T>::size_type queue_size(option.source_queue_capacity);
    }

    ~trans_form_block() {
        _run = false;
        delete this->_pool;
//        for (const auto &item : _threads) {
//            if (item.joinable()) {
//                item.join();
//            }
//        }
    }

    inline bool Post(T t) override {
        return this->source_queue->push(t);
    }

    bool link_to(i_source<V> *target) override {
//        if (target != nullptr) {
//            return false;
//        }
//        this->target = target;
        return true;
    };
};


#endif //CPPDATAFOLOW_TRANS_FORM_BLOCK_H
