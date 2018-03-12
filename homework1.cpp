#include <vector>
#include <iostream>

namespace my_algorithms
{

template<typename ForwardIter>
void advance(ForwardIter& it, unsigned int steps)
{
    while(steps--)
        ++it;
}

template<typename InputIterator, typename OutputIterator>
void copy(InputIterator b, InputIterator e, OutputIterator o)
{
    while(b!=e)
    {
        *o=*b;
        ++b;
        ++o;
    }
}

template<typename Iter, typename T>
Iter find(Iter b, Iter e, const T& val)
{
    while(b!=e)
    {
        if(*b==val)return b;
        ++b;
    }
    return e;
}

template<typename Iter, typename T>
Iter remove(Iter b, Iter e, const T& val)
{
    Iter res=b;
    while(b!=e)
    {
        if(*b!=val)
        {
            *res=*b;
            ++res;
        }
        ++b;
    }
    return res;
}

template<typename Iter, typename T>
unsigned int count(Iter b, Iter e, const T& val)
{
    unsigned int res=0;
    while(b!=e)
    {
        if(*b==val)++res;
        ++b;
    }
    return res;
}

template<typename Iter>
bool equal_range(Iter b, Iter e, Iter s)
{
	while (b != e)
	{
		if (*b != *s)return false;
		++b;
		++s;
	}
	return true;
}

template<typename Iter>
void sort(Iter b, Iter e)
{
    Iter bb=b;
    while(bb!=e)
    {
        Iter s=b;
        while(s!=e)
        {
            if(*s>*(s+1))std::swap(*(s+1),*s);
            ++s;
        }
        ++bb;
    }
}

}

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);

    if (my_algorithms::count(v.begin(), v.end(), 1) != 3U)
    {
        std::cout << "count is not implemented correctly" << std::endl;
        return 1;
    }

    if (my_algorithms::count(v.begin(), v.end(), 5) != 0)
    {
        std::cout << "count is not implemented correctly" << std::endl;
        return 1;
    }

    std::vector<int>::iterator it = my_algorithms::find(v.begin(), v.end(), 3);
    if (it == v.end() || *it != 3)
    {
        std::cout << "find is not implemented correctly" << std::endl;
        return 1;
    }

    it = my_algorithms::find(v.begin(), v.end(), 20);
    if (it != v.end())
    {
        std::cout << "find is not implemented correctly" << std::endl;
        return 1;
    }

    it = v.begin();
    my_algorithms::advance(it, 4);
    if (*it != 3)
    {
        std::cout << "advance is not implemented correctly" << std::endl;
        return 1;
    }

    unsigned int originalSize = v.size();
    unsigned int countOfOnes = my_algorithms::count(v.begin(), v.end(), 1);

    it = my_algorithms::remove(v.begin(), v.end(), 1);
    if (my_algorithms::find(v.begin(), it, 1) != it)
    {
        std::cout << "remove is not implemented correctly" << std::endl;
        return 1;
    }

    v.erase(it, v.end());

    if (originalSize - countOfOnes != v.size())
    {
        std::cout << "remove is not implemented correctly" << std::endl;
        return 1;
    }

    v.push_back(5);
    v.push_back(1);

    my_algorithms::sort(v.begin(), v.end());
    // check range is correctly sorted
    bool sorted = true;
    for (unsigned int i = 1; i < v.size(); ++i)
    {
        if (v[i - 1] > v[i])
        {
            std::cout << "sort is not implemented correctly" << std::endl;
            return 1;
        }
    }

    std::vector<int> q(v.size());
    my_algorithms::copy(v.begin(), v.end(), q.begin());
    for (unsigned int i = 0; i < q.size(); ++i)
    {
        if (q[i] != v[i])
        {
            std::cout << "copy is not implemented correctly" << std::endl;
            return 1;
        }
    }

    if (!my_algorithms::equal_range(v.begin(), v.end(), q.begin()))
    {
        std::cout << "equal_range is not implemented correctly" << std::endl;
        return 1;
    }

    std::cout << "Seems everything is correct!!!" << std::endl;

    return 0;
}
