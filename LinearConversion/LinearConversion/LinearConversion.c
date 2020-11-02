#include "libLab6.c"


/* プロトタイプ宣言 */
void linearConversion(int width, int height, unsigned char** inputImage, unsigned char** outputImage);


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
	linearConversion(width, height, inputImage, outputImage);

	/* 処理後画像の出力 */
	writeRaw(width, height, outputImage);

	/* メモリの開放 */
	free(inputImage);
	free(outputImage);

	return 0;
}


/* 折れ線型トーンカーブによるコントラスト変換を行う関数 */
void linearConversion(int width, int height, unsigned char** inputImage, unsigned char** outputImage)
{
	int inMin = 0, inMax = 0;		// 入力勾配部分の範囲（最小値，最大値）
	int outMin = 0, outMax = 0;		// 出力勾配部分の範囲（最小値，最大値）
	int row = 0, col = 0;			// ループカウンタ（row：行(row)方向，col：列(column)方向）

	/* 勾配部分の範囲を設定する */
	printf("\n[ 勾配部分の範囲を入力（空白で区切る） ]\n");
	printf("入力（最小値，最大値）: ");
	scanf_s("%d%d", &inMin, &inMax);
	printf("出力（最小値，最大値）: ");
	scanf_s("%d%d", &outMin, &outMax);

	printf("\n[ ヒストグラム変換 ]\n");

	for (row = 0; row < height; row++) 
	{
		for (col = 0; col < width; col++)
		{
			if (inputImage[row][col] < inMin)
			{
				outputImage[row][col] = outMin;
			}
			else if (inMax < inputImage[row][col])
			{
				outputImage[row][col] = outMax;
			}
			else
			{
				outputImage[row][col] = ((outMax - outMin) / (inMax - inMin)) * (inputImage[row][col] - inMin) + outMin;
			}
		}
	}
}