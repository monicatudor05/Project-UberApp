cmake_minimum_required(VERSION 3.26)

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing executable name in this file
set(MAIN_PROJECT_NAME "oop")
set(MAIN_EXECUTABLE_NAME "${MAIN_PROJECT_NAME}")

project(${MAIN_PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "include/*")
file(GLOB_RECURSE TESTS  RELATIVE ${CMAKE_SOURCE_DIR} "test/*.cpp")

include_directories(include)
include_directories(src)

option(WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
option(USE_ASAN "Use Address Sanitizer" OFF)
option(USE_MSAN "Use Memory Sanitizer" OFF)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "install_dir" CACHE PATH "..." FORCE)
endif()

set(is_debug "$<CONFIG:Debug>")
set(is_rel_with_deb "$<CONFIG:RelWithDebInfo>")
set(debug_mode "$<OR:${is_debug},${is_rel_with_deb}>")



function(detect_libcpp)
    set(OLD_CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(TEST_STDLIB_SRC [=[
    #include <iostream>
    int main() {}
    ]=])
    try_compile(HAS_LIBCPP SOURCE_FROM_CONTENT test_stdlib.cpp ${TEST_STDLIB_SRC})
    set(CMAKE_CXX_FLAGS ${OLD_CMAKE_CXX_FLAGS})
    unset(OLD_CMAKE_CXX_FLAGS)


    set(HAS_LIBCPP ${HAS_LIBCPP} PARENT_SCOPE)
endfunction()

function(set_custom_stdlib_and_sanitizers target add_apple_asan)
    if(MSVC)
        # see https://gitlab.kitware.com/cmake/cmake/-/issues/24922
        set_target_properties(${target} PROPERTIES VS_USER_PROPS "${CMAKE_SOURCE_DIR}/disable_modules.props")
        target_compile_options(${target} PRIVATE /experimental:module-)
        if(USE_ASAN)
            target_compile_options(${target} PRIVATE "$<${debug_mode}:/fsanitize=address>")
        endif()
        return()
    endif()

    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" AND NOT WIN32)
        detect_libcpp()
        if(HAS_LIBCPP)
            target_compile_options(${target} PRIVATE -stdlib=libc++)
            target_link_options(${target} PRIVATE -stdlib=libc++)
        else()
            target_compile_options(${target} PRIVATE -stdlib=libstdc++)
            target_link_options(${target} PRIVATE -stdlib=libstdc++)
        endif()
    endif()

    if(APPLE)
        if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" AND add_apple_asan MATCHES true)
            if(USE_ASAN)
                target_compile_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
                target_link_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
            endif()
        endif()
    elseif(UNIX)
        if(USE_ASAN)
            target_compile_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
            target_link_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
        elseif(USE_MSAN)
            target_compile_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=memory,undefined;-fsanitize-recover=memory,undefined;-fsanitize-memory-track-origins>")
            target_link_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=memory,undefined;-fsanitize-recover=memory,undefined;-fsanitize-memory-track-origins;-Wl,-rpath,tools/llvm-project/build/lib>")
        endif()
    endif()
endfunction()

include(cmake/Options.cmake)
include(cmake/CompilerFlags.cmake)
include(cmake/CopyHelper.cmake)

###############################################################################
# MAIN target

add_executable(${MAIN_EXECUTABLE_NAME} main.cpp ${SOURCES} ${HEADERS})
set_compiler_flags(RUN_SANITIZERS TRUE TARGET_NAMES ${MAIN_EXECUTABLE_NAME})
target_include_directories(${MAIN_EXECUTABLE_NAME} SYSTEM PRIVATE generated/include)

###############################################################################
# TESTS



option(ENABLE_TESTS "Build tests" ON)

if (ENABLE_TESTS)
    include(CTest)
    enable_testing()


    set(LIB_SOURCES ${SOURCES})
    list(FILTER LIB_SOURCES EXCLUDE REGEX "^main\\.cpp$")
    list(FILTER LIB_SOURCES EXCLUDE REGEX ".*/main\\.cpp$")

    add_library(oop_lib STATIC ${LIB_SOURCES} ${HEADERS})
    target_include_directories(oop_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
    target_compile_features(oop_lib PUBLIC cxx_std_23)
    set_compiler_flags(RUN_SANITIZERS TRUE TARGET_NAMES oop_lib)

    include(FetchContent)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    FetchContent_MakeAvailable(googletest)


    if (TARGET gtest)
        set_custom_stdlib_and_sanitizers(gtest TRUE)
        endif()
    if (TARGET gtest_main)
        set_custom_stdlib_and_sanitizers(gtest_main TRUE)
        endif()
    if (TARGET gmock)
        set_custom_stdlib_and_sanitizers(gmock TRUE)
        endif()
    if (TARGET gmock_main)
        set_custom_stdlib_and_sanitizers(gmock_main TRUE)
        endif()


    if (MSVC AND USE_ASAN)
        if (TARGET gtest)
            set_compiler_flags(RUN_SANITIZERS TRUE TARGET_NAMES gtest)
            endif()
        if (TARGET gtest_main)
            set_compiler_flags(RUN_SANITIZERS TRUE TARGET_NAMES gtest_main)
            endif()
        if (TARGET gmock)
            set_compiler_flags(RUN_SANITIZERS TRUE TARGET_NAMES gmock)
        endif()
        if (TARGET gmock_main)
            set_compiler_flags(RUN_SANITIZERS TRUE TARGET_NAMES gmock_main)
        endif()
    endif()

    if (TESTS)
        add_executable(test_oop ${TESTS})
        if (MSVC AND USE_ASAN)
            set(_asan_paths
                    "$ENV{VCINSTALLDIR}/Tools/Llvm/x64/bin"
                    "$ENV{VCINSTALLDIR}/Tools/Llvm/bin"
                    "$ENV{VSINSTALLDIR}/VC/Tools/Llvm/x64/bin"
                    "$ENV{VSINSTALLDIR}/VC/Tools/Llvm/bin"
            )

            find_file(ASAN_DLL
                    NAMES clang_rt.asan_dynamic-x86_64.dll
                    PATHS ${_asan_paths}
                    NO_DEFAULT_PATH
            )
            find_file(ASAN_THUNK_DLL
                    NAMES clang_rt.asan_dynamic_runtime_thunk-x86_64.dll
                    PATHS ${_asan_paths}
                    NO_DEFAULT_PATH
            )

            if (ASAN_DLL AND ASAN_THUNK_DLL)
                foreach(_tgt ${MAIN_EXECUTABLE_NAME} test_oop)
                    if (TARGET ${_tgt})
                        add_custom_command(TARGET ${_tgt} POST_BUILD
                                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                                "${ASAN_DLL}" "$<TARGET_FILE_DIR:${_tgt}>"
                                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                                "${ASAN_THUNK_DLL}" "$<TARGET_FILE_DIR:${_tgt}>"
                                VERBATIM
                        )
                    endif()
                endforeach()
            else()
                message(WARNING "MSVC ASAN runtime DLLs not found. Tests may fail with 0xC0000135.")
            endif()
        endif()

        target_link_libraries(test_oop PRIVATE oop_lib GTest::gtest_main)
        target_include_directories(test_oop PRIVATE ${CMAKE_SOURCE_DIR}/include)
        set_compiler_flags(RUN_SANITIZERS TRUE TARGET_NAMES test_oop)

        if (NOT ((WIN32 AND MSVC AND USE_ASAN) OR (UNIX AND USE_MSAN)))
            include(GoogleTest)
            gtest_discover_tests(test_oop)
        else()
            message(STATUS "CTest registration disabled for test_oop on Windows MSVC ASAN (build-only).")
        endif()

    endif()
endif()


install(TARGETS ${MAIN_EXECUTABLE_NAME} DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()

copy_files(FILES tastatura.txt COPY_TO_DESTINATION TARGET_NAME ${MAIN_EXECUTABLE_NAME})
