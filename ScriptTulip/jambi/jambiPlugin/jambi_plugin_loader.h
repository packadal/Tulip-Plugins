#include <stdio.h>

#include "qtjambi_core.h"
#include <jni.h>

#include <tulip/Graph.h>
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
	//TODO use tulip's tools to get tulip's path and use it
	options[0].optionString = "-Djava.class.path=/home/packadal/temp/tulip-plugins-read-only/ScriptTulip/jambi:/home/packadal/temp/tulip-plugins-read-only/ScriptTulip/jambi/tulip-qtjambi-linux32-gcc-4.4.3_01.jar:/var/lib/QT4/qtjambi-4.4.3/qtjambi-4.4.3_01.jar:";
	args.options = options;
	args.ignoreUnrecognized = JNI_FALSE;

	JNI_CreateJavaVM(&jvm, (void **)&env, &args);
	return env;
}

#define MKSTRING(arg) #arg

void invoke_class(JNIEnv* env, QGraph* graph) {
	jclass jambiPluginClass = (env)->FindClass(MKSTRING(JAVA_FILE));

	if (jambiPluginClass == 0) {
	    qWarning("Failed to find class");
	    
	    qtjambi_exception_check(env);
	    return ;
	}

	jmethodID runMethod = (env)->GetStaticMethodID(jambiPluginClass, "run", "(Lcom/tulip/jambi/QGraph;)V");
	env->ExceptionDescribe();
	
	jobject QGraphJambi = qtjambi_from_object(env, graph, "QGraph", "com/tulip/jambi/", true);
	if (QGraphJambi == 0) {
	    qWarning("Failed to find class");
	    
	    qtjambi_exception_check(env);
	    return ;
	}
	
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