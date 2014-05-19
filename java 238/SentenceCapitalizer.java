
public class SentenceCapitalizer
{
	public String capitalize(String str)
	{
		StringBuilder string = new StringBuilder(str);
		boolean toCapital = true; //determine next char to be capitalized
		for (int i = 0; i < string.length(); i++)
		{
			if (str.charAt(i) == 46) toCapital = true;
			if (toCapital && string.charAt(i) >= 97 && string.charAt(i) <= 122)
			{
				char c = (char) (string.charAt(i) - ' ');
				string.setCharAt(i, c);
				toCapital = false;
			}
		}
		String newstring = string.toString();
		return newstring;
	}
}
