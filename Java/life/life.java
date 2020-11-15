import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Life extends JComponent implements MouseListener, MouseMotionListener, MouseWheelListener
{
	static int frameHeight = 1000;
	static int frameWidth = 1000;
	int cellSize = 10;
	Color gridColor = Color.gray;
	int mouseX, mouseY;
	int rows = frameHeight/cellSize;
	int cols = frameWidth/cellSize;
	int grid[][] = new int[rows][cols];

	final int DEAD_DEAD = 0;
	final int LIVE_LIVE = 1;
	final int DEAD_LIVE = 2;
	final int LIVE_DEAD = 3;

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
		if(init == false)
		{
			addMouseListener(this);
			addMouseMotionListener(this);
			addMouseWheelListener(this);
			if(JOptionPane.showInputDialog("Randomize?").toLowerCase().equals("yes"))
				randomize();
			init = true;
		}
		drawGrid(g);
	}

	public void randomize()
	{
		for(int i=0; i<rows; i++)
			for(int j=0; j<cols; j++)
				grid[i][j] = (int)(Math.random()*2);
	}

	public void live()
	{
		int liveNeighbors;
		for(int row=0; row<rows; row++)
		{
			for(int col=0; col<cols; col++)
			{
				liveNeighbors = countNeighbors(row,col);
				if(grid[row][col] == LIVE_LIVE || grid[row][col] == LIVE_DEAD)
					if(liveNeighbors < 2 || liveNeighbors > 3)
						grid[row][col] = LIVE_DEAD;
				if(grid[row][col] == DEAD_DEAD || grid[row][col] == DEAD_LIVE)
					if(liveNeighbors == 3)
						grid[row][col] = DEAD_LIVE;
			}
		}

		for(int row=0; row<rows; row++)
		{
			for(int col=0; col<cols; col++)
			{
				if(grid[row][col] == LIVE_DEAD)
					grid[row][col] = DEAD_DEAD;
				if(grid[row][col] == DEAD_LIVE)
					grid[row][col] = LIVE_LIVE;
			}
		}
		repaint();
	}

	public int countNeighbors(int row, int col)
	{
		int liveNeighbors = 0;
		int r,c;
		for(int i=-1; i<=1; i++)
		{
			for(int j=-1; j<=1; j++)
			{
				r = row+i; c = col+j;
				if( r<0 || r>=rows || c<0 || c>=cols || (i==0 && j==0) )
					continue;
				if(grid[r][c] == LIVE_LIVE || grid[r][c] == LIVE_DEAD)
					liveNeighbors++;
			}
		}
		return liveNeighbors;
	}

	public void drawGrid(Graphics g)
	{
		g.setColor(gridColor);
		for(int i=0; i<frameHeight/cellSize; i++)			// draw grid lines
			g.drawLine(0,i*cellSize,frameWidth,i*cellSize);
		for(int i=0; i<frameWidth/cellSize; i++)
			g.drawLine(i*cellSize,0,i*cellSize,frameHeight);

		for(int row=0; row<rows; row++)					// fill in live cells
			for(int col=0; col<cols; col++)
				if(grid[row][col] == LIVE_LIVE)
					g.fillOval(cellSize*row,cellSize*col,cellSize,cellSize);
	}

	public void mouseClicked(MouseEvent event)
	{
		int col = mouseX/cellSize;
		int row = mouseY/cellSize;
		if(row<rows && col<cols)
			grid[col][row] = LIVE_LIVE;
		event.consume();
		repaint();
	}

	public void mouseMoved(MouseEvent event)	// if the mouse was moved,
	{
		mouseX = event.getX();		// update the x-coordinate
		mouseY = event.getY();		// update the y-cooridnate
		event.consume();
	}

	public void mouseEntered(MouseEvent event) {}
	public void mouseExited(MouseEvent event) {}
	public void mousePressed(MouseEvent event) {}
	public void mouseReleased(MouseEvent event) {}
	public void mouseDragged(MouseEvent event)
	{ mouseClicked(event); event.consume(); }

	public void mouseWheelMoved(MouseWheelEvent event)
	{
		int notches = event.getWheelRotation();
		if(notches != 0)
			live();
		event.consume();
	}

	boolean init = false;
}
