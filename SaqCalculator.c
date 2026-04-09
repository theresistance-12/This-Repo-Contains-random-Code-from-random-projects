#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void call_calc () {
	printf ("Welcome to SaqCalcualtor! Usage: num1 operator num2 \n, type 'exit' to quit");
	char calc_ram [512];
	double num1;
	double num2;
	char op;
	while (1) {
		printf ("Calc>>> ");
		fgets (calc_ram, sizeof(calc_ram), stdin);
		if (strcmp(calc_ram, "exit\n")== 0) {
			printf ("Exitting...\n");
			break;
		}
		int items_found = sscanf (calc_ram, "%lf, %c, %lf", &num1, &op, &num2);
		if (items_found == 3) {
			if (op == '+') {
				printf ("Result: %g\n", num1 + num2);
			}
			else if (op == '-') {
				printf ("Result: %g\n", num1 - num2);
			}
			else if (op == '*') {
				printf ("Result: %g\n", num1 * num2);
			}
			else if (op == '/') {
				if (num2 != 0) {
					printf ("Result: %g\n", num1 / num2);
				} else {
					printf ("Divide by 0 ERROR!\n");
				}
			}
		} else {
			printf ("Wrong Instruction to Calc\n");
		}
	}
}
int main () {
	call_calc ();
	return 0;
}
			
		
