/**
 * demostate how Month class compares months objects 
 */
public class MonthDemo 
{
	public static void main(String[] args)
	{
		// create three month object and compare them
		Month month1 = new Month();
		Month month2 = new Month(1);
		Month month3 = new Month(7);
		
		System.out.println(month1.getMonthName());
		System.out.println(month2.getMonthName());
		System.out.println(month3.getMonthName());
		
		System.out.println(month1.greaterThan(month2));
		System.out.println(month2.greaterThan(month3));
		System.out.println(month1.greaterThan(month3));
		
		System.out.println(month1.equals(month2));
		System.out.println(month2.equals(month3));
		System.out.println(month1.equals(month3));
		
		System.out.println(month1.lessThan(month2));
		System.out.println(month2.lessThan(month3));
		System.out.println(month1.lessThan(month3));
		
		month1.setMonthNumber(6);
		month2.setMonthNumber(7);
		month3.setMonthNumber(8);
		
		System.out.println(month1.getMonthName());
		System.out.println(month2.getMonthName());
		System.out.println(month3.getMonthName());
		
		System.out.println(month1.greaterThan(month2));
		System.out.println(month2.greaterThan(month3));
		System.out.println(month1.greaterThan(month3));
		
		System.out.println(month1.equals(month2));
		System.out.println(month2.equals(month3));
		System.out.println(month1.equals(month3));
		
		System.out.println(month1.lessThan(month2));
		System.out.println(month2.lessThan(month3));
		System.out.println(month1.lessThan(month3));
		
	}

}
