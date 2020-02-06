#pragma once

#include <QPair>

#include "Vertex.h"

namespace graph {
namespace models {

class Edge
{
public:
    enum class Orientation {
        None = 0,
        LeftToRight,
        RightToLeft
    };

    Edge() noexcept;
    Edge(const Vertex&, const Vertex&, int, Orientation = Orientation::None);
    Edge(const Edge& ob);

    Edge& operator=(const Edge& ob);

    const Vertex& left() const;
    const Vertex& right() const;

    int value() const;
    bool isOriented() const;
    Orientation orientation() const;

    void setValue(int);

    friend bool operator==(const Edge&, const Edge&);
    friend bool operator!=(const Edge&, const Edge&);

private:
    Vertex left_;
    Vertex right_;
    int value_;
    Orientation orientation_;
};

} //models
} //graph



