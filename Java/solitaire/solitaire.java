import javax.swing.*;
import java.awt.*;

class Solitaire extends JComponent
{
	static int frameHeight = 500;
	static int frameWidth = 600;
	int deckSize = 52;
	int deck[] = new int[deckSize];
	int cardHeight = 100;
	int cardWidth = 75;
	int cardBorder = 2;
	Color faceUpColor = Color.white;
	Color faceDownColor = Color.yellow;
	int space=4;
	int stack = 0;
	int stacks[] = new int[7];

	int HEARTS = 0;
	int DIAMONDS = 1;
	int CLUBS = 2;
	int SPADES = 3;
	int JACK = 11;
	int QUEEN = 12;
	int KING = 13;
	int NONE = 0;

	public static void main(String args[])
	{
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().add(new Solitaire());
		frame.setSize(frameWidth,frameHeight);
		frame.setVisible(true);
	}

	public void paint(Graphics g)
	{
		deck = shuffle();

		for(int i=0; i<7; i++)	// draw first row
		{
			if(i==1 || i==2)
				continue;
			drawCard(g,0,i,true,NONE);
		}

		for(int i=0; i<7; i++)	// draw 2nd row
		{
			for(int j=0; j<=i; j++)
			{
				if(j==i)
					drawCard(g,1,i,true,NONE);
				else
					drawCard(g,1,i,false,NONE);
			}
		}
	}

	public void drawCard(Graphics g, int row, int col, boolean faceUp, int cardNumber)
	{
		int x = (cardWidth+space)*col;
		int y = (cardHeight+space)*row;

		if(row==0 && col==1)	// stack
			x += stack*space;

		if(row==1)		// 2nd row
		{
			y += stacks[col]*space;
			stacks[col]++;
		}

		if(faceUp)
		{
			g.setColor(faceUpColor);
			if(cardNumber == NONE)
				g.setColor(Color.gray);
		}
		else
			g.setColor(faceDownColor);
		g.fillRect(x,y,cardWidth,cardHeight);
		g.setColor(Color.black);
		g.drawRect(x,y,cardWidth,cardHeight);

		if(faceUp && (cardNumber >= 1 && cardNumber <= 13*5))
		{
			// code for writing number on card
		}
	}

	public int[] shuffle()
	{
		int list1[] = new int[deckSize];
		int list2[] = new int[deckSize];

		for(int i=0; i<deckSize; i++)
			list1[i] = i;

		for(int i=0; i<deckSize; i++)
		{
			int r = (int)(Math.random()*(deckSize-i));
			list2[i] = list1[r];
			list1[r] = list1[deckSize-1-i];
		}

		return list2;
	}
}
