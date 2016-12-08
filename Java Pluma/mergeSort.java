import java.io.*;

public class mergeSort{

	public void merge(int[] array, int max, int min){
		int split = (max - min) / 2;
		
		int[] lower = new int[split];
		for(int i = 0; i < split; i++){
			
		}

		
	}

	public static void main(String[] args){
		System.out.println("Hello World");

		//create a random array of values from 1 to 100 using the arg
		int[] array = new int[Integer.parseInt(args[0])];

		
		for(int i = 0; i < array.length; i++){
			array[i] = (int)(Math.random() * 100) + 1;
			System.out.println(array[i]);

				
		}

		int min = 0;
		int max = array.length - 1;
	}
}
