#pragma once


#include <QVector>
#include <QHash>

#include "models/Edge.h"

namespace graph {
namespace containers {

class VertexContainer
{
public:
    using value_type = models::Vertex;
protected:
    using container_type = QHash<QString, value_type>;
public:

    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;

    VertexContainer();
    VertexContainer(const VertexContainer& ob);
    VertexContainer(VertexContainer&& ob);
    VertexContainer& operator=(const VertexContainer& ob);
    VertexContainer& operator=(VertexContainer&& ob);

    void insert(const value_type&);
    void remove(const QString&);
    void clear();


    int size() const;
    bool contains(const QString&) const;
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

} //containers
} //graph



