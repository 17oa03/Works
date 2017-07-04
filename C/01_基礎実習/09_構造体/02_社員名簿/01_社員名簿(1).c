/*
【プログラム概要】
社員名簿(5名分)の構造体配列を初期化し、
年齢の降順に出力する。
*/

/*【プログラム】*/
#include <stdio.h>

#define ELEMENT 5 /* 人数 */

/* 構造体の型枠の宣言 */
struct ymd {
	int y; /* 年 */
	int m; /* 月 */
	int d; /* 日 */
};

struct employee {
	int    no;           /* 社員番号 */
	char   name[11];     /* 氏名 */
	struct ymd entrance; /* 入社年月日 */
	struct ymd birth;    /* 生年月日 */
};

int main(void)
{
	/* 構造体変数の定義と初期化 */
	struct employee data[ELEMENT] = {
		{ 1212, "sato",      { 2002,  4,  1 },{ 1982,  6, 23 } }, /* 1人目 */
		{ 2353, "suzuki",    { 2001,  4,  1 },{ 1984,  9, 30 } }, /* 2人目 */
		{ 3147, "takahashi", { 2001, 10,  1 },{ 1986, 10, 11 } }, /* 3人目 */
		{ 5206, "tanaka",    { 1995,  4, 20 },{ 1986, 10, 10 } }, /* 4人目 */
		{ 6447, "watanabe",  { 1988,  3, 25 },{ 1985,  4, 20 } }, /* 5人目 */
	};

	struct employee temp;

	/* カウンタ変数 */
	int i, j;

	/* 年齢の降順にソートする */
	for (i = 0; i < ELEMENT - 1; i++) {
		for (j = i + 1; j < ELEMENT; j++) {

			if (data[i].birth.y  > data[j].birth.y  ||
			   (data[i].birth.y == data[j].birth.y  &&
			    data[i].birth.m  > data[j].birth.m) ||
			   (data[i].birth.y == data[j].birth.y  &&
			    data[i].birth.m == data[j].birth.m  &&
			    data[i].birth.d  > data[j].birth.d)) {

			    temp    = data[i];
			    data[i] = data[j];
			    data[j] = temp;
			}
		}
	}

	/* 出力 */
	printf("社員番号 氏    名   入社年月日  生年月日 \n");
	printf("-------- ---------- ---------- ----------\n");

	for (i = 0; i < ELEMENT; i++) {
		printf("%8d ", data[i].no);
		printf("%-11s", data[i].name);
		printf("%4d/%2d/%2d ", data[i].entrance.y, data[i].entrance.m, data[i].entrance.d );
		printf("%4d/%2d/%2d\n", data[i].birth.y, data[i].birth.m, data[i].birth.d );
	}

	return 0;
}

/*
【実行結果】
社員番号 氏    名   入社年月日  生年月日
-------- ---------- ---------- ----------
    1212 sato       2002/ 4/ 1 1982/ 6/23
    2353 suzuki     2001/ 4/ 1 1984/ 9/30
    6447 watanabe   1988/ 3/25 1985/ 4/20
    5206 tanaka     1995/ 4/20 1986/10/10
    3147 takahashi  2001/10/ 1 1986/10/11
*/

/*
【考察】
構造体配列の初期化は一括でできる、
構造体のネストには、
さらに{}を記述すれば初期化できる。

if分の内容が複雑になっている、
複雑な分岐は処理が遅くなるため、
なるべく演算処理で判定できるようにするべき。

出力に関して、
「-」を変換指定子の間に記述すると左寄せにできる。

printf関数の実引数と仮引数の数を合わせる、
3つの変換指定子に対して、
1つの構造体の指定で出力ができてしまうが、
コンパイル時に警告されてしまう、
引数の管理には注意するべき。
*/