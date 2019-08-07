cmake_minimum_required(VERSION 3.14)
project(CppDataFolow)

set(CMAKE_CXX_STANDARD 17)
set(BOOST_DIR "C:/boost_1_70_0")
include_directories("C:\\boost_1_70_0")
link_directories("C:\\boost_1_70_0\\stage\\lib")

add_executable(CppDataFolow example/main.cpp base/i_source.h base/i_target.h base/thread/queue_thread_pool.cpp base/thread/queue_thread_pool.h base/thread/queue_thread.cpp base/thread/queue_thread.h example/queue_thread_pool_test.cpp blocks/trans_form_block.h base/i_block.cpp base/i_block.h base/thread/threadpool.h)
target_link_libraries(CppDataFolow libboost_thread-vc141-mt-x64-1_70 libboost_chrono-vc141-mt-x64-1_70)