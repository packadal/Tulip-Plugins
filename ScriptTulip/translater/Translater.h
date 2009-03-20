#ifndef TRANSLATER_H_
#define TRANSLATER_H_

#include <QFile>
#include <QMap>
#include <QPair>
#include <QString>
#include <QRegExp>
#include <QMetaMethod>
#include <QMetaObject>

#include "TulipScriptEngine.h"

class Translater {
public:
	Translater();
	Translater(QString);
	virtual ~Translater();
	QString convert();
	void initMap();
	void parse();
	void parseTypes(QObject* obj);
	void viewMap();
private:
	bool toCast;
	QString parseIteratorType(QString functionName);
	QString addLine(QString line);
	QString fetchType(QString line, QString varName = "");
	QString checkQuotedText(QString line);
	QString fetchReturnType(QString line, QString varName = "");
	QFile* fileStream;
	QFile* outputFile;
	TulipScriptEngine* scriptEngine;
	QMap<QPair<QString,int>, QString> functionToType;
	QMap<QString, QString> itToType;
};

#endif /* TRANSLATER_H_ */
