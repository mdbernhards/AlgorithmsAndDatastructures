#include "maxheap.h"

maxheap::maxheap(const std::vector<task> &values)
    : m_values{values} {
    heapify();
}

maxheap::operator bool() const {
    return !m_values.empty();
}

maxheap &maxheap::operator<<(int priority) {
    return operator<<(task{.priority = priority, .description = "unspecified"});
}

maxheap &maxheap::operator<<(const task &task) {
    insert(task);
    return *this;
}

size_t maxheap::size() const {
    return m_values.size();
}

const task &maxheap::maximum() const 
{
    return m_values[0];
}

void maxheap::delete_max() {
    std::swap(m_values[0], m_values.back());
    m_values.pop_back();
    bubble_down(0);
}

void maxheap::insert(const task &value) {
    m_values.push_back(value);
    bubble_up(m_values.size() - 1);
}

void maxheap::swap_at_index(size_t first_index, size_t second_index) {
    std::swap(m_values[first_index], m_values[second_index]);
}

size_t maxheap::parent_index(size_t index) 
{
    if (index == 0) 
    {
        return npos;
    }

    return (index - 1) / 2;
}

size_t maxheap::left_child_index(size_t index) 
{
    return child_index(index, false, m_values.size());
}

size_t maxheap::right_child_index(size_t index) 
{
    return child_index(index, true, m_values.size());
}

size_t maxheap::child_index(size_t index, bool rightChild, size_t heapSize)
{
    auto childIndex = index * 2 + 1 + rightChild;

    if (childIndex >= heapSize)
    {
        return npos;
    }

    return childIndex;
}

size_t maxheap::bubble_up(size_t index) 
{
    size_t swaps = 0;

    if (index == 0) 
    {
        return swaps;
    }

    auto parentIndex = parent_index(index);

    while (parentIndex != npos && m_values[index].priority > m_values[parentIndex].priority)
    {
        swap_at_index(index, parentIndex);
        index = parentIndex;
        parentIndex = parent_index(index);
        swaps++;
    }
    
    return swaps;
}

size_t maxheap::bubble_down(size_t index) 
{
    size_t swaps = 0;

    do
    {
        auto swapIndex = index;
        auto rightIndex = right_child_index(index);
        auto leftIndex = left_child_index(index);

        if (rightIndex != npos && m_values[index] < m_values[rightIndex])
        {
            swapIndex = rightIndex;
        }

        if (leftIndex != npos && m_values[swapIndex] < m_values[leftIndex])
        {
            swapIndex = leftIndex;
        }

        if (swapIndex == index)
        {
            return swaps;
        }
        
        swaps++;
        swap_at_index(index, swapIndex);
        index = swapIndex;
    } while (true);
}

size_t maxheap::heapify() 
{
    size_t swaps = 0;

    if (!m_values.size())
    {
        return swaps;
    }
    
    for (int i = (m_values.size() / 2) - 1; i >= 0; i--)
    {
        swaps += bubble_down(i);
    }
    
    return swaps;
}
