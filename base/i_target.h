//
// Created by guoxi on 2019/8/6.
//

#include <type_traits>

#ifndef CPPDATAFOLOW_ITARGET_H
#define CPPDATAFOLOW_ITARGET_H

#include "i_source.h"

template<typename T>
class i_target {
    virtual bool link_to(i_source<T>* target) = 0;
};

#endif //CPPDATAFOLOW_ITARGET_H

