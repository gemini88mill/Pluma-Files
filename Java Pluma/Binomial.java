//Binomial Coefficients, Recursive and DP solution 
//created by Raphael Miller on 12.05.2016

import java.io.*;
import java.util.*;


public class Binomial{

	static int[][] memo;
	static boolean initialized = false;

	public static void init(){
		//initalize 
		Arrays.fill(memo, -1);	
	} 

	public static void main(String[] args){
		//System.out.println("Hello World");

			
		//eseentially a choose function, we shall accept two perams 
		//where first value equals n and the second value equals k

		int n, k = 0;

		n = Integer.parseInt(args[0]);
		k = Integer.parseInt(args[1]);
		
		System.out.println(n + "\t" + k);

		int solution = recursiveBinomial(n, k);
		System.out.println(memoBinomial(n, k));
		System.out.println(solution);
	}

	public static int recursiveBinomial(int n, int k){
		//n choose k, using the simple n! solution from COT 3100 could cause overflow
		//so its more important form a recursive function 
		
		//the recurrance relation goes like this: 
		
		/*	C(n, k) = C(n-1, k-1) + C(n-1, k) where C(n,0) = C(n,n) = 1 for all n >= 0
			This states that for all of our choices, we have n choices and we choose k
			of them, then that would imply that we have two choices to choose from; 
			either we take one nth item (which also implies that we choose a k) or we 
			dont shoose that item, in which we still have a k choice but with n - 1 
			items. We also see that if we have n to choose from and we choose all of them
			then our solution is 1, or if we choose none of them, our solution is also 1

			This only holds if our choices are > 0, if we have nothing to choose from, 
			then we cannot make a choice		
		*/

		//baseCase

		//first basecase because this breaks our solution. 
		if(k == 0 || k == n)
			return 1;
		
		return recursiveBinomial(n - 1, k - 1) + recursiveBinomial(n - 1, k);
			
	} 

	public static int memoBinomial(int n, int k){
		//memo version of binomial expansion
		
		int[][] matrix = new int[n + 1][k + 1];
		

		//basecase 
		for(int i = 1; i <= n; i++){
			//n cant be zero
			matrix[i][0] = 1;		
		}
		
		for(int i = 0; i <= k; i++){
			matrix[i][i] = 1;
		}		
		
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= Math.min(i - 1, k); j++){
				matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];			
			}		
		}
		
			
		return matrix[n][k];
	}
}




















