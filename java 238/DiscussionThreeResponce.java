
public class DiscussionThreeResponce
{
//	Start code by Brandy Poag
	private String name = "Brandy Dian Poag";
	public static int counter = 0;
	public String toString()
	{
		String string = name;
		return string;
	}
	DiscussionThreeResponce()
	{
		counter++;
	}
//	End of code by Brandy Poag
	public static void main(String[] args)
	{
		//Added by Michael Jenkins
		//Example call to method displaying odd numbers between 1 and 10
		//While passing in an int Array
		//Chapter 7 
		int[] myNum = {1,2,3,4,5,6,7,8,9,10};
		showOddNumbers(myNum);
		//End of code by Michael Jenkins
		
		//Added by Brandy Poag pg 316, 341
		//call the DiscussionThreeResponce constructor and 
		//use a static integer varriable to keep count
		//of how many DiscussionThreeResponce objects are made
		//show the toString method can be used
		DiscussionThreeResponce brandy = new DiscussionThreeResponce();
		System.out.println("There are " + counter + 
				" DiscussionThreeResponce objects!");
		DiscussionThreeResponce dian = new DiscussionThreeResponce();
		System.out.println("There are " + counter + 
				" DiscussionThreeResponce objects!");
		DiscussionThreeResponce poag = new DiscussionThreeResponce();
		System.out.println("There are " + counter + 
				" DiscussionThreeResponce objects!");
		System.out.println(brandy);
		System.out.println(dian);
		System.out.println(poag);
		//End of code by Brandy Poag
	}
	
	/**
	 * Added by Michael Jenkins
	 * This displays odd numbers between 1 and the passed in number
	 */
	public static void showOddNumbers(int[] myNum) 
	{
		//For loop that loops through myNum times
		//Pages 266-274
		for(int x = 0;x < myNum.length; x++) 
		{
			//if statement that checks the remainder
			//if the remainder is 1 then the number is odd
			//Pages multiple in Chapter 7
			if(myNum[x] % 2 == 1)
			{
				System.out.println(myNum[x]);
			}
		}
	}
}
