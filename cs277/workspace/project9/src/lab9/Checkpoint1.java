package lab9;

public class Checkpoint1 {
	 public static void main(String[] args){
		int num = 7;
		System.out.println(getPyramidCount(num));
	}
	
	public static int getPyramidCount(int n){
		int totalNumOfBalls = 0;
		if(n > 0){
			totalNumOfBalls = n*n + getPyramidCount(n-1);
		}
		return totalNumOfBalls;
	}
}