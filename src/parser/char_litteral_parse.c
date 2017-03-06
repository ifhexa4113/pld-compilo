#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int string_char_hex_to_int (char * str)
{
	int length = strlen(str);
	int size = length - 4 + 1;
	char * buffer = malloc(size);
	_memccpy(buffer, &str[3],'\0',size - 1);
	buffer[size - 1] = '\0';
	
	int value = strtol(buffer, NULL, 16);
	
	free(buffer);
	
	return value;
}

char string_char_oct_to_int (char * str)
{
		int length = strlen(str);
	int size = length - 4 + 1;
	char * buffer = malloc(size);
	_memccpy(buffer, &str[3],'\0',size - 1);
	buffer[size - 1] = '\0';
	
	int value = strtol(buffer, NULL, 8);
	
	free(buffer);
	
	return value;
}