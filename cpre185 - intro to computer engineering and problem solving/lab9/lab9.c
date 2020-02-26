// Headers
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>

// Mathematical constants
#define PI 3.14159

/* Screen geometry
Use NUMROWS and NUMCOLS for the screen height and width (set by system)*/
#define NUMROWS 80
#define NUMCOLS 100

/* Character definitions */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*Number of samples taken to form an average for the accelerometer data
Feel free to tweak this.  You may actually want to use the moving averages
code you created last week along with this number as your windowing size
to get a playable game*/
#define NUM_SAMPLES 10  


/* 2D character array which the maze is mapped into
 You should fill this with characters, not numbers. */
char MAZE[NUMROWS][NUMCOLS];


/* PRE: The level of difficulty will be entered on the command line. 
You will have to use the argument to the command line to determine how 
difficult the maze is (how many maze characters are on the screen).
POST: Generates a random maze structure into MAZE[][]
You will want to use the rand() function and maybe use the output %100. */
void generate_maze(int difficulty);

/* PRE: MAZE[][] has been initialized by generate_maze()
POST: Draws the maze to the screen.  You must use the draw_character
function to print to the screen.  You cannot use printf in curses.  */
void draw_maze(void);

/* PRE: 0 < x < NUMCOLS, 0 < y < NUMROWS, characters are defined above
POST: Draws character use to the screen and position y,x as in a graph
where x is the horizontal axis and y is the vertical axis.  
When using the i and j from the maze, you will want to remember that 
i (outer loop) is the rows and corresponds to y, while j is the columns 
and corresponds to x.  */
void draw_character(int x, int y, char use);

/* PRE: -1.0 < x_mag < 1.0
POST: Returns tilt magnitude scaled to -1.0 -> 1.0
You may want to reuse the roll function written in previous labs. */ 
double calc_roll(double x_mag);

// Main - Run with './explore.exe -t -a -b' piped into STDIN
void main(int argc, char* argv[])
{
	// setup screen    
	initscr();
	refresh();

	// Generate and draw the maze, with initial avatar

	// Read accelerometer data to get ready for using moving averages.    

	// Event loop
	do
	{

		// Read data, update average
		
		// Is it time to move?  if so, then move avatar
		
	} while(1); // Change this to end game at right time 

	// Print the win message
	endwin();
	
	printf("YOU WIN!\n");
}



/* PRE: 0 < x < NUMCOLS, 0 < y < NUMROWS, characters are defined above
POST: Draws character use to the screen and position y,x as in a graph
where x is the horizontal axis and y is the vertical axis.  
When using the i and j to draw the maze, you will want to remember that 
i (outer loop) is the rows and corresponds to y, while j (the inner loop) is the columns 
and corresponds to x. 

This code places the Avatar and the maze on the screen.  

IT WORKS CORRECTLY AS PROVIDED.  
PLEASE DO NOT CHANGE THIS FUNCTION. */

void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}


