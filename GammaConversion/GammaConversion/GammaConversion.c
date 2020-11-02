#include "libLab6.c"


/* プロトタイプ宣言 */
void gammaConversion(int width, int height, unsigned char** inputImage, unsigned char** outputImage);


/* main() 関数 */
int main(void)
{
	/* 変数宣言 */
	unsigned char** inputImage = NULL;		// 画素データ配列（原画像用）
	unsigned char** outputImage = NULL;		// 画素データ配列（処理後画像用）
	int width = 0;							// 画像の幅（列数）
	int height = 0;							// 画像の高さ（行数）

	/* 原画像の入力 */
	inputImage = readRaw(&width, &height);

	/* 出力画像用配列を生成 */
	outputImage = makeRawArray(width, height);

	/* 画像処理をする関数を呼び出す */
	gammaConversion(width, height, inputImage, outputImage);

	/* 処理後画像の出力 */
	writeRaw(width, height, outputImage);

	/* メモリの開放 */
	free(inputImage);
	free(outputImage);

	return 0;
}


/* ガンマ変換を行う関数 */
void gammaConversion(int width, int height, unsigned char** inputImage, unsigned char** outputImage)
{
	double gamma = 0.0;		// ガンマ値
	int row = 0, col = 0;	// ループカウンタ（row：行(row)方向，col：列(column)方向）

	/* ガンマ値を設定する */
	printf("\n[ ガンマ値を入力（実数） ]\n");
	printf("ガンマ値（> 0.0）: ");
	scanf_s("%lf", &gamma);

	printf("\n[ ガンマ変換 ]\n");

	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{
			outputImage[row][col] =255 * (double)pow((double)(inputImage[row][col])/255,(double)1/gamma);
		}
	}
}

