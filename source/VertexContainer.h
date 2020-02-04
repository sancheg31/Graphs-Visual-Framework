#pragma once


#include <QVector>
#include <QHash>

#include "Edge.h"

class VertexContainer
{
public:
    using value_type = Vertex;
protected:
    using container_type = QHash<QString, value_type>;
public:

    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;

    VertexContainer();
    VertexContainer(const VertexContainer&);
    VertexContainer& operator=(const VertexContainer&);

    void insert(const value_type&);
    void remove(const QString&);

    int size() const;
    bool isEmpty() const;

    value_type& operator[](const QString&);
    value_type operator[](const QString&) const;

    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const;

    iterator end();
    const_iterator end() const;
    const_iterator cend() const;

private:
    container_type cont;
};

