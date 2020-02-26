package lab8;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


//public class LineNumberer {
//	public static void main(String[] args) throws FileNotFoundException {
//		File file = new File("../project7/src/lab7/Deck.java");
//	    Scanner scanner = new Scanner(file);
//	    File outFile = new File("checkpoint1-2.txt");
//	    PrintWriter out = new PrintWriter(outFile);
//	    int lineCount = 1;
//
//	    while (scanner.hasNextLine())
//	    {
//	    	String line = scanner.nextLine();
//	    	out.println(lineCount + " " + line);
//	    	lineCount += 1;
//	    }
//	    
//	    System.out.println("Done");
//	    out.close();
//
//	}
//}


public class LineNumberer {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(System.in);
	    File outFile = new File("checkpoint1-1.txt");
	    PrintWriter out = new PrintWriter(outFile);
	    int lineCount = 1;

	    while (scanner.hasNextLine())
	    {
	    	String line = scanner.nextLine();
	    	out.println(lineCount + " " + line);
	    	lineCount += 1;
	    }
	    
	    System.out.println("Done");
	    out.close();

	}
}