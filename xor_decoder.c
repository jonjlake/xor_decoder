/**
 * Decode IBM WebSphere XOR encoding ( {xor} labeled pws)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * XOR truth table:
 *  
 * A | B | XOR
 * -----------
 * 0   0   0
 * 0   1   1
 * 1   0   1
 * 1   1   0
 * 
 * XOR(A,B) = C is reversible by A = XOR(B,C)
 * For key B: 0s preserve input bits, 1s flip input bits
 * So during XOR, key bit 1 tells you to flip the bit, 0 tells you to keep it
 */

char* xor(char key, char *input, int input_len)
{
	int i;
	char *output = calloc(1, input_len);

	for (i = 0; i < input_len; i++)
	{
		output[i] = input[i] ^ key;
	}
	
	return output;
}

char* reverse_xor(char key, char *input, int input_len)
{
	return xor(key, input, input_len);
}

int main(int argc, char * argv[]) 
{
	char *output = NULL;
	char key = 0x5f;

	if (argc < 2)
	{
		printf("No input specified. Exiting\n");
		return 0;
	}

	printf("Decoding %s\n", argv[1]);
	printf("Length of argv[1]: %d\n", strlen(argv[1]));

	output = reverse_xor(key, argv[1], strlen(argv[1]));

	printf("Decoded to %s\n", output);

	free(output);	

	return 0;
}
