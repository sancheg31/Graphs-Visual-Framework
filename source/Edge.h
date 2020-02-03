#pragma once

#include <QPair>

#include "Vertex.h"

class Edge
{
public:
    enum class Orientation {
        None = 0,
        LeftToRight,
        RightToLeft
    };

    Edge(const Vertex&, const Vertex&, int, Orientation = Orientation::None);
    Edge(const Edge&);
    Edge& operator=(const Edge&);

    QPair<Vertex, Vertex> adjacentVertices() const;
    int value() const;
    bool isOriented() const;
    Orientation orientation() const;

    friend bool operator==(const Edge&, const Edge&);
    friend bool operator!=(const Edge&, const Edge&);

protected:
    Vertex left_;
    Vertex right_;
    int value_;
    Orientation orientation_;
};

