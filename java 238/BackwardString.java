/**
 * Brandy Poag
 * This class has one method that accepts a String 
 * object and displays the 
 * strings contents backward
 */

import java.util.Scanner; // need for Scanner

public class BackwardString
{
	/**
	 * backward method accepts a String 
	 * object and displays the 
	 * strings contents backward
	 */
	public void backward(String str)
	{
		for (int i = str.length() - 1; i >= 0; i--)
		{
			System.out.print(str.charAt(i));
		}
	}
	
	public static void main(String[] args) 
	{
		// create a backward string object
		BackwardString theString = new BackwardString();
		// create a string object
		String string;
		// create Scanner object
		Scanner keyboard = new Scanner(System.in);
		
		// ask the user to enter a string then pass the 
		// string into the backward method
		System.out.println("Enter a string!");
		string = keyboard.nextLine();
		theString.backward(string);
	}

}
