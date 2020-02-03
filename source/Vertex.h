#pragma once

#include <QObject>

class Vertex
{
public:
    Vertex(int id, int value);

    int value() const;
    int id() const;

    friend bool operator==(const Vertex&, const Vertex&);
    friend bool operator!=(const Vertex&, const Vertex&);

protected:
    int id_;
    int value_;
};

