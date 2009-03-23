#include <stdio.h>

#include "qtjambi_core.h"
#include <jni.h>

#include <tulip/Graph.h>
#include <tulip/TlpTools.h>

#include "QGraph.h"

#include <iostream>
using namespace std;

#define CLASS_NAME1_(x) #x
#define CLASS_NAME_(x) CLASS_NAME1_(x)
#define CLASS_NAME CLASS_NAME_(JAVA_FILE)

void invoke_class(JNIEnv* env, QGraph* graph) {

	//find our plugin's class
	jclass jambiPluginClass = env->FindClass(CLASS_NAME);
	if (jambiPluginClass == 0) {
	    qWarning("Failed to find class: ");
	    env->ExceptionDescribe();
	    return ;
	}

	//call it's main method (must initialize QtJambi : QApplication.initialize(String[]);
/*
	jmethodID mainMethod = env->GetStaticMethodID(jambiPluginClass, "main", "([Ljava/lang/String;)V");
	jobjectArray applicationArgs = env->NewObjectArray(1, env->FindClass("java/lang/String"), NULL);
	jstring applicationArg0 = env->NewStringUTF("coucou");
	env->SetObjectArrayElement(applicationArgs, 0, applicationArg0);
	env->CallStaticVoidMethod(jambiPluginClass, mainMethod, applicationArgs);
	env->ExceptionDescribe();
*/

	//now we get the run(QGraph) method, which should be the actual algorithm
	jmethodID runMethod = env->GetStaticMethodID(jambiPluginClass, "run", "(Lcom/tulip/jambi/QGraph;)V");
//	env->ExceptionDescribe();
	jobject QGraphJambi = qtjambi_from_object(env, graph, "QGraph", "com/tulip/jambi/", true);
//	env->ExceptionDescribe();
	if (QGraphJambi == 0) {
	    qWarning("Failed to find class");
	    env->ExceptionDescribe();
//	    qtjambi_exception_check(env);

	    return ;
	}
	//and then we call it
	env->CallStaticVoidMethod(jambiPluginClass, runMethod, QGraphJambi);
}


class myJVM {
public:
	static myJVM* getInstance() { if(_myJVM == 0) _myJVM = new myJVM(); return _myJVM; }
	static void kill() { delete _myJVM; }
	JavaVM* jvm() { return _jvm; }
	JNIEnv* env() { return _env; }

private:
	myJVM() {
		JavaVMInitArgs args;
		JavaVMOption options[1];

		args.version = JNI_VERSION_1_4;
		args.nOptions = 1;

		std::stringstream classPath;
		classPath << "-Djava.class.path=";
		classPath << ":" << tlp::TulipPluginsPath << "/jambi";
		classPath << ":" << tlp::TulipPluginsPath << "/jambi/tulip-qtjambi.jar";
		classPath << ":" << tlp::TulipPluginsPath << "/jambi/qtjambi.jar";
		char ClassPath[classPath.str().length()];
		strcpy(ClassPath, classPath.str().c_str());
		options[0].optionString = ClassPath;

		args.options = options;
		args.ignoreUnrecognized = JNI_TRUE;

		JNI_CreateJavaVM(&_jvm, (void **)&_env, &args);
	}
	~myJVM() { _jvm->DestroyJavaVM(); }

	JavaVM* _jvm;
	JNIEnv* _env;
	static myJVM* _myJVM;
};

myJVM* myJVM::_myJVM = 0;

void initialize_jambi_plugin(tlp::Graph* graph) {

	std::cout << "============" << std::endl;

	QGraph* g = new QGraph(graph);
	JNIEnv* env = myJVM::getInstance()->env();
	invoke_class(env, g);
 	delete g;

 	std::cout << "============" << std::endl << std::endl;
}
