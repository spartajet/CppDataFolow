//
// Created by guoxi on 2019/8/6.
//

#ifndef CPPDATAFOLOW_ISOURCE_H
#define CPPDATAFOLOW_ISOURCE_H

//#include "i_target.h"

template<typename T>
class i_source {
public:
    virtual bool Post(T t) = 0;
};


#endif //CPPDATAFOLOW_ISOURCE_H

