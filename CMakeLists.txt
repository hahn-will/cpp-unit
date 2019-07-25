cmake_minimum_required (VERSION 3.13)

project (simple-cpp-unit LANGUAGES CXX)

macro (add_sources)
    file (RELATIVE_PATH _relPath "${PROJECT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND SRCS "${_relPath}/${_src}")
        else()
            list (APPEND SRCS "${_src}")
        endif()
    endforeach()
    if (_relPath)
        set (SRCS ${SRCS} PARENT_SCOPE)
    endif()
endmacro()


add_subdirectory (src)
add_subdirectory (src/command_line)
add_subdirectory (src/macros)
add_subdirectory (src/test_method)
add_subdirectory (src/test_suite)
add_subdirectory (src/utils)

add_executable (simple-cpp-unit ${SRCS})
target_compile_options (simple-cpp-unit PRIVATE -Wall -Werror -rdynamic)
target_link_libraries (simple-cpp-unit ${CMAKE_DL_LIBS})
