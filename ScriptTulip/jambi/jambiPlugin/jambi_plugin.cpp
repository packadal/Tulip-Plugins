#include <tulip/TulipPlugin.h>
#include <string>

#include "jambi_plugin_loader.h"

using namespace std;
using namespace tlp;

/** Algorithm documentation */
// MyColorAlgorithm is just an example
/*@{*/


class JambiAlgorithm:public Algorithm {
public:

  // The constructor below has to be defined,
  // it is the right place to declare the parameters
  // needed by the algorithm,
  // addParameter<DoubleProperty>("metric", paramHelp[0], 0, false);
  // and declare the algorithm dependencies too.
  // addDependency<Algorithm>("Quotient Clustering", "1.0");
  JambiAlgorithm(AlgorithmContext context):Algorithm(context) {
  }

  // Define the destructor only if needed
  // ~MyColorAlgorithm() {
  // }

  // Define the check method only if needed.
  // It can be used to check topological properties of the graph,
  // metric properties on graph elements or anything else you need.
  // bool check(string& errorMsg) {
  //   errorMsg="";
  //   return true;
  // }

  // The run method is the main method :
  //     - It will be called out if the pre-condition method (bool check (..)) returned true.
  //     - It is the starting point of your algorithm.
  // The returned value must be true if your algorithm succeeded.
  bool run() {
	initialize_jambi_plugin(graph);
    return true;
  }

  bool check() {
      return true;
  }
};
/*@}*/

// This line is very important because it's the only way to register your algorithm in tulip.
// It automatically builds the plugin object that will embed the algorithm.
ALGORITHMPLUGIN(JambiAlgorithm, CLASS_NAME, "Packadal", "18/03/09", "Comments", "1.0")
// If you want to present your algorithm in a dedicated submenu of the Tulip GUI,
// use the declaration below where the last parameter specified the name of submenu.
// COLORPLUGINOFGROUP(MyColorAlgorithm, "My Color Algorithm", "Authors", "07/07/07", "Comments", "1.0", "My algorithms");

