// The software class will compute the total cost
// of software packages sold depending on the number of 
// packages sold and the discount recieved 
public class SoftwareSales 
{
	// store the number of units sold in quantity
	private int quantity;
	
	// constructor the object specifies the quantity of packages
	SoftwareSales(int n)
	{
		quantity = n;
	}
	
	// method to set new quantity
	void setQuantity(int n)
	{
		quantity = n;
	}
	
	// method to return the quantity
	int getQuantity()
	{
		return quantity;
	}
	
	// calculate the total cost 
	double cost()
	{
		int pkgCost = 99;
		double discountRate = 0;
		double cost = 0;
		
		if (quantity < 10)
		{
			return pkgCost * quantity;
		}
		else if (quantity < 20)
		{
			discountRate = 0.2;
		}
		else if (quantity < 50)
		{
			discountRate = 0.3;
		}
		else if (quantity < 100)
		{
			discountRate = 0.4;
		}
		else
		{
			discountRate = 0.5;
		}
		
		cost = quantity * pkgCost - quantity 
		* pkgCost * discountRate;
		
		return cost;
	}
}
