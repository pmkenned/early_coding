import javax.swing.*;
import java.awt.*;

class Fireworks
{
	int frameHeight = 500;
	int frameWidth = 500;

	public static void main(String args[])
	{
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().add(new Life());
		frame.setSize(frameWidth,frameHeight);
		frame.setVisible(true);
	}

	public void paint(Graphics g)
	{
		
	}
}
