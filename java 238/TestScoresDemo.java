
public class TestScoresDemo 
{
	public static void main(String[] args) 
	{
		try
		{
			int[] array = { 90, 80, 70, 90, 80, 70, 75};
			TestScores test = new TestScores(array);
			System.out.println("The average of the test " +
					"scores is " + test.average() );
			int[] array2 = { 50, 50, 50};
			TestScores test2 = new TestScores(array2);
			System.out.println("The average of the test " +
					"scores is " + test2.average() );
			/*int[] array3 = { 50, 50, 50, -1};
			TestScores test3 = new TestScores(array3);
			System.out.println("The average of the test " +
					"scores is " + test3.average() );*/
			int[] array4 = { 50, 50, 50, 106};
			TestScores test4 = new TestScores(array4);
			System.out.println("The average of the test " +
					"scores is " + test4.average() );
		}
		catch (IllegalArgumentException e)
		{
			System.out.println(e.getMessage());
		}

	}


}
