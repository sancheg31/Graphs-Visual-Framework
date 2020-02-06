#pragma once

#include <QVector>
#include <utility>
#include <functional>

#include "Edge.h"

namespace graph {
namespace containers {

class EdgeContainer
{
public:
    using value_type = models::Edge;
protected:
    using container_type = QVector<value_type>;
public:

    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;

    EdgeContainer(int size = 0);
    EdgeContainer(const EdgeContainer&);
    EdgeContainer& operator=(const EdgeContainer&);

    void push_back(const value_type&);
    void insert(int i, const value_type&);
    void remove(int i);
    void remove(iterator);

    void remove_if(std::function<bool(const value_type&)>);

    int size() const;
    bool isEmpty() const;

    value_type& operator[](int i);
    const value_type& operator[](int i) const;

    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const;

    iterator end();
    const_iterator end() const;
    const_iterator cend() const;

private:
    container_type cont;
};

} // containers
} //graph



