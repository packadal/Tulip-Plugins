#include <QtScript/QScriptExtensionPlugin>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>

void qtscript_initialize_tulip_script_bindings(QScriptValue &);

class tulip_script_ScriptPlugin : public QScriptExtensionPlugin
{
public:
    QStringList keys() const;
    void initialize(const QString &key, QScriptEngine *engine);
};

QStringList tulip_script_ScriptPlugin::keys() const
{
    QStringList list;
    list << QLatin1String("tulip");
    list << QLatin1String("tulip.script");
    return list;
}

void tulip_script_ScriptPlugin::initialize(const QString &key, QScriptEngine *engine)
{
    if (key == QLatin1String("tulip")) {
    } else if (key == QLatin1String("tulip.script")) {
        QScriptValue extensionObject = engine->globalObject();
        qtscript_initialize_tulip_script_bindings(extensionObject);
    } else {
        Q_ASSERT_X(false, "tulip_script::initialize", qPrintable(key));
    }
}

Q_EXPORT_STATIC_PLUGIN(tulip_script_ScriptPlugin)
Q_EXPORT_PLUGIN2(qtscript_tulip_script, tulip_script_ScriptPlugin)
