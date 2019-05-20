package testesDeAprendizado;

import java.util.ArrayList;
import java.util.Collections;

public class Main {
	
	public static void main(String[] args) {
		   ArrayList<Double> nums = new ArrayList<Double>();
		   nums.add(5.0);
		   nums.add(7.0);
		   nums.add(7.0);
		   nums.add(4.0);		   
		   System.out.println(Collections.frequency(nums, 0));
	}
}
