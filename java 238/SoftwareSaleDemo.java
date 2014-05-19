/**
 * The SoftwareSaleDemo class is used to show how the 
 * SoftwareSales class is used
 */
import java.text.DecimalFormat;
import java.util.Scanner;

public class SoftwareSaleDemo 
{
	public static void main(String[] args) 
	{
		Scanner keyboard = new Scanner(System.in);
		// create a decimal format object
		DecimalFormat formatter = new DecimalFormat("$#,##0.00");
		
		// create 3 order objects using the constructor to 
		// specify the quantity of the packages purchased
		// use the cost method of SoftwareSales class to calculate
		// the total cost then display the cost in decimal format
		SoftwareSales order1 = new SoftwareSales(1);
		System.out.println(formatter.format(order1.cost()));
		
		SoftwareSales order2 = new SoftwareSales(2);
		System.out.println(formatter.format(order2.cost()));
		
		SoftwareSales order3 = new SoftwareSales(10);
		System.out.println(formatter.format(order3.cost()));
		
		// use the setQuantity method of SoftwareSales class to
		// specify a new quantity of packages purchased for order1
		// use the cost method of SoftwareSales class to calculate
		// the total cost then display the cost in decimal format
		order1.setQuantity(100);
		System.out.println(formatter.format(order1.cost()));

		// allow the user to specify the number of packages
		// purchased then
		// use the setQuantity method of SoftwareSales class to
		// specify a new quantity of packages purchased for order1
		// use the cost method of SoftwareSales class to calculate
		// the total cost then display the cost in decimal format
		System.out.println("How many packages " +
				"are being purchased? ");
		int amount = keyboard.nextInt();
		order1.setQuantity(amount);
		System.out.println("The total cost of " + amount +
				" packages is ");
		System.out.println(formatter.format(order1.cost()));
	}
}
