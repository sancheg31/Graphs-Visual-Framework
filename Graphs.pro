
include(qmake-target-platform.pri)
include(qmake-destination-path.pri)

DESTDIR = $${PWD}/binaries/$${DESTINATION_PATH}
OBJECTS_DIR = $${PWD}/build/$${DESTINATION_PATH}/.obj
MOC_DIR = $${PWD}/build/$${DESTINATION_PATH}/.moc
UI_DIR = $${PWD}/build/$${DESTINATION_PATH}/.ui
RCC_DIR = $${PWD}/build/$${DESTINATION_PATH}/.rcc

message(project dir: $${PWD})
message(dest dir: $${DESTINATION_PATH})

QT += core

CONFIG += c++17 console
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    source/algorithms/MaximalFlow.cpp \
    source/containers/EdgeContainer.cpp \
    source/containers/VertexContainer.cpp \
    source/iterators/ConstEdgeIterator.cpp \
    source/iterators/ConstVertexIterator.cpp \
    source/iterators/EdgeIterator.cpp \
    source/iterators/VertexIterator.cpp \
    source/main.cpp \
    source/models/Edge.cpp \
    source/models/Graph.cpp \
    source/models/GraphFactory.cpp \
    source/models/GraphImplementation.cpp \
    source/models/Vertex.cpp

HEADERS += \
    source/algorithms/MaximalFlow.h \
    source/containers/EdgeContainer.h \
    source/containers/VertexContainer.h \
    source/iterators/ConstEdgeIterator.h \
    source/iterators/ConstVertexIterator.h \
    source/iterators/EdgeIterator.h \
    source/iterators/VertexIterator.h \
    source/models/Edge.h \
    source/models/Graph.h \
    source/models/GraphFactory.h \
    source/models/GraphImplementation.h \
    source/models/Vertex.h

INCLUDEPATH += source

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
