#include "dos.h"
#include "conio.h"
#include "stdio.h"

int x1 = 15, y1 = 10, x2 = 65, y2 = 20;
int x = 1, y = 1;
int key;

void draw(int x, int y) { // replace gotoxy() and putch()
	gotoxy(x, y);
	putch('*');
}


int get() { // replace getch()
	union REGS r;
	r.h.ah = 0x07;
	int86(0x21, &r, &r);
	return r.h.al;
}

int main() {
	window(x1, y1, x2, y2);
	textbackground(GREEN);
	textcolor(YELLOW);
	clrscr();
	do {
		clrscr();
		draw(x, y);
		key = get();
		switch (key) {
			case 72: // up
				if ((y - 1) > 0) {
					--y;
				}
				break;
			case 80: // down
				if ((y + 1) <= (y2 - y1 + 1)) {
					++y;
				}
				break;
			case 75: // left
				if ((x - 1) > 0) {
					--x;
				}
				break;
			case 77: // right
				if ((x + 1) <= (x2 - x1)) {
					++x;
				}
				break;
		}
	} 
	while (key != 27); // while pressed key != ESC
	return 0;
}