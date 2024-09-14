# Sorting

This project contains two targets: merge sort and selection sort.

### Selection sort

You'll start with implementing the selection sort algorithm, and use it sort an array of `int`s.
All the functions you need are given in the `array.h` header file.
Make sure to use the `test_` functions to test your code.

### Merge sort

Merge sort is a _recursive_ sorting algorithm, and is applied to *singly linked lists*.
All the code necessary to work with linked lists is given in `list.h`.
You'll need to implement functions to (1) _split_ a linked list, (2) _merge_ two linked lists, and (3) recursively sorts linked lists by splitting and merging them.
Again, make sure to use the `test_` functions to test your code.

### WSL & Address sanitizer

In order to detect memory-related problems, you should run the code on WSL (or on Linux directly).
Make sure to activate the address sanitizer, as this will help you catch array out-of-bounds errors.
To do this, add the argument `-DUSE_ASAN=True` to the CMake options in your CMake profile.