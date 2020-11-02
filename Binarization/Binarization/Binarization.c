#include "libLab6.c"


/* プロトタイプ宣言 */
void binarization(int width, int height, unsigned char** inputImage, unsigned char** outputImage);


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
	binarization(width, height, inputImage, outputImage);

	/* 処理後画像の出力 */
	writeRaw(width, height, outputImage);

	/* メモリの開放 */
	free(inputImage);
	free(outputImage);

	return 0;
}


/* 画像を指定された閾値で2値化する関数 */
void binarization(int width, int height, unsigned char** inputImage, unsigned char** outputImage)
{
	int threshold = 0;		// しきい値
	int row = 0, col = 0;	// ループカウンタ（row：行(row)方向，col：列(column)方向）

	/* しきい値を入力 */
	printf("\n[ しきい値を入力 ]\n");
	printf("しきい値（この値以上を%dにする） : ", F_MAX);
	scanf_s("%d", &threshold);

	printf("\n[ 画像の2値化 ]\n");

	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{
			if (inputImage[row][col] >= threshold) {
				outputImage[row][col] = 255;
			}
			else {
				outputImage[row][col] = 0;
			}
		}
	}
}