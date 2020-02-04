
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
    source/ConstEdgeIterator.cpp \
    source/ConstVertexIterator.cpp \
    source/Edge.cpp \
    source/EdgeContainer.cpp \
    source/EdgeIterator.cpp \
    source/Graph.cpp \
    source/GraphFactory.cpp \
    source/GraphImplementation.cpp \
    source/MaximalFlow.cpp \
    source/Vertex.cpp \
    source/VertexContainer.cpp \
    source/VertexIterator.cpp \
    source/main.cpp \

HEADERS += \
    source/ConstEdgeIterator.h \
    source/ConstVertexIterator.h \
    source/Edge.h \
    source/EdgeContainer.h \
    source/EdgeIterator.h \
    source/Graph.h \
    source/GraphFactory.h \
    source/GraphImplementation.h \
    source/MaximalFlow.h \
    source/Vertex.h \
    source/VertexContainer.h \
    source/VertexIterator.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
