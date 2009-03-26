import com.tulip.java.QGraph;
import com.tulip.java.QNode;
import com.tulip.java.QEdge;
import com.tulip.java.QIterator;


class Main
{
    public static void main(String args[])
    {
	QGraph g = new QGraph();
	QNode n1 = g.addNode();
	QNode n2 = g.addNode();
	QNode n3 = g.addNode();
	g.addEdge(n1, n2);
	g.addEdge(n2, n3);
	g.addEdge(n3, n1);
	
	g.saveGraph("testTriangle.tlp");

	QGraph g2 = g.loadGraph("testTriangle.tlp");
	QIterator it = g2.getNodes();
	it.next();it.next(); // Skip first two nodes
	System.out.println(g2.numberOfNodes());
	QNode n4 = (QNode)it.next();
	QNode n5 = g2.addNode();
	g2.addEdge(n4, n5); // Add to the saved graph a new edge
	
	g2.saveGraph("testTriangle2.tlp"); // save the new graph
	
    }
}