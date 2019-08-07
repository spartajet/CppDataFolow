//
// Created by guoxi on 2019/8/7.
//

#ifndef CPPDATAFOLOW_QUEUE_THREAD_H
#define CPPDATAFOLOW_QUEUE_THREAD_H

#include <boost/thread.hpp>
using namespace boost;
//#include <thread>

using namespace boost;
namespace cdf{
class queue_thread: public boost::thread {
    private:
        int order;
    public:

//    template<class _Fn,
//            class... _Args,
//            class = enable_if_t<!is_same_v<remove_cv_t<remove_reference_t<_Fn>>, thread>>>
//    explicit queue_thread(_Fn&& _Fx, _Args&&... _Ax)
//    {	// construct with _Fx(_Ax...)
//        _Launch(&_Thr,
//                _STD make_unique<tuple<decay_t<_Fn>, decay_t<_Args>...> >(
//                        _STD forward<_Fn>(_Fx), _STD forward<_Args>(_Ax)...));
//    }
    [[nodiscard]] int getOrder() const;

        void setOrder(const int order);

    };
}

#endif //CPPDATAFOLOW_QUEUE_THREAD_H
