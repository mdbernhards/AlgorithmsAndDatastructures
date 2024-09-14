# Algorithms & Data Structures, week 3

This project contains two targets - they are configured in the `CMakeLists.txt` files in the directories `singly_linked` and `doubly_linked`.
The project's main `CMakeLists.txt` configures settings that apply to both settings.

## Selecting the target to build / run

You can select which target to build / run by selecting it from the drop-down menu next to the "Build" (hammer), and "Run" (play button).

## Using an address sanitizer

It is highly recommended to use an address sanitizer, in order to detect memory-related bugs in your program, such as memory leaks, out-of-bounds access, etc.
To do so, setup a CMake profile in CLion (through Settings > Build, Execution, Deployment > CMake) that:


1. uses the WSL toolchain
2. Adds the following option to CMake: `-DUSE_ASAN=True`

When debugging/running the program while the address sanitizer is active, you'll find a "Sanitizers" tab next to the "Console" tab.
In case your program has problems, it will finish with exit code 1, and the sanitizer tab will list problems.

These problems can for example be "Heap-buffer-overflow", or "Detected memory leak".
In the former case, you're accessing memory that was not allocated.
The latter warning means that you're not `free`-ing memory that you allocated earlier.
