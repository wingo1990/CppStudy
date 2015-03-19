#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_INPUT 100
#define MAX_COLS 20

int read_clomns( int columns[], int max )
{
	int num = 0;
	int ch;


	while ( num < max && scanf("%d ",&columns[num]) == 1 
		&& columns[num] >= 0 )
		num++;

	if ( num % 2 != 0 )
	{
		puts("last columns is not paired");
		exit( EXIT_FAILURE );
	}
	else
	{
		for (int i = 0; i < num ; i+=2 )
		{
			if( columns[i+1] - columns[i] < 0 )
			{
				puts("wrong");
				exit( EXIT_FAILURE );
			}
		}
	}

	ch = getchar();

	//丢弃该行中包含最后一个数字的那部分内容
	while( (ch = getchar()) != EOF && ch != '\n');

	return num;
}

void rearrange( char *output, char const *input, int n_cloumns, int const columns[] )
{
	int len;
	int col = 0;
	int output_col = 0;

	len = strlen(input);

	for ( col = 0; col < n_cloumns; col += 2 )
	{
		int nchars = columns[col + 1] - columns[col] + 1;

		if (columns[col] > len || 
			output_col == MAX_INPUT - 1 )
			break;

		if( output_col + nchars > MAX_INPUT - 1 )
			nchars = MAX_INPUT - 1 - output_col;

		strncpy( output + output_col, input + columns[col], nchars );

		output_col += nchars;

	}

	output[output_col] = '\0';
}

int main()
{
	char input[MAX_INPUT];
	char output[MAX_INPUT];
	int columns[MAX_COLS];

	int n_cloumns;


	//读取字符串标号
	n_cloumns = read_clomns( columns, MAX_COLS);

	
	while( gets( input ) != NULL )
	{
		printf( "Original input : %s \n",input );
		rearrange( output, input, n_cloumns, columns );
		printf( "Rearrange line : %s \n",output );
	}

	return EXIT_SUCCESS;
}