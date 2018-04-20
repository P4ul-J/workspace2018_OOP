package de.tuvision.counter;

public class CounterUnitTest {
	
	static boolean testBaseCounter(){
		System.out.println("Testing ForwardCounter for BaseCounter functionality:");
		Counter counter = new ForwardCounter();
		
		if(counter.getValue() != 0){
			System.out.println("ForwardCounter: Value not initialized as 0!");
			return false;
		}
				
		counter.setValue(10);
		if(counter.getValue() != 10){
			System.out.println("ForwardCounter: Incorrect setValue()!");
			return false;
		}
		
		Counter secondCounter = new ForwardCounter();
		secondCounter.setValue(8);
		counter.adoptValue(secondCounter);
		if(counter.getValue() != 8){
			System.out.println("ForwardCounter: Incorrect adoptValue()!");
			return false;
		}
		
		return true;
	}

	static boolean testForwardCounter(){
		System.out.println("Testing ForwardCounter:");
		Counter counter = new ForwardCounter();
		
				
		counter.count();
		counter.count();
		if(counter.getValue() != 2){
			System.out.println("ForwardCounter: Incorrect Counting!");
			return false;
		}
		
		return true;
	}
	
	static boolean testVariableCounter(){
		System.out.println("Testing VariableCounter:");
		Counter counter = new VariableCounter();
		
		counter.count();
		if(counter.getValue() != 0){
			System.out.println("ForwardCounter: Step size not initialized as 0!");
			return false;
		}
		
		counter = new VariableCounter(2);
		
		counter.count();
		if(counter.getValue() != 2){
			System.out.println("ForwardCounter: Incorrect Counting!");
			return false;
		}
				
		return true;
	}
	
	
	public static void main(String[] args) {
		
		
		if(testBaseCounter())
			System.out.println("BaseCounter: PASSED");
		else
			System.out.println("BaseCounter: FAILED");
		
		if(testForwardCounter())
			System.out.println("ForwardCounter: PASSED");
		else
			System.out.println("ForwardCounter: FAILED");
		
		if(testVariableCounter())
			System.out.println("VariableCounter: PASSED");
		else
			System.out.println("VariableCounter: FAILED");
		
	
		return;
	}

}
