# Week 6 - Sets

This project contains three targets: the first consists of just a single file, `intro.c`, and two consist of multiple files.
The latter two are stored in the directories `sets_sorted` and `sets_unsorted`.

You'll need to do the first two activities in the `intro.c` file.
Activity three (three function implementations) is done in the `sets_unsorted` target, and the remainder of the activities is done in the `sets_sorted` target.

Make sure to use the provided `test_....` functions to test your code.
Also, use an address sanitizer to verify that your code is accessing memory correctly.
For this, please verify that the `-DUSE_ASAN=True` option is included in the `CMake` options.