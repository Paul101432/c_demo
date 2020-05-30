cmake_minimum_required(VERSION 3.16)
project(c_demo)

set(SOURCE_FILES src/main.cpp src/base64.h src/base64.cpp)
set(CMAKE_CXX_STANDARD 11)

set(INC_DIR ./include/)
set(LINK_DIR ./libs/window/x64/openssl/)




include_directories(${INC_DIR}) #引入头文件环境变量目录，cpp或者h文件中#include会自动去搜索这些头文件
link_directories(${LINK_DIR})   #获取该目录下的相对于的dylib  so  dll文件


# 生成的可执行文件
add_executable(c_demo  ${SOURCE_FILES})
## openssl libcrypto
target_link_libraries(${PROJECT_NAME} libcrypto)# ${LINK_DIR} TODO 第三方包加入失败 xmake可以

