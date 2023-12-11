cmake_minimum_required(VERSION 2.8)		# cmake的最低版本要求，使用apt安装的cmake版本一般是没什么问题的

project(myprocess)		# 工程名字，随意写就行

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

link_directories()  #需要的链接库搜索路径

file(GLOB SRC_FILE ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

add_executable(myprocess ${SRC_FILE})

target_link_libraries(myprocess)    #可以在后面添加需要链接的库名

