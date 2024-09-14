# Weeks 11 and 12 - Binary search trees

In these two weeks, you'll work on another way to store data: binary search trees.
These are hierarchical data structures that keep data sorted, just like sorted arrays do, but the hierarchical structure offers a few advantages.
In week 11, you'll implement functions to insert, remove, and search for data in a binary search tree.
You'll also use recursion to traverse the tree.

In week 12, you'll extend the binary search tree to one that self-balances itself as values are inserted and removed.
You will again use recursion for this, but this time you'll use it in a way that's a bit more complex.

When working with complex data structures like these, it's important to use pen and paper to draw out the structure of the data, especially when looking for bugs in your code.
Use the `bintree_writer` class to write out the tree to a so-called "dot" file, and then use a tool like [Graphviz](https://dreampuf.github.io/GraphvizOnline/) to visualize the tree.

Also, visualization tools like [this one](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html) can be very helpful to understand how the different operations performed on a (balanced) binary search tree work.

As always, make sure to use the provided `test_....` functions to test your code, and use an address sanitizer to verify that your code is accessing memory correctly.

