import javax.swing.*;
import java.awt.*;

class Loading extends JComponent
{
	static int frameHeight = 100;
	static int frameWidth = 100;
	static int barHeight = 10;

	public static void main(String args[])
	{
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().add(new Loading());
		frame.setSize(frameWidth,frameHeight);
		frame.setVisible(true);
	}

	public void paint(Graphics g)
	{
		g.fillRect(0,0,5,5);
	}
}
