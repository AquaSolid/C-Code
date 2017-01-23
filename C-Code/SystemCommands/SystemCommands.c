#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[]) {
	int adjust = 7;
	printf("Enter a number(1-15): ");
	scanf("%d", &adjust);
	char str[100];
	sprintf(str, "sudo tee /sys/class/backlight/acpi_video0/brightness <<< %d", 
adjust);
	puts(str);
	system(str);
	return EXIT_SUCCESS;
}
