/**
 *	Brandy Poag
 *	MPG class compute miles driven divided by gallons
 *	of gas used.
 */

import java.util.Scanner;  // needed for use of scanner

public class MilesPerGallon 
{
	public static void main(String[] args) 
	{
		double mpg = 0, milesDriven = 0, gasUsed = 0;
	
		// create scanner obj to read input
		Scanner keyboard = new Scanner(System.in);
		
		// get miles driven
		System.out.println("Compute how many miles " +
				"per gallon a car gets. Enter miles driven.");
		milesDriven = keyboard.nextDouble();
		
		// get gallons of gas used
		System.out.println("Enter amount of gallons of gas used.");
		gasUsed = keyboard.nextDouble();
		
		// compute MPG
		mpg = milesDriven / gasUsed;
		
		// display MPG
		System.out.println("The miles per gallon is " + mpg + '.');
	}

}
