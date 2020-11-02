#include "libLab6.c"


/* プロトタイプ宣言 */
void countPixels(int width, int height, unsigned char** inputImage, int histCount[]);
void calcFrequency(int size, int level, int histCount[], double histFrequency[]);


/* main() 関数 */
int main(void)
{
	/* 変数宣言 */
	unsigned char** inputImage = NULL;		// 画素データ配列（原画像用）
	int width = 0;							// 画像の幅（列数）
	int height = 0;							// 画像の高さ（行数）

	int histCount[LEVEL] = { 0 };			// 画素値の発生数データ配列
	double histFrequency[LEVEL] = { 0.0 };	// 画素値の発生頻度データ配列

	/* 原画像の入力 */
	inputImage = readRaw(&width, &height);

	/* 画像処理をする関数を呼び出す */
	countPixels(width, height, inputImage, histCount);
	calcFrequency(width * height, LEVEL, histCount, histFrequency);

	/* 処理後画像の出力 */
	writeImageHistogram(LEVEL, histCount, histFrequency);

	/* メモリの開放 */
	free(inputImage);

	return 0;
}


/* 画素値の発生数をカウントする関数 */
void countPixels(int width, int height, unsigned char** inputImage, int histCount[])
{
	int row = 0, col = 0;	// ループカウンタ（row：行(row)方向，col：列(column)方向）

	printf("\n[ 画素値の発生数をカウント ]\n");

	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{
			histCount[inputImage[row][col]]++;
		}
	}
}


/* 画素値の発生頻度を算出する関数 */
void calcFrequency(int size, int level, int histCount[], double histFrequency[])
{
	int count = 0;		// ループカウンタ（階調レベル）

	printf("\n[ 画素値の発生頻度を算出 ]\n");

	for (count = 0; count < LEVEL; count++) 
	{
		histFrequency[count] = (double)histCount[count] / size;
	}
}