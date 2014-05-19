// the SentenceCapitalizerDemo demonstrates the SentenceCapitalizer
// class by sending a string object that needs to be capitalized 
// into the capitalize method and returns a string that is capitalized

import java.util.Scanner; // need for Scanner

public class SentenceCapitalizerDemo
{
	public static void main(String[] args) 
	{
		// create a backward string object
		SentenceCapitalizer theString = new SentenceCapitalizer();
		// create a StringBuilder object
		String string;
		// create Scanner object
		Scanner keyboard = new Scanner(System.in);
		
		// ask the user to enter a string then pass the 
		// string into the backward method
		System.out.println("Enter sentences to be capitalized.");
		string = keyboard.nextLine();
		String  newString = theString.capitalize(string);
		System.out.println(newString);
	}
}