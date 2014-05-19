
public class ResponseDiscussionFour 
{

	/**
	 * Added by Brandy Poag
	 * This takes a first, middle, and last names and creates
	 * one fullname string using the StringBuilder class pg.515
	 */
	public static StringBuilder fullname(String first, String middle, String last)
	{
		StringBuilder string = new StringBuilder(first);
		string.append(" ");
		string.append(middle);
		string.append(" ");
		string.append(last);
		return string;
	}
	
	public static void main(String[] args) 
	{
		//Added by Michael Jenkins
		//Example call to a static method converting text to upper/lower case
		conversionTest("Michael Jenkins Teaches CISS238!");
		//End of code by Michael Jenkins
		
		// Added by Brandy Poag
		// call the fullname method with 3 name strings to create one 
		// string combining the three
		StringBuilder name = fullname("brandy", "dian", "poag");
		System.out.println(name);
		// End of code by Brandy Poag
	}
	
	/**
	 * Added by Michael Jenkins
	 * This displays message in upper/lower case
	 */
	public static void conversionTest(String value) 
	{
		//converts value to upper/lower case
		//page 497
		System.out.println("Original: " + value);
		System.out.println("UPPER: " + value.toUpperCase());
		System.out.println("lower: " + value.toLowerCase());
	}
	
}
