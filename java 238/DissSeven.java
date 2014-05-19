import javax.swing.*;
import java.awt.event.*;

public class DissSeven extends JFrame
{
	private JButton button;
	private JButton button5;
	private JButton button6;
	private JPanel panel;

	/**
	 * Added by Brandy Poag
	 * from the book on page 703
	 */
	
	public DissSeven()
	{
		super("You are feeling?");
		setSize(300, 200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		button = new JButton("happy");
		button.addActionListener(new ButtonListener());
		button5 = new JButton("sad");
		button5.addActionListener(new ButtonListener());
		button6 = new JButton("mad");
		button6.addActionListener(new ButtonListener());
		panel = new JPanel();
		panel.add(button);
		panel.add(button5);
		panel.add(button6);
		add(panel);
		setVisible(true);
	}
	
	private class ButtonListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			JOptionPane.showMessageDialog(null, "Why so "
					+ e.getActionCommand() + " today?");
		}
	}
	
	public static void main(String[] args) 
	{
		//Brandy Poag's code
		DissSeven hi = new DissSeven();

		//Added by Michael Jenkins
		getAverage();
	}

	/**
	 * Added by Michael Jenkins
	 * from the book on page 684
	 * This is just a starting point.
	 */
	public static void getAverage()
	{
		int score1, score2, score3; // Three test scores
		String strInput; // String input
		double average; // Average test score
		int repeat; // Confirm dialog button clicked

		do {
			// Get the first test score.
			strInput = JOptionPane.showInputDialog(null, "Enter score #1.");
			score1 = Integer.parseInt(strInput);

			// Get the second test score.
			strInput = JOptionPane.showInputDialog(null, "Enter score #2.");
			score2 = Integer.parseInt(strInput);

			// Get the third test score.
			strInput = JOptionPane.showInputDialog(null, "Enter score #3.");
			score3 = Integer.parseInt(strInput);

			// Calculate and display the average test score.
			average = (score1 + score2 + score3) / 3.0;
			JOptionPane.showMessageDialog(null, "The average is " + average);

			// Does the user want to average another set?
			repeat = JOptionPane.showConfirmDialog(null,"Would you like to average another set of test scores?", "Please Confirm.",JOptionPane.YES_NO_OPTION);

		}
		while (repeat == JOptionPane.YES_OPTION);

		System.exit(0);
	}
}
