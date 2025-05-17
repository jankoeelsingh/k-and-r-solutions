#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void convert(int lower, int upper, int step);

int main() {
	convert(LOWER, UPPER, STEP);

	// while (fahr <= upper) {
	// 	celsius = 5.0 * (fahr - 32.0) / 9.0;
	// 	printf("|%6.0f C\t|%6.0f F\t|\n", fahr, celsius);
	// 	printf("-------------------------\n");
	// 	fahr = fahr + step;
	// }
}

void convert(int lower, int upper, int step) {
	int fahr;

	printf("=== Celsius to Fahrenheit converter ===\n\n");

	for (fahr = lower; fahr <= upper; fahr = fahr + step) {
		printf("-------------------------\n");
		printf("|%6d C\t|%7.1f F\t|\n", fahr, (5.0/9.0)*(fahr-32));
	}

	printf("-------------------------\n");
}
