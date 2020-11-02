#include "libLab6.c"


/* �v���g�^�C�v�錾 */
void gammaConversion(int width, int height, unsigned char** inputImage, unsigned char** outputImage);


/* main() �֐� */
int main(void)
{
	/* �ϐ��錾 */
	unsigned char** inputImage = NULL;		// ��f�f�[�^�z��i���摜�p�j
	unsigned char** outputImage = NULL;		// ��f�f�[�^�z��i������摜�p�j
	int width = 0;							// �摜�̕��i�񐔁j
	int height = 0;							// �摜�̍����i�s���j

	/* ���摜�̓��� */
	inputImage = readRaw(&width, &height);

	/* �o�͉摜�p�z��𐶐� */
	outputImage = makeRawArray(width, height);

	/* �摜����������֐����Ăяo�� */
	gammaConversion(width, height, inputImage, outputImage);

	/* ������摜�̏o�� */
	writeRaw(width, height, outputImage);

	/* �������̊J�� */
	free(inputImage);
	free(outputImage);

	return 0;
}


/* �K���}�ϊ����s���֐� */
void gammaConversion(int width, int height, unsigned char** inputImage, unsigned char** outputImage)
{
	double gamma = 0.0;		// �K���}�l
	int row = 0, col = 0;	// ���[�v�J�E���^�irow�F�s(row)�����Ccol�F��(column)�����j

	/* �K���}�l��ݒ肷�� */
	printf("\n[ �K���}�l����́i�����j ]\n");
	printf("�K���}�l�i> 0.0�j: ");
	scanf_s("%lf", &gamma);

	printf("\n[ �K���}�ϊ� ]\n");

	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{
			outputImage[row][col] =255 * (double)pow((double)(inputImage[row][col])/255,(double)1/gamma);
		}
	}
}

