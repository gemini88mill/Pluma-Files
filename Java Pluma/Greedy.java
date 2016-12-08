/*	Greedy.java - A program that uses a greedy algorithm to solve the solution
	
	This program will attempt to solve the coin change problem, i.e. using a 
	greedy algorithm, solve for any value and give the least amount of change 
	back.  */

import java.io.*;

public class Greedy{

	public static int[] denominations = {1, 5, 10, 25};

	public static void main(String[] args){
		//args[0] is the change to be given
		int change = Integer.parseInt(args[0]);

		int[] coins = new int[4];
		int denom = coins.length - 1;		
		
		makeChange(change, coins, denom);
		
		System.out.println("Coins:");
		for(int i = 0; i < coins.length; i++){
			System.out.println("coin(" + i + "): " + coins[i]);		
		}	
	}

	public static int[] makeChange(int n, int[] coin, int denom){
		//method to make change using a greedy approach.

		
		//baseCase - no more change can be given or n = 0
		if(n == 0)
			return coin;
		else{
			if(n >= denominations[denom]){
				n = n - denominations[denom];
				coin[denom]++;
				makeChange(n, coin, denom);			
			} else {
				makeChange(n, coin, denom - 1);			
			}		
		}
		return null;
			
	}
}
