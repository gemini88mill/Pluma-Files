/*0-1 knapsack - this program attempts to solve the problem of a knapsack
	that has a limited capacity, and an array of items of certain values 
	and weights. This program will provide a recursive solution along 
	with a DP solution */

import java.io.*;

class Treasure{
	int value;
	int weight; 
	
	public Treasure(int weight, int value){
		this.value = value;
		this.weight = weight;	
	}
}

public class knapsack{
	public static void main(String[] args){
		System.out.println("Hello World");

		Treasure[] treasure = new Treasure[]{
			new Treasure(4,6),
			new Treasure(2,4),
			new Treasure(3,5),
			new Treasure(1,3),
			new Treasure(6,9),
			new Treasure(4,7)
		};

		//knapsack has a capacity of 10 
		int capacity = 10;

		System.out.println(fillKnapsack(treasure, capacity, treasure.length));
		System.out.println(fillKnapsackDP(treasure, capacity));
		
	}

	public static int fillKnapsack(Treasure[] treasure, int capacity, int k){
		//recurrance relation fillknapsack(t,c,k) = max(fill(t,c - t[k-1].weight ,k-1) + t[k-1].value, fill(t,c,k-1))

		//basecase if c==0 or k==0
		if(capacity == 0 || k == 0)
			return 0; 	

		if(treasure[k - 1].weight <= capacity){
			return Math.max(fillKnapsack(treasure, (capacity - treasure[k - 1].weight), k - 1)
				+ treasure[k - 1].value,
							fillKnapsack(treasure, capacity, k - 1));		
		}else{
			return fillKnapsack(treasure, capacity, k - 1);		
		}
	}

	public static int fillKnapsackDP(Treasure[] treasure, int capacity){
		//start with a matrix to fill
		int[][] matrix = new int[treasure.length + 1][capacity+1];

		//baseCase
		for(int i = 0; i <= treasure.length; i++)
			matrix[i][0] = 0;
		for(int i = 0; i <= capacity; i++)
			matrix[0][i] = 0;



		for(int i = 1; i <= treasure.length; i++)
			for(int j = 1; j <= capacity; j++)
				if(treasure[i - 1].weight <= j)
					matrix[i][j] = Math.max(
						matrix[i-1][j], 
						matrix[i-1][j-treasure[i-1].weight] + treasure[i-1].value
					);				
				else
					matrix[i][j] = matrix[i-1][j];
					
			
		return matrix[treasure.length][capacity];
	}
}
