#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
char notepad_ram[100000];
void call_notepad () {
	printf ("Welcome to SaqNotepad standalone app from SaqShell V3!, type ::QUIT:: to exit to OS\n");
	char notepad_bufferin[8168];
	char savmenu_choice[100];
	char filename[1000];
	bool loop = true;
	while (loop) {
		printf ("> ");
		fgets (notepad_bufferin, sizeof(notepad_bufferin), stdin);
		if (strcmp(notepad_bufferin, "::QUIT::\n")== 0) {
			break;
		}
		strcat (notepad_ram, notepad_bufferin);
	}
	printf ("SAVE MENU\n\n");
	printf ("Do you wanna save your data y/n?> ");
	fgets (savmenu_choice, sizeof(savmenu_choice), stdin);
	if (strcmp(savmenu_choice, "y\n")== 0) {
		printf ("Type in filename with .exstention> ");
		fgets (filename, sizeof(filename), stdin);
		filename[strcspn(filename, "\n")] = 0;
		FILE *file_ptr = fopen (filename, "w");
		if (file_ptr != NULL) {
			fprintf (file_ptr, "%s", notepad_ram);
			fclose (file_ptr);
			printf ("File '%s' has been saved successfully in the same folder as where the SaqShell execuatble lives! :), Returning to Os...\n", filename);
		} else {
			printf ("OS didnt allow saving %s :( (makesure to run SaqNotepad as Admin in Windows.). ERRCODE: KERNEL_ILLEGAL_PERM_TO_FS, returning to os without saving...\n", filename);
		}
	}
	else if (strcmp(savmenu_choice, "n\n")== 0) {
		printf ("exitting to OS without saving...\n");
	} else {
		printf ("ERRCODE: ILLEGAL_INSTRUCTION_TO_SAQNOTEPAD, not saving and exitting to OS...\n");
	}
}
int main() {
	call_notepad ();
	return 0;
}
	/*Schon crazy wie ich das alles ohne dokumentation geschrieben habe :P*/
	
