#pragma once

#include <QObject>

class Vertex
{
public:
    Vertex(int id = 0, int value = 0);
    Vertex(const Vertex&);
    Vertex& operator=(const Vertex&);

    int value() const;
    int id() const;

    friend bool operator==(const Vertex&, const Vertex&);
    friend bool operator!=(const Vertex&, const Vertex&);

protected:
    int id_;
    int value_;
};

