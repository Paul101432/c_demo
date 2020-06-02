cmake_minimum_required(VERSION 3.16)
project(c_demo)
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_EXE_LINKER_FLAGS "/machine:x64")
#set(CMAKE_MODULE_LINKER_FLAGS "/machine:x64")


set(SOURCE_FILES src/main.cpp )


set(INC_DIR ./include/)


## ${CMAKE_SYSTEM} ${CMAKE_SYSTEM}
## ${CMAKE_HOST_SYSTEM_NAME} Windows
## ${CMAKE_CL_64} 0 就是x86 1 就是 x64



include_directories(${INC_DIR}) #引入头文件环境变量目录，cpp或者h文件中#include会自动去搜索这些头文件
link_libraries(
        "..\\libs\\windows\\x86\\ft\\ShuttleCsp11_3000GM.lib"
        "..\\libs\\windows\\x86\\openssl\\libcrypto.lib"
        "..\\libs\\windows\\x86\\openssl\\openssl.lib"
)
## E:\\code-c\\c_demo\\libs\\windows\\x64\\ft

# 生成的可执行文件
add_executable(c_demo  ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME})

