/*
 * DataScriptClass.h
 *
 *  Created on: 30 oct. 2008
 *      Author: chuet
 */

#ifndef DATASCRIPTCLASS_H_
#define DATASCRIPTCLASS_H_

#include <QObject>
#include <QScriptClass>
#include <QScriptContext>

class DataScriptClass : public QObject, public QScriptClass
{
	Q_OBJECT
public:
	DataScriptClass(QScriptEngine*);
	QScriptValue newInstance();

private:
	QScriptValue _prototype;
	QScriptValue _ctor;
	static QScriptValue construct(QScriptContext *ctx, QScriptEngine *eng);

	static QScriptValue toScriptValue(QScriptEngine *eng, const QByteArray &ba);
	static void fromScriptValue(const QScriptValue &obj, QByteArray &ba);


};

#endif /* DATASCRIPTCLASS_H_ */
