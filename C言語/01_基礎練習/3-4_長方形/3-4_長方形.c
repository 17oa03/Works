/*
【プログラム概要】
長方形の縦と横の長さを入力し、
「*」を使って長方形を出力する。
*/

/*
【プログラム】
*/
#include <stdio.h>

int main(void)
{
	int i, j;
	int input1, input2;

	printf("たて ==> ");
	scanf("%d", &input1);

	printf("よこ ==> ");
	scanf("%d", &input2);

	for (i = 0; i < input1; i++){
		for (j = 0; j < input2; j++){

			printf("*");
		}

		printf("\n");
	}

	return 0;
}

/*
【実行結果1】
たて ==> 1
よこ ==> 1
*

【実行結果2】
たて ==> 1
よこ ==> 5
*****

【実行結果3】
たて ==> 5
よこ ==> 1
*
*
*
*
*

【実行結果4】
たて ==> 3
よこ ==> 7
*******
*******
*******
*/