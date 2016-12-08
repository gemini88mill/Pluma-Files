//fib.java 
//Created by Raphael MIller 
//on 12.03.2016

import java.io.*;
import java.lang.*;
import java.util.*;

public class fib{

	private static int[] memo = new int[46];
	private static boolean init = false;

	private static void initalize(){
		Arrays.fill(memo, -1);	
	}

	//this is the recursion method to fibonacci
	private static int computeFib(int n){
		
		//System.out.println(n);
		//baseCases
		if(n < 2)
			return n;

		return computeFib(n - 2) + computeFib(n - 1);
	}

	//memo method
	private static int computeFibMemo(int n){
		//object is to take all calls to already calculated values and store them
		//in memo array. 

		//array needs to be initialized, but cannot be initialized in the method 
		//because the method will recurse, so...

		if(!init){
			initalize();
			init = true;
		}		
		
		//basecase
		memo[0] = 0;
		memo[1] = 1;

		if(memo[n] != -1){
			return memo[n];		
		}	
		
		memo[n] = computeFibMemo(n - 1) + computeFibMemo(n - 2);
		return memo[n]; 
	}

	private static int fib_dp(int n){
		//using only loops

		int[] fibArr = new int[n + 1];
		
		fibArr[0] = 0;
		fibArr[1] = 1;

		for(int i = 2; i <= n; i++){
			fibArr[i] = fibArr[i - 1] + fibArr[i - 2];		
		}	
		
		return fibArr[n];
	}
	
	public static void main(String[] args){
		//System.out.println("Hello World");

		//accepts command line arguements for the number of fib that we can count to. 
		int input = Integer.parseInt(args[0]);

		long start = System.currentTimeMillis();
		long start2;
		System.out.println(fib_dp(input) + " \tProcessing Time: " + (System.currentTimeMillis() - start) + "ms");
		System.out.println(computeFibMemo(input) + " \tProcessing Time: " + (System.currentTimeMillis() - start) + "ms");
		
		start2 = System.currentTimeMillis();
		System.out.println(computeFib(input) + " \tProcessing Time: " + (System.currentTimeMillis() - start2));
		
		
		
	}
}
