/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
	

int main(void) {
	int t;
	double ax, ay, az; 	
	
	while (TRUE) {
		int button1 = Esplora.readButton(switch_1)
		int button2 = Esplora.readButton(switch_2)
		int button3 = Esplora.readButton(switch_3)
		int button4 = Esplora.readButton(switch_4)
		if(button1 == LOW){
			int button1 = 1
		}
		else {
			int button1 = 0
		}
		if(button2 == LOW){
			int button2 = 1
		}
		else {
			int button2 = 0
		}
		if(button3 == LOW){
			int button3 = 1
		}
		else {
			int button3 = 0
		}
		if(button4 == LOW){
			int button4 = 1
		}
		else {
			int button4 = 0
		}
		t = button1 + button2 + button3 + button4
		printf("%d", t)
		fflush(stdout)
	}
return 0;
}