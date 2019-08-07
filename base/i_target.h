//
// Created by guoxi on 2019/8/6.
//

#include <type_traits>

#ifndef CPPDATAFOLOW_ITARGET_H
#define CPPDATAFOLOW_ITARGET_H

#include "i_source.h"

template<typename V>
class i_target {
//    template <typename V>
    using target_function=function<bool(V)>;

    virtual bool set_target_function(function<bool(V)> function) = 0;
//    bool link_to(typename i_source<V> *target) {
//        return true;
//    }
};

#endif //CPPDATAFOLOW_ITARGET_H

