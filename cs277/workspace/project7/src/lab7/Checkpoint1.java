package lab7;

import java.util.Arrays;
import java.util.Random;

public class Checkpoint1 {
	public static int[] getPositiveNumbers(int[] numbers){
	    
	    int count = 0;
	    int index = 0;
	    
	    while(numbers.length > count)
	    {
	      if(numbers[count] > 0)
	    	  index +=1;
	      count ++;
	    }
	    int[] positiveNum = new int[index];

	    count = 0;
	    int i = 0;
	    while(numbers.length > count){
	    	if(numbers[count] > 0){
	    		positiveNum[i] = numbers[count];
	    		i ++;
	    	}
	    	count ++;
	    }
	    return positiveNum;
	}
	
	public static int[] randomExperiment(int max, int iters){
		int[] counts = new int[max];
		Random rnd = new Random(127);
		while(iters > 0){
			int i = rnd.nextInt(max);
			counts[i] = counts[i] + 1;
			iters --;
		}
		return counts;
	}
	
	public static void switchHalves(int[] numbers){
		int front = 0;
		int rear = numbers.length / 2;
	    while (rear <numbers.length)
	    {
	    
	      int temp = numbers[front];
	      numbers[front] = numbers[rear];
	      numbers[rear] = temp;	      
	      // move indices towards the center
	      front += 1;
	      rear += 1;
	    }
	    
	}
}
