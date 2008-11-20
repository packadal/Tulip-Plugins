#include <QApplication>

#include "Application.h"

#include "Data.h"
#include "CurveGroup.h"
#include "HistogramGroup.h"
#include "ScriptViewer.h"

Application::Application()
{
	// Display the viewer window
	ScriptViewer* v1 = new ScriptViewer();
	v1->show();
	v1->scale(3);

	// An example of script :
	/*
		var data = Data();
		data.add(10, 3);
		data.add(30, 4);
		data.add(40, -10);
		data.add(50, 6);
		data.add(60, 12);
		var curve = viewer.addCurve(data);
		var histogram = viewer.addHistogram(data);
		curve.setColor(255, 0, 0);
		histogram.setColor(0, 255, 0, 125);
		viewer.refresh(); // To validate color change
	*/

}

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	Application appli;

	return app.exec();
}
