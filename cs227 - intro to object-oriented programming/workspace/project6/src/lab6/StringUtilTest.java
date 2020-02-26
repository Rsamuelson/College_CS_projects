package lab6;

public class StringUtilTest {
	 public static void main(String[] args)
	  {
	    // should return "ready"
	    System.out.println("test raedy, expected: ready; got: " + StringUtil.fixSpelling("raedy"));
    
	    // should return "ready"
	    System.out.println("test bleu, expected: blue; got: " + StringUtil.fixSpelling("bleu"));
	  }
}
