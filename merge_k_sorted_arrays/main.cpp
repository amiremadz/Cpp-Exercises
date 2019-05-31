#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

struct Node{
    std::vector<int>::const_iterator current;
    std::vector<int>::const_iterator end;
};

struct Compare{
    bool operator()(const Node &a, const Node &b) const
    {
        return (*a.current > *b.current);
    }
};

std::vector<int> mergeSortedLists(std::vector<std::vector<int>> &mylist)
{
    std::priority_queue<Node, std::vector<Node>, Compare> pq;
    std::vector<int> result;
    
    for (const auto &vec : mylist)
    {
        pq.emplace(Node{vec.cbegin(), vec.cend()});
    }
    
    while (!pq.empty())
    {
        Node top = pq.top();
        pq.pop();
        if (top.current != top.end)
        {
            result.push_back(*top.current);
            pq.emplace(Node{std::next(top.current), top.end});
        }
    }

    return result;    
} 

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec)
{
    for (int num : vec)
        os << num << " ";
    os << std::endl;
    return os;
}

int main()
{
	std::vector<std::vector<int>> mylist{{1, 21, 30}, {2, 24, 44}, {12, 21, 23, 37, 88}};
    std::vector<int> mergedList = mergeSortedLists(mylist);
    std::cout << mergedList << std::endl;
    
    std::getchar();
    return 0;
}
