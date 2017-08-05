/*
【プログラム概要】
テキストファイルのバイト数と行数を出力する。

※改行コードは2バイトとする。
*/

/*【プログラム】*/
#include <stdio.h>

int main(void)
{
	int c = 0; /* getchar関数の戻り値を格納する変数 */

	int i = 0; /* バイト数のカウンタ変数 */
	int	j = 0; /* 行数のカウンタ変数 */

	while ((c = getchar()) != EOF) /* 1文字ずつデータを取り込む */
	{

		i++; /* バイト数のカウント */

		if (c == '\n') { i++; j++; } /* 取り込んだ文字が改行コードだった場合 */
	}

	printf("バイト数 : %d\n", i); /* バイト数の出力 */
	printf("行　　数 : %d\n", j); /* 行数の出力 */

	return 0;
}

/*
【実行結果】
バイト数 : 52
行　　数 : 4
*/

/*
【考察】
getchar関数は、
標準入力から1文字分文字をunsigned char型として読み取り、
int型に変換(ASCIIコード)して戻り値になる、
読み取り失敗時は「EOF」を返す。
*/