#pragma once


#include <QVector>

#include "Edge.h"

class VertexContainer
{
public:
    using value_type = Edge;
protected:
    using container_type = QVector<value_type>;
public:

    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;

    VertexContainer(int size = 0);
    VertexContainer(const VertexContainer&);
    VertexContainer& operator=(const VertexContainer&);

    void insert(int i, const value_type&);
    void remove(int i);

    int size() const;
    bool isEmpty() const;

    value_type& operator[](int i);
    const value_type& operator[](int i) const;

    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const;

    iterator end();
    const_iterator end() const;
    const_iterator cend() const;;

private:
    container_type cont;
};

