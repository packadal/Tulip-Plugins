#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>

QScriptValue qtscript_create_QEdge_class(QScriptEngine *engine);
QScriptValue qtscript_create_QSize3D_class(QScriptEngine *engine);
QScriptValue qtscript_create_QIterator_class(QScriptEngine *engine);
QScriptValue qtscript_create_QGraph_class(QScriptEngine *engine);
QScriptValue qtscript_create_QProperty_class(QScriptEngine *engine);
QScriptValue qtscript_create_QNode_class(QScriptEngine *engine);
QScriptValue qtscript_create_QBooleanProperty_class(QScriptEngine *engine);
QScriptValue qtscript_create_QStringProperty_class(QScriptEngine *engine);
QScriptValue qtscript_create_QLayoutProperty_class(QScriptEngine *engine);
QScriptValue qtscript_create_QSizeProperty_class(QScriptEngine *engine);
QScriptValue qtscript_create_QDoubleProperty_class(QScriptEngine *engine);
QScriptValue qtscript_create_QIntegerProperty_class(QScriptEngine *engine);
QScriptValue qtscript_create_QColorProperty_class(QScriptEngine *engine);
QScriptValue qtscript_create_QGraphProperty_class(QScriptEngine *engine);

static const char * const qtscript_tulip_script_class_names[] = {
    "QEdge"
    , "QSize3D"
    , "QIterator"
    , "QGraph"
    , "QProperty"
    , "QNode"
    , "QBooleanProperty"
    , "QStringProperty"
    , "QLayoutProperty"
    , "QSizeProperty"
    , "QDoubleProperty"
    , "QIntegerProperty"
    , "QColorProperty"
    , "QGraphProperty"
};

typedef QScriptValue (*QtBindingCreator)(QScriptEngine *engine);
static const QtBindingCreator qtscript_tulip_script_class_functions[] = {
    qtscript_create_QEdge_class
    , qtscript_create_QSize3D_class
    , qtscript_create_QIterator_class
    , qtscript_create_QGraph_class
    , qtscript_create_QProperty_class
    , qtscript_create_QNode_class
    , qtscript_create_QBooleanProperty_class
    , qtscript_create_QStringProperty_class
    , qtscript_create_QLayoutProperty_class
    , qtscript_create_QSizeProperty_class
    , qtscript_create_QDoubleProperty_class
    , qtscript_create_QIntegerProperty_class
    , qtscript_create_QColorProperty_class
    , qtscript_create_QGraphProperty_class
};

void qtscript_initialize_tulip_script_bindings(QScriptValue &extensionObject)
{
    QScriptEngine *engine = extensionObject.engine();
    for (int i = 0; i < 14; ++i) {
        extensionObject.setProperty(qtscript_tulip_script_class_names[i],
            qtscript_tulip_script_class_functions[i](engine),
            QScriptValue::SkipInEnumeration);
    }
}
