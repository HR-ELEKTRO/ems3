#include <string.h>
#include <stdio.h>

int main(void) {
	char naam[10];
	naam = "Harry"; // Fout! Zie opmerking 1.
	strcpy(naam, "Harry"); // OK
	printf("%s\n", naam);
	strcpy(naam, "Willem-Alexander"); // Fout! Zie opmerking 2.
	strcpy(naam, "Alex"); // OK
	printf("%s\n", naam);
	if (naam == "Alex") { // Fout! Zie opmerking 3.
		// ...
	}
	if (strcmp(naam, "Alex") == 0) { // OK
		// ...
	}
}
