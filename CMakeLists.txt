cmake_minimum_required(VERSION 3.14)
project(CppDataFolow)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000")
option(CMAKE_ENCODING_UTF8 "Use UTF-8 encoding internally." ON)

set(BOOST_DIR "C:/boost_1_70_0")
include_directories("C:\\boost_1_70_0")
link_directories("C:\\boost_1_70_0\\stage\\lib")

add_executable(CppDataFolow example/main.cpp base/i_source.h base/i_target.h example/queue_thread_pool_test.cpp blocks/trans_form_block.h base/i_block.cpp base/i_block.h base/thread/threadpool.h blocks/action_block.cpp blocks/action_block.h)
target_link_libraries(CppDataFolow libboost_thread-vc141-mt-x64-1_70 libboost_chrono-vc141-mt-x64-1_70)