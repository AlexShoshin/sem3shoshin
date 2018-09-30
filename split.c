#include <stdio.h>
#include <malloc.h>
#include <string.h>

// FIXIT: магические константы 10, 15, 30, 100 нужно превратить в #define ПОНЯТНОЕ_НАЗВАНИЕ 10 и т.п.

char* GiveMemoryForString(int len)
{
	char* str = (char*)malloc(len * sizeof(char));
	return str;
}

char** GiveMemoryForArray(int count, int len)
{
	char** array = (char**)malloc(count * sizeof(char*));
	if(array == NULL)
	{
		printf("Error at allocation memory for array!\n");
		return 0;
	}
	else
	{
		int i;
		for(i = 0; i < count; i++)
		{
			array[i] = (char*)malloc(len * sizeof(char));
		}
		return array;
	}
}

void FreeArrayMemory(char** array, int count)
{
	int i;
	for(i = 0; i < count; i++)
	{
		free(array[i]);
	}
	free(array);
}

void Split(char* string, char* delimiter, char** words, int* count)
{
	int i = 0;
	char* tmp = GiveMemoryForString(30);
	tmp = strtok(string, delimiter);
	while(tmp != NULL)
	{
		strcpy(words[i], tmp);
		i++;
		tmp = strtok(NULL, delimiter);
	}
	// Лишние скобки: *count = i; достаточно
	*(count) = i;
	free(tmp);
	
}

int main()
{
	char* string = GiveMemoryForString(100);
	fgets(string, 100, stdin);
	char* delimiter = GiveMemoryForString(10);
	fgets(delimiter, 10, stdin);
	int init_count = 15;
	char**words = GiveMemoryForArray(init_count, 15);
	int count = 0;
	
	Split(string, delimiter, words, &count);
	int i;
	for(i = 0; i < count; i++)
	{
		printf("%s\n", words[i]);
	}
	free(string);
	free(delimiter);
	FreeArrayMemory(words, init_count);

	return 0;
}
