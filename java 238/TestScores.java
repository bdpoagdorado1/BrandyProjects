
public class TestScores 
{
	public int[] array;
	public TestScores( int[] arr)
	{
		int[] x = new int[arr.length];
		for (int i = 0; i < arr.length; ++i)
		{
			if( arr[i] < 0 || arr[i] > 100 ) throw new IllegalArgumentException("Not valid score!");
			x[i] = arr[i];
			array = x;
		}
	}
	public double average()
	{
		double sum = 0;
		for (int i = 0; i < array.length; ++i)
		{
			sum += array[i];
		}
		return sum / array.length;
		
	}

	/**
	 * @param args
	 */
	
}
