if(CMAKE_COMPILER_IS_GNUCXX)
    execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion
                    OUTPUT_VARIABLE GCC_VERSION)
    if(GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8)
        set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
    else(GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8)
        set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
    endif(GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8)
endif(CMAKE_COMPILER_IS_GNUCXX)
if(CMAKE_CXX_COMPILER MATCHES "clang")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
endif(CMAKE_CXX_COMPILER MATCHES "clang")
# TODO: handle msvc compilers warnings?