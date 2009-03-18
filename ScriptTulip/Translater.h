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
	QString parseLine(QString line);
	void parseTypes(QObject* obj);
	void viewMap();
private:
	QString addLine(QString line);
	QString fetchType(QString line);
	QString checkQuotedText(QString line);
	QString fetchReturnType(QString line);
	QFile* fileStream;
	QFile* outputFile;
	TulipScriptEngine* scriptEngine;
	QMap<QPair<QString,int>, QString> functionToType;
	QMap<QString, QString> varToType;
};

#endif /* TRANSLATER_H_ */
