#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char expressions[256];

	printf("Input Expression: ");
	fgets(expressions, sizeof(expressions), stdin);

	char buffer[255];
	char lastOperator = '+';
	int startPoint = 0, endPoint;
	int operatorFound = 0;
	float result = 0;
	float num1, num2;

	for (int i = 0;; i++) {
		char currentChar = expressions[i];
		if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
			for (int j = 0; j < strlen(buffer); j++) buffer[j] = 0;
			strncpy(buffer, &expressions[startPoint], i - startPoint);
			startPoint = i + 1;
			result = atof(buffer);
			break;
		}
	}

	for (int i = 0;; i++) {
		char currentChar = expressions[i];
		//puts(&currentChar);

		if (currentChar == '\n') {
			break;
		}

		switch (currentChar) {
			case '+':
				for (endPoint = startPoint + 1; endPoint < strlen(expressions); endPoint++) {
					char temp = expressions[endPoint];
					if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '\n') {
						endPoint--;
						break;
					}
				}

				for (int j = 0; j < strlen(buffer); j++) buffer[j] = 0;
				strncpy(buffer, &expressions[i + 1], endPoint);
				num1 = atof(buffer);
				result = result + num1;

				break;
			case '-':
				for (endPoint = startPoint + 1; endPoint < strlen(expressions); endPoint++) {
					char temp = expressions[endPoint];
					if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '\n') {
						endPoint--;
						break;
					}
				}

				for (int j = 0; j < strlen(buffer); j++) buffer[j] = 0;
				strncpy(buffer, &expressions[i + 1], endPoint);
				num1 = atof(buffer);
				result = result - num1;

				break;
			case '*':
				for (endPoint = startPoint + 1; endPoint < strlen(expressions); endPoint++) {
					char temp = expressions[endPoint];
					if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '\n') {
						endPoint--;
						break;
					}
				}

				for (int j = 0; j < strlen(buffer); j++) buffer[j] = 0;
				strncpy(buffer, &expressions[i + 1], endPoint);
				num1 = atof(buffer);
				result = result * num1;

				break;
			case '/':
				for (endPoint = startPoint + 1; endPoint < strlen(expressions); endPoint++) {
					char temp = expressions[endPoint];
					if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '\n') {
						endPoint--;
						break;
					}
				}

				for (int j = 0; j < strlen(buffer); j++) buffer[j] = 0;
				strncpy(buffer, &expressions[i + 1], endPoint);
				num1 = atof(buffer);
				result = result / num1;

				break;
			default:
				break;
		}
	}
	printf("\n%.3f\n", result);
	return 0;
}
