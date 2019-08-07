//
// Created by guoxi on 2019/8/7.
//

#include "queue_thread.h"
namespace cdf {
    int queue_thread::getOrder() const {
        return order;
    }

    void queue_thread::setOrder(int order) {
        queue_thread::order = order;
    }
}