#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "visitor.h"
#include "dot_writer.h"
#include "traversal_tester.h"
#include "topological_sort.h"

int main() 
{
    data::graph g{true}; // create an undirected graph
    g.add_edge("a", "b");
    g.add_edge("b", "d");
    g.add_edge("d", "c");
    g.add_edge("c", "a");
    g.add_edge("d", "e");
    g.add_edge("e", "f");
    g.add_edge("f", "g");
    g.add_edge("g", "e");
    g["a"].set_colour(data::colour::blue);
    g["b"].set_colour(data::colour::blue);
    g["c"].set_colour(data::colour::blue);
    g["d"].set_colour(data::colour::blue);
    g["e"].set_colour(data::colour::blue);
    g["f"].set_colour(data::colour::blue);
    g["g"].set_colour(data::colour::blue);
    dot_writer::write(g, "simple2.dot");


    auto gg = data::graph::load("large_acyclic.graph");
    auto visitors = new visitor(gg);
    auto answer = visitors->find_path("a", "u");

    if (answer)
    {
        std::cout << "path found!" << std::endl;
    }
    else
    {
        std::cout << "path not found!" << std::endl;
    }

    dot_writer::write(gg, "simple3.dot");


    auto ggg = data::graph::load("large_cyclic.graph");
    auto visitors2 = new visitor(ggg);
    auto answer2 = visitors2->find_path("a", "foo");

    if (answer2)
    {
        std::cout << "path found!" << std::endl;
    }
    else
    {
        std::cout << "path not found!" << std::endl;
    }

    dot_writer::write(ggg, "simple4.dot");


    // NOTE: some of the tests below may cause the program to crash.
    //  uncomment the tests one by one.
    algos::traversal_tester::test_find_path_result(); // Activity 3
    algos::traversal_tester::test_path_colouring();   // Activty 4
    algos::traversal_tester::test_avoid_cycle();    // Activity 5
    algos::traversal_tester::test_detect_cycle();   // Activity 6
    algos::traversal_tester::test_colour_cycle();   // Activity 7
    algos::traversal_tester::test_post_order();    // Activity 8
    algos::traversal_tester::test_topological_sort();   // Activity 9


    std::ifstream infile("tasks.txt");

    string line;
    string array[10];

    while(getline(infile, line)) 
    {
        if (line == "\r")
        {
            break;
        }
        
        std::istringstream iss(line);
        string a, b, temp;

        iss >> a >> b;

        while (iss >> temp)
        {
            b += " " + temp;
        }

        a.pop_back();
        array[std::stoi(a) - 1] = b;
    }

    std::ofstream myfile;
    myfile.open ("gameDev.graph");
    myfile << "directed\n";

    while(getline(infile, line)) 
    {
        std::istringstream iss(line);

        string a, b, c, d;
        iss >> a >> b >> c >> d;
        myfile << a << " " << d << std::endl;
    }

    myfile.close();

    auto graph = data::graph::load("gameDev.graph");
    algos::topological_sort sorter{graph};

    if (sorter.compute()) 
    {
        const auto& result = sorter.result();

        std::cout << "Order of tasks:" << std::endl;
        for (const auto& task : result) 
        {
            std::cout << array[std::stoi(task) - 1] << std::endl;
        }
    } 
    else 
    {
        std::cerr << "Cycle there, can't do it." << std::endl;
    }

    return 0;
}
