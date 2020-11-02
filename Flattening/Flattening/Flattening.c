#include "libLab6.c"


/* プロトタイプ宣言 */
void flattening(int width, int height, unsigned char** inputImage, unsigned char** outputImage, unsigned char lookuptable[]);
void makeLookupTable(int size, int histCount[], unsigned char lookupTable[]);
void countPixels(int width, int height, unsigned char** inputImage, int histCount[]);


/* main() 関数 */
int main(void)
{
	/* 変数宣言 */
	unsigned char** inputImage = NULL;		// 画素データ配列（原画像用）
	unsigned char** outputImage = NULL;		// 画素データ配列（処理後画像用）
	int width = 0;							// 画像の幅（列数）
	int height = 0;							// 画像の高さ（行数）

	int histCount[LEVEL] = { 0 };				// 画素値発生数データ配列
	unsigned char lookupTable[LEVEL] = { 0 };	// ヒストグラム変換テーブル配列

	/* 原画像の入力 */
	inputImage = readRaw(&width, &height);

	/* 出力画像用配列を生成 */
	outputImage = makeRawArray(width, height);

	/* 画像処理をする関数を呼び出す */
	countPixels(width, height, inputImage, histCount);
	makeLookupTable(width * height, histCount, lookupTable);
	flattening(width, height, inputImage, outputImage, lookupTable);

	/* 処理後画像の出力 */
	writeRaw(width, height, outputImage);

	/* メモリの開放 */
	free(inputImage);
	free(outputImage);

	return 0;
}


/* ヒストグラムの平坦化 */
void flattening(int width, int height, unsigned char** inputImage, unsigned char** outputImage, unsigned char lookupTable[])
{
	int row = 0, col = 0;	// ループカウンタ（row：行(row)方向，col：列(column)方向）

	printf("\n[ ヒストグラムの平坦化 ]\n");

	for (row = 0; row < height; row++) 
	{
		for (col = 0; col < width; col++) 
		{
			outputImage[row][col] = lookupTable[inputImage[row][col]];
		}
	}
}


/* ヒストグラムの変換テーブルを作成 */
void makeLookupTable(int size, int histCount[], unsigned char lookupTable[])
{
	int count = 0;		// ループカウンタ（階調レベル）
	int target = 0;		// ループカウンタ（カウントする画素値）
	int sum = 0;		// 累積度数

	printf("\n[ ヒストグラムの変換テーブルを作成 ]\n");

	for (target = 0; target < 255; target++)
	{
		sum +=  histCount[target];
		lookupTable[target] = (double)(sum*(255/size));
		printf("%lf ",lookupTable[target]);
	}
}



/* テーマ3で作成したGenerateHistogram内にあるcountPixels()関数の内容をそのまま貼り付ける */

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