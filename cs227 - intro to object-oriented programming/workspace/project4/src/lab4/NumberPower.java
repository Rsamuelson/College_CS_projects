package lab4;
import java.util.Scanner;

public class NumberPower {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		
		int firstNum = getNextNumber(scanner);
		
		int secendNum = getNextNumber(scanner);
		
		int power = (int) Math.pow(firstNum, secendNum);
	    System.out.print(firstNum + " ^ " + secendNum + " = " + power);
	    

	}
	private static int getNextNumber(Scanner scanner){
		  System.out.print("Enter a number: ");
		    if (scanner.hasNextInt()){
			    int next = scanner.nextInt();
			    return next;
		    }
		    else{
		    	scanner.next();
		    	return 1;
	
		    }
	}
}
