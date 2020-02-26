package lab2;

public class StringTest {
	public static void main(String[] args){
		String message = "Hello, World!";
		System.out.println(message);
		
		int theLength = message.length();
		System.out.println(theLength);
		
		char theChar = message.charAt(0);
		System.out.println(theChar);

		theChar = message.charAt(12);
		System.out.println(theChar);
		
		String upperCase = message.toUpperCase();
		System.out.println(upperCase);
		
		String var = message.substring(0,5);
		System.out.println(var);
		
		String newMessage = message.replace('o','*');
		System.out.println(newMessage);
	}
}
