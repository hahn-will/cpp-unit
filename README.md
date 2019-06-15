# simple-cpp-unit
A simple C++ unit testing framework, designed after other testing frameworks from C# and Java
## Building
1. Clone the repository and change directory into it:

    `git clone https://github.com/hahn-will/simple-cpp-unit.git && cd simple-cpp-unit`
2. Build source:
    ```
    mkdir build && cd build
    cmake ..
    make
    ```
    
## Information
- This program relies heavily on additional preprocessing accomplished on top of the already existing c++ preprocessing, so errors may come from innacurately used macros.
- If there are any issues, create an issue, otherwise try to fix it yourself

## Future Steps
- In the future this project may include integration with popular development environments
- Faster and more accurate preprocessing
