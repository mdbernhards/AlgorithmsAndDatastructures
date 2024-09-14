#include <iostream>
#include <cassert>
#include <string>
#include "maxheap.h"
#include "heap_tester.h"

template<typename T>
void bubble_down(std::vector<T> &values, size_t index, size_t count) 
{
    do
    {
        auto swapIndex = index;
        auto leftIndex = 2 * index + 1;
        auto rightIndex = leftIndex + 1;

        if (rightIndex < count && values[index] < values[rightIndex])
        {
            swapIndex = rightIndex;
        }

        if (leftIndex < count && values[swapIndex] < values[leftIndex])
        {
            swapIndex = leftIndex;
        }

        if (swapIndex == index)
        {
            return;
        }
        
        std::swap(values[index], values[swapIndex]);
        index = swapIndex;
    } while (true);
}

template<typename T>
void heapify(std::vector<T> &values) 
{
    auto size = values.size();

    if (!size)
    {
        return;
    }
    
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        bubble_down(values, i, size);
    }
}

template<typename T>
void heap_sort(std::vector<T> &values)
{
    heapify(values);
    for (int i = values.size() - 1; i > 0; i--) 
    {
        std::swap(values[i], values[0]);
        bubble_down(values, 0, i);
    }
}

int main() 
{
    std::vector<int> heap = {9, 7, 6, 3, 2, 5};
    std::swap(heap[5], heap[0]);
    bubble_down(heap, 0, 5);
    assert(heap == (std::vector<int>{7, 5, 6, 3, 2, 9}));
    std::swap(heap[4], heap[0]);
    bubble_down(heap, 0, 4);
    assert(heap == (std::vector<int>{6, 5, 2, 3, 7, 9}));
    std::swap(heap[3], heap[0]);
    bubble_down(heap, 0, 3);
    assert(heap == (std::vector<int>{5, 3, 2, 6, 7, 9}));
    std::swap(heap[2], heap[0]);
    bubble_down(heap, 0, 2);
    assert(heap == (std::vector<int>{3, 2, 5, 6, 7, 9}));
    std::swap(heap[1], heap[0]);
    assert(heap == (std::vector<int>{2, 3, 5, 6, 7, 9}));
    heap = {2, 9, 5, 3, 7, 6};
    heapify(heap);
    assert(heap == (std::vector<int>{9, 7, 6, 3, 2, 5}));

    std::vector<int> numbers{2, 9, 5, 3, 7, 6, 0, 4, 1};
    heap_sort(numbers);
    assert(numbers == (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 9}));

    std::vector<int> numbers2{2, 9, 5, 3, 7, 6, 0, 4, 1};
    heap_sort(numbers2);
    assert(heap_tester::is_sorted(numbers2));
    std::vector<char> letters{'z', 't', 'x', 'y', 'a', 'f', 'q', 'c', 's'};
    heap_sort(letters);
    assert(heap_tester::is_sorted(letters));
    std::vector<std::string> strings{"foo", "bar", "bob", "ham", "bacon"};
    heap_sort(strings);
    assert(heap_tester::is_sorted(strings));

    std::cout << "Done" << std::endl;

    /*

    // Activty 5
    heap_tester::test_left_child_index();
    heap_tester::test_right_child_index();
    heap_tester::test_parent_index();

    // Activty 6
    heap_tester::test_find_max();

    // Activty 7
    heap_tester::test_bubble_up();

    // Activity 8
    heap_tester::test_bubble_down();

    // Activity 9
    heap_tester::test_heapify();


    heap_tester::createAndHeapify(5);
    heap_tester::createAndHeapify(10);
    heap_tester::createAndHeapify(20);
    heap_tester::createAndHeapify(50);
    heap_tester::createAndHeapify(100);
    heap_tester::createAndHeapify(200);
    heap_tester::createAndHeapify(300);
    heap_tester::createAndHeapify(400);
    heap_tester::createAndHeapify(500);
    heap_tester::createAndHeapify(1000);

    
    // Activity 11, 12
    std::vector<int> numbers{2, 9, 5, 3, 7, 6, 0, 4, 1};
    heap_sort(numbers);
    assert(heap_tester::is_sorted(numbers));
    */
    return 0;
}
