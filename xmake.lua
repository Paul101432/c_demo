add_rules("mode.debug", "mode.release")
set_languages("cxx11") -- 设置c代码标准：c99， c++代码标准：c++11
add_includedirs("include") -- 添加头文件搜索目录



-- 链接库相对目录
if is_plat("windows") then
    if is_arch("x64") then
        add_linkdirs("libs/windows/x64/openssl")
        add_linkdirs("libs/windows/x64/ft")
    end
end


-- 控制台程序
target("console")
    set_kind("binary")
    add_links("libcrypto")
    add_links("ShuttleCsp11_3000GM")
    add_files("src/main.cpp")

