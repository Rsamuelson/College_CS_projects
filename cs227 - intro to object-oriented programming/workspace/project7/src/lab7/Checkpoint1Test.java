package lab7;
import java.util.Arrays;
public class Checkpoint1Test {
	public static void main(String[] agrs){
		int[] arr = new int[8];
		arr[0] = 8;
		arr[1] = 1;
		arr[2] = 5;
		arr[3] = -3;
		arr[4] = -7;
		arr[5] = 3;
		arr[6] = 2;
		arr[7] = 9;
		
		System.out.println("original: " + Arrays.toString(arr));
		int[] newArr = Checkpoint1.getPositiveNumbers(arr);
		System.out.println("after getPositiveNumbers: " + Arrays.toString(newArr));
		System.out.println();
		
		int max = 10;
		int iters = 1000;
		System.out.println(Arrays.toString(Checkpoint1.randomExperiment(max, iters)));
		System.out.println();

		
		int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8};
		System.out.println("original: " + Arrays.toString(numbers));
		Checkpoint1.switchHalves(numbers);
		System.out.println("after switchHalves: " + Arrays.toString(numbers));
	}
}