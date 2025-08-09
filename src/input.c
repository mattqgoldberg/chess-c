#include "input.h"
#include <string.h>
#include <stdio.h>
#define INPUT_SIZE 8

Move getMove() {
	
	char buf[8];
	char c;

	char MIN_FILE = 'A';
	char MAX_FILE = 'H';
	char MIN_RANK = '1';
	char MAX_RANK = '8';

	while(1) {
		printf("Enter move:\n");
		
		if (!fgets(buf, INPUT_SIZE, stdin)) { // read line safely
            printf("Error reading input.\n");
            continue;
        }


		int len = strlen(buf);
		int invalidMove = 0;
		if (len < 5 || len > 6) {invalidMove = 1;}

		if (strchr(buf, '\n') == NULL) {
			while ((c = getchar()) != '\n' && c != EOF);
        }

		if (buf[0] < MIN_FILE || buf[0] > MAX_FILE) {invalidMove = 1;}
		if (buf[1] < MIN_RANK || buf[1] > MAX_RANK) {invalidMove = 1;}
		if (buf[2] < MIN_FILE || buf[2] > MAX_FILE) {invalidMove = 1;}
		if (buf[3] < MIN_RANK || buf[3] > MAX_RANK) {invalidMove = 1;}

		if (invalidMove) {
			printf("Invalid input\n");
			continue;
		}

		break;
	}

	Move move;

	move.start.col = (int) (buf[0] - MIN_FILE);
	move.start.row = (int) (buf[1] - MIN_RANK);
	move.end.col = (int) (buf[2] - MIN_FILE);
	move.end.row = (int) (buf[3] - MIN_RANK);

	return move;
}
