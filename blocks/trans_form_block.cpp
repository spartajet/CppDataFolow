//
// Created by guoxi on 2019/8/7.
////
//
//#include "trans_form_block.h"
//
//template<typename T, typename V>
//void trans_form_block<T, V>::manage() {
//    vector<future<V>> futures;
//    while (_run) {
////            int queue_size = this->source_queue.
//        if (this->source_queue.empty()) {
//            continue;
//        }
//        futures.clear();
//        for (int i = 0; i < this->option.thread_size; ++i) {
//            T t;
//            bool pop_result = this->source_queue.pop(t);
//            if (!pop_result) {
//                break;
//            }
//            futures.emplace_back(_pool->commit(f, t));
//        }
//        for (auto &&future : futures) {
//            V v = future.get();
//            std::cout << "计算结果" << v << std::endl;
////                if (this->target) {
////                    target.Post(v);
////                }
//        }
//    }
//}