package lab8;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import java.awt.Point;
import plotter.Plotter;
import plotter.Polyline;
import java.lang.String;


public class Checkpoint2 {
	
	  public static void main(String[] args) throws FileNotFoundException{
		  //test.txt
		  //hello.txt
		  String file = "hello.txt";
		  ArrayList<Polyline> list = readfile(file);
		  printPolylines(list);
	  }
	  
	  private static ArrayList<Polyline> readfile(String filename) throws FileNotFoundException {
		  File file = new File(filename);
		  Scanner scanner = new Scanner(file);
		  ArrayList<Polyline> list = new ArrayList<Polyline>();
		  while (scanner.hasNextLine()){
			  String line = scanner.nextLine();
			  line.trim();
			  if(line.isEmpty()){
				  line = scanner.nextLine();
				  line.trim();
			  }
			  
			  else if(line.contains("#")){
				  line = scanner.nextLine();
				  line.trim();
			  }
			  else{
				  list.add(addToArrayList(line, list));
			  }
			
		  }
		  return list;
	  }
	  

	  private static Polyline addToArrayList(String line, ArrayList<Polyline> list) {
		  Scanner temp = new Scanner(line);
		  int width;
		  if(temp.hasNextInt()){
			  width = temp.nextInt();
		  }
		  else 
			  width = 1;
		  String color = temp.next();
		  Polyline p1 = new Polyline(color, width);

		  while(temp.hasNextInt()){
			  int point1 = temp.nextInt();
			  int point2 = temp.nextInt();
			  p1.addPoint (new Point(point1, point2));
		  }
		  return p1;
	}

	private static void printPolylines(ArrayList<Polyline> list){
		 Plotter plotter = new Plotter();
		for(int x = 0; list.size() > x; x++){
		    plotter.plot(list.get(x));
		}
	  }
}
