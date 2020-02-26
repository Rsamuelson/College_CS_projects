package lab9;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;

public class Checkpoint2 {
	public static void main(String[] args){
		int[] arr = {3, 4, 7, 1, 2, 5, 8};
//		System.out.println("max: " + arrayMax(arr));
		
		String rootDirectory = "."; 

		countAllBytes(new File(rootDirectory));
		

//	    System.out.println("files: " + findFiles(new File(rootDirectory)));
	}
	
	public static int arrayMax(int[] arr){
	    return findMaxOfArray(arr, 0, arr.length - 1);
	}
	
	public static int findMaxOfArray(int[] arr, int start, int end){
		int max;
		int mid = (start+end)/2;
		if(start == end){
			return arr[start];
		}
		else{
			int max1 = findMaxOfArray(arr, start, mid);
		    int max2 = findMaxOfArray(arr, mid + 1, end);
		
		    if(max1 > max2){
		    	max = max1;
		    }
		    else{
		    	max = max2;
		    }
		}
		return max;
	}
	
	public static void countAllBytes(File f)
	{
	    // start off at level 0
		System.out.println("bytes: " + countBytes(f, 0));
	}
	
	public static long countBytes(File f, int level){
		long totalBytes = 0;
	    if (!f.isDirectory())
	    {
	    	System.out.println("name: " + f.getName() + " Bytes: " + f.length());
	      // Base case: f is a file,
	    	return f.length();
	    	
	    }
	    else{
	    	File[] files = f.listFiles();
	        for (int i = 0; i < files.length; ++i)
	        {
	        	totalBytes = totalBytes + countBytes(files[i], level + 1);
	        }
	        
	    }
	   return totalBytes;
	}
	
	public static ArrayList<String> findFiles(File file)
	  {
	    // create an empty array list...
	    ArrayList<String> arr = new ArrayList<String>();
	    
	    // pass it into the recursive method
	    findFilesRec(file, arr);
	    
	    // and return the filled-up ArrayList
	    return arr;
	  }

	  // recursive helper method
	  private static void findFilesRec(File file, ArrayList<String> list) {
		  if (!file.isDirectory()){
		      // Base case: f is a file, so just add its name to the list if an array
		      if(file.getName().endsWith(".java")){
		    	  list.add(file.getName());
		      }
		  }
		    else
		    {
		    	// General case: f is a directory, so recursively list the 
		    	// files and subdirectories it contains
		    	File[] files = file.listFiles();
		    	for(int i = 0; i < files.length; i++){
		    		findFilesRec(files[i], list);
		    	}
		    }
	  }

	 
}
