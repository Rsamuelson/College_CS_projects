package lab4;
import java.util.Scanner;

public class Bibliography {
	public static void main(String[] args)
	{
		String s1 = "Dijkstra, Edsger#Go To Statement Considered Harmful#Communications of the ACM#1968#11";
		String s2 = "Levoy, Marc#Display of Surfaces from Volume Data#IEEE Computer Graphics and Applications#1988#8";
		String s3 = "Dean, Jeffrey; Ghemawat, Sanjay#MapReduce: Simplified Data Processing on Large Clusters#Communications of the ACM#2008#51";
		
		BibItem item1 = myHelperMethod(s1);
		BibItem item2 = myHelperMethod(s2);
		BibItem item3 = myHelperMethod(s3);
		System.out.println(item1);
		System.out.println(item2);
		System.out.println(item3);

	}
	
	private static BibItem myHelperMethod(String s)
	{
	  // parse the given string s and return a new BibItem
		Scanner string = new Scanner(s);
	     string.useDelimiter("#");
	     String authors = string.next();
	     String title = string.next();
	     String journal = string.next();
	     int year = string.nextInt();
	     int volume = string.nextInt();
	     
	     String authorsUp = authors.toUpperCase();
	     BibItem BibItemS = new BibItem(authorsUp, title, journal, year, volume);
	     
	     return BibItemS;
	}
}
