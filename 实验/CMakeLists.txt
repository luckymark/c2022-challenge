cmake_minimum_required(VERSION 3.23)
project(NewWuZiQi)

set(CMAKE_CXX_STANDARD 14)

link_libraries(libeasyx.a)
link_libraries(Winmm.lib)

#pragma comment(lib,"Winmm.lib")
#target_link_libraries(Winmm.lib)

add_executable(NewWuZiQi WuZiQi.h main.cpp Game_Start.cpp GoPng.cpp min_max.cpp myscore.cpp)

