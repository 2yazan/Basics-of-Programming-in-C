#include <stdio.h>
#include <string.h>

// Remove the digit 1 from the representation of the given octal number.


void calc(char* sv) {
	char bval[25] = "\0"; 
	char* len = strtok(sv, "1");
	while (len != NULL) {
		strcat(bval, len);
		len = strtok(NULL, "1");
	}
	printf("%s", bval);
}

int dectordx(char* buf, int len, int n, int radix){
	if (n >= radix)
		len = dectordx(buf, len, n / radix, radix);
	buf[len++] = '0' + n % radix;
	if (len < 32)buf[len] = '\0';
	return len;
}

int main() {
    printf("Enter a decimal number: \n");
    int value;
    scanf("%d", &value);
    char buf[32] = { 0 };
    dectordx(buf, 0, value, 2);
    printf("The entered number %d in binary is: %s\n", value, buf);
    dectordx(buf, 0, value, 8);
    printf("The entered number %d in octal is: %s\n", value, buf);
    printf("Removing 1 from the representation of this octal number: ");
    calc(buf);
    return 0;
}

