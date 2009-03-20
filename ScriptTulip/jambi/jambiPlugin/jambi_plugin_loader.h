#include <stdio.h>

#include "qtjambi_core.h"
#include <jni.h>

#include <tulip/Graph.h>
#include <tulip/TlpTools.h>

#include "QGraph.h"

#include <iostream>
using namespace std;


JNIEnv* create_vm() {
	JavaVM* jvm;
	JNIEnv* env;
	JavaVMInitArgs args;
	JavaVMOption options[1];

// 	 There is a new JNI_VERSION_1_4, but it doesn't add anything for the purposes of our example.
	args.version = JNI_VERSION_1_2;
	args.nOptions = 1;
//	options[0].optionString = "-Djava.class.path=/home/packadal/Skuld/workspace/ScriptTulip/jambi/jambiPlugin:/home/packadal/Skuld/workspace/ScriptTulip/jambi/tulip-qtjambi-linux32-gcc-4.5.0_01.jar:/var/lib/QT4/qtjambi/qtjambi-4.5.0_01.jar:";

	std::stringstream classPath;
	classPath << "-Djava.class.path=";
//	classPath << tlp::TulipPluginsPath;
	classPath << ":" << tlp::TulipPluginsPath << "/jambi";
	classPath << ":" << tlp::TulipPluginsPath << "/jambi/tulip-qtjambi.jar";
	classPath << ":" << tlp::TulipPluginsPath << "/jambi/qtjambi.jar";
	char ClassPath[classPath.str().length()];
	strcpy(ClassPath, classPath.str().c_str());
	options[0].optionString = ClassPath;

	args.options = options;
	args.ignoreUnrecognized = JNI_FALSE;

	JNI_CreateJavaVM(&jvm, (void **)&env, &args);
	return env;
}

#define FINDCLASS(arg) env->FindClass(#arg)
#define SHOW(arg) std::cout << "arg: " << #arg << std::endl

#define CLASS_NAME1_(x) #x
#define CLASS_NAME_(x) CLASS_NAME1_(x)
#define CLASS_NAME CLASS_NAME_(JAVA_FILE)

void invoke_class(JNIEnv* env, QGraph* graph) {

	resolveClass(env, CLASS_NAME, "");
	//find our plugin's class
	jclass jambiPluginClass = env->FindClass(CLASS_NAME);
	if (jambiPluginClass == 0) {
	    qWarning("Failed to find class: ");

	    qtjambi_exception_check(env);
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
	env->ExceptionDescribe();
	jobject QGraphJambi = qtjambi_from_object(env, graph, "QGraph", "com/tulip/jambi/", true);
	env->ExceptionDescribe();
	if (QGraphJambi == 0) {
	    qWarning("Failed to find class");
	    env->ExceptionDescribe();
	    qtjambi_exception_check(env);

	    return ;
	}
	//and then we call it
	env->CallStaticVoidMethod(jambiPluginClass, runMethod, QGraphJambi);

}


void initialize_jambi_plugin(tlp::Graph* graph) {

// 	qtjambi_initialize_vm();
// 	JNIEnv* env = qtjambi_current_environment();
 	JNIEnv* env = create_vm();
	QGraph* g = new QGraph(graph);
	invoke_class(env, g);
// 	delete g;
}
