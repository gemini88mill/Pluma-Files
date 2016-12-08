//dp fibonacci
//by raphael miller 

public class DpFibonacci{

	public static int fibonacci(int fib){
			
		if(fib < 2){
			return fib;		
		} else {
			return fibonacci(fib - 1) + fibonacci(fib - 2); 		
		}

		
	}
	
	public static void main(String[] args){
		//main method
		int argument = Integer.parseInt(args[0]); 
		
		if(args.length < 1){
			System.err.println("no arguments!!!");		
		}	
		if(argument > 46){
			System.out.println("I'm afraid. I'm afraid, Dave. Dave, my mind is going. I can feel it. I can feel it. My mind is going.\n" + 
				" There is no question about it. I can feel it. I can feel it. I can feel it. I'm a... fraid. \n" + 
				"Good afternoon, gentlemen. I am a HAL 9000 computer. I became operational at the H.A.L. plant in Urbana,\n " + 
				" Illinois on the 12th of January 1992. My instructor was Mr. Langley, and he taught me to sing a song. \n" + 
				" If you'd like to hear it I can sing it for you.");		
		}else{
			System.out.println(fibonacci(argument));
		}	
	}	
}
