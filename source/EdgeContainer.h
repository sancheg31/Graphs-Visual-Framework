#pragma once

#include <QVector>

#include "Edge.h"

class EdgeContainer
{
public:
    using value_type = Edge;
protected:
    using container_type = QVector<value_type>;
public:

    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;

    EdgeContainer(int size = 0);
    EdgeContainer(const EdgeContainer&);
    EdgeContainer& operator=(const EdgeContainer&);

    void insert(const value_type&, int i);
    void remove(int i);

    value_type& operator[](int i);
    const value_type& operator[](int i) const;

    iterator begin();
    iterator begin() const;
    const_iterator cbegin() const;

    iterator end();
    iterator end() const;
    const_iterator cend() const;

private:
    container_type cont;
};

