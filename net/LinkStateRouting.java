package javtut;
//import java.lang.FunctionalInterface;
import java.util.*;

public class LinkStateRouting {
	public static void main(String args[]) {
	 Scanner sc = new Scanner(System.in);
	 
	  System.out.println("Enter The No of Nodes :");
	  int nodeCount=sc.nextInt();
	  int[] pred = new int[nodeCount];
	  int[] visited= new int[nodeCount];
	  int[] distances =new int[nodeCount];
	  int[][] costMat= new int[nodeCount][nodeCount];
	  
	  for(int i=0;i<nodeCount;i++) {
		  visited[i]=0;
		  pred[i]=0;
		  for(int j=0;j<nodeCount;j++) {
			  costMat[i][j]=sc.nextInt();
		      if(costMat[i][j]==0 && i!=j) {
		    	  costMat[i][j]=999;
		      }
			   
		  }
	  }
	  //end of input
	  distances=costMat[0];
	  visited[0]=1;
	  distances[0]=0;
	  
	  for(int count=0;count<nodeCount-1;count++) {
		  int mindist=999;
		  int nextNode=0;
		  for(int i=0;i<nodeCount;i++) {
			  if(visited[i]==0 && distances[i] < mindist) {
				  mindist=distances[i];
				  nextNode=i;
			  }
		  }
		  visited[nextNode]=1;
		  
		  for(int i=0;i<nodeCount;i++) {
			  if(visited[i]==0 && mindist + costMat[nextNode][i] < distances[i]) {
				  distances[i]=mindist+costMat[nextNode][i];
				  pred[i]=nextNode;
			  }
		  }
	  }
	  for (int i = 1; i < nodeCount; i++) {
          System.out.print("Shortest path to node " + i + " = " + i);
          int currentNode = i;
          while (currentNode != 0) {
              currentNode = pred[currentNode];
              System.out.print(" <- " + currentNode);
          }
          System.out.println();
          System.out.println("Cost = " + distances[i] + "\n");
      }

      //scanner.close();
	  
	  
	  
	}
}
