# Week 12 - Graph traversal

In this week, you'll mainly focus on algorithms that operate on graphs.
In particular, you'll implement depth-first search, which is a fundamental algorithm when working with graphs.
You'll also implement a topological sort, which is a way to order the nodes in a graph.

The graph data structure is stored in `graph.h`.
The algorithms you'll work on are stored in `visitor.h` and `topological_sort.h`.
The tests for the various activities can be found in `traversal_tester.h`.

When working on graphs, visualization is often very helpful.
The class `dot_writer` can be used to generate a [DOT](https://en.wikipedia.org/wiki/DOT_(graph_description_language))
file that can be visualized online, [here](https://edotor.net/) or [here](https://dreampuf.github.io/GraphvizOnline/).
Note that when including images in your log book, you should also include the files when submitting your markdown file.
Make sure that you use relative path names when including images, otherwise someone else won't be able to locate them.

Several of the tests actually load graphs from a file.
These files are contained in the `graphs` directory.
Along with the graph, its `dot` file is also included.
