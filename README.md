# simple-cpp-unit
A simple C++ unit testing framework, designed after other testing frameworks from C# and Java
## Building
1. Clone the repository and change directory into it:

    `git clone https://github.com/hahn-will/simple-cpp-unit.git && cd simple-cpp-unit`
2. Build source:
    ```
    mkdir build && cd build
    cmake ..
    make install
    ```
    
## Information
- This library relies heavily on macros to create the behavior desired for this to work as I intend it to, however, this means
there may be undefined behavior if these macros are not used as intended.
- To see how to use this library, view the wiki (not yet created).
- This library is created using a only a couple header files, which can all be found in the "api" folder
