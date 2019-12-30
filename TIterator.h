#ifndef TITERATOR_H
#define TITERATOR_H

#include <memory>
#include <iostream>

template <class N, class T>
class TIterator
{
public:
	using value_type = T;
	using reference = T & ;
	using pointer = T * ;
	using difference_type = ptrdiff_t;
	using iterator_category = std::forward_iterator_tag;

    TIterator(std::shared_ptr<N> n) {
        cur = n;
    }

    std::shared_ptr<N> operator* () {
        return cur;
    }

    std::shared_ptr<T> operator-> () {
        return cur->GetFigure();
    }

    void operator++() {
        cur = cur->GetNext();
    }

    TIterator operator++ (int) {
        TIterator cur(*this);
        ++(*this);
        return cur;
    }

    bool operator== (const TIterator &i) {
        return (cur == i.cur);
    }

    bool operator!= (const TIterator &i) {
        return (cur != i.cur);
    }

private:
    std::shared_ptr<N> cur;
};

#endif