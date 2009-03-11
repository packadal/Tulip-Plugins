#ifndef TEMPLATE_PROPERTIES
#define TEMPLATE_PROPERTIES


#include "QGraph.h"
#include "QNode.h"
#include "QEdge.h"
#include "QSize3D.h"
#include "QStdSet.h"

#include <tulip/IntegerProperty.h>
#include <tulip/DoubleProperty.h>
#include <tulip/BooleanProperty.h>
#include <tulip/SizeProperty.h>

#include <QtGui/QColor>
#include <QtCore/QSet>

#define AS_ARG(ARG) ARG
#define AS_ARG_EDGE(ARG) AS_ARG(ARG)
#define AS_ARG_NODE(ARG) AS_ARG(ARG)

#define AS_RETURN(RET) RET
#define AS_RETURN_EDGE(RET) RET
#define AS_RETURN_NODE(RET) RET



#define CLASS_NAME Integer
#define PROPERTY_NAME IntegerProperty
#define QPROPERTY_NAME QIntegerProperty
#define EDGE_TYPE int
#define NODE_TYPE int
#include "QTemplateProperties.def"
#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

#define CLASS_NAME Double
#define PROPERTY_NAME DoubleProperty
#define QPROPERTY_NAME QDoubleProperty
#define EDGE_TYPE double
#define NODE_TYPE double
#include "QTemplateProperties.def"
#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

//do not generate get{Node/Edge}{Min/Max} from now on
#define SIMPLE

#define CLASS_NAME Boolean
#define PROPERTY_NAME BooleanProperty
#define QPROPERTY_NAME QBooleanProperty
#define EDGE_TYPE bool
#define NODE_TYPE bool
#include "QTemplateProperties.def"
#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

#undef AS_ARG
#define AS_ARG(ARG) ARG->asSize3D()
#undef AS_RETURN_NODE
#define AS_RETURN_NODE(RET) new QSize3D(RET)
#undef AS_RETURN_EDGE
#define AS_RETURN_EDGE(RET) new QSize3DVector(RET)
QSTDVECTOR(Size3D, tlp::Coord);

#define CLASS_NAME Layout
#define PROPERTY_NAME LayoutProperty
#define QPROPERTY_NAME QLayoutProperty
#define EDGE_TYPE QSize3DVector*
#define NODE_TYPE QSize3D*
#include "QTemplateProperties.def"
#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef AS_RETURN_EDGE
#undef AS_RETURN_NODE
#undef AS_ARG
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

QSTDSET(Edge, tlp::edge);
#define AS_ARG(ARG) ARG->asGraph()
#define AS_RETURN_NODE(RET) new QGraph(RET)
#define AS_RETURN_EDGE(RET) new QEdgeSet(RET)
#define CLASS_NAME Graph
#define PROPERTY_NAME GraphProperty
#define QPROPERTY_NAME QGraphProperty
#define EDGE_TYPE QEdgeSet*
#define NODE_TYPE QGraph*
#include "QTemplateProperties.def"
#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef AS_RETURN_EDGE
#undef AS_RETURN_NODE
#undef AS_ARG
#undef AS_RETURN
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

#define AS_RETURN(RET) QString::fromStdString(RET)
#define AS_RETURN_NODE(RET) QString::fromStdString(RET)
#define AS_RETURN_EDGE(RET) QString::fromStdString(RET)
#define AS_ARG(ARG) ARG.toStdString()
#define CLASS_NAME String
#define PROPERTY_NAME StringProperty
#define QPROPERTY_NAME QStringProperty
#define EDGE_TYPE QString
#define NODE_TYPE QString
#include "QTemplateProperties.def"
#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef AS_RETURN_EDGE
#undef AS_RETURN_NODE
#undef AS_RETURN
#undef AS_ARG
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

#define AS_ARG(ARG) tlp::Color(ARG.red(), ARG.green(), ARG.blue(), ARG.alpha())
#define AS_RETURN(RET) QColor(RET.getR(), RET.getG(), RET.getB(), RET.getA())
#define AS_RETURN_NODE(RET) QColor(RET.getR(), RET.getG(), RET.getB(), RET.getA())
#define AS_RETURN_EDGE(RET) QColor(RET.getR(), RET.getG(), RET.getB(), RET.getA())
#define CLASS_NAME Color
#define PROPERTY_NAME ColorProperty
#define QPROPERTY_NAME QColorProperty
#define EDGE_TYPE QColor
#define NODE_TYPE QColor
#include "QTemplateProperties.def"
#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef AS_ARG
#undef AS_RETURN
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME
#undef AS_RETURN_NODE
#undef AS_RETURN_EDGE

#define AS_ARG(ARG) tlp::Size(ARG.getW(), ARG.getH(), ARG.getD())
#define AS_RETURN(RET) QSize3D(RET)
#define AS_RETURN_NODE(RET) QSize3D(RET)
#define AS_RETURN_EDGE(RET) QSize3D(RET)
#define CLASS_NAME Size
#define PROPERTY_NAME SizeProperty
#define QPROPERTY_NAME QSizeProperty
#define EDGE_TYPE QSize3D
#define NODE_TYPE QSize3D
#include "QTemplateProperties.def"
#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef AS_ARG
#undef AS_RETURN
#undef AS_ARG_EDGE
#undef AS_ARG_NODE
#undef AS_RETURN_EDGE
#undef AS_RETURN_NODE
#undef PROPERTY_NAME
#undef QPROPERTY_NAME
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

#endif //TEMPLATE_PROPERTIES
