#include "libLab6.c"


/* �v���g�^�C�v�錾 */
void binarization(int width, int height, unsigned char** inputImage, unsigned char** outputImage);


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
	binarization(width, height, inputImage, outputImage);

	/* ������摜�̏o�� */
	writeRaw(width, height, outputImage);

	/* �������̊J�� */
	free(inputImage);
	free(outputImage);

	return 0;
}


/* �摜���w�肳�ꂽ臒l��2�l������֐� */
void binarization(int width, int height, unsigned char** inputImage, unsigned char** outputImage)
{
	int threshold = 0;		// �������l
	int row = 0, col = 0;	// ���[�v�J�E���^�irow�F�s(row)�����Ccol�F��(column)�����j

	/* �������l����� */
	printf("\n[ �������l����� ]\n");
	printf("�������l�i���̒l�ȏ��%d�ɂ���j : ", F_MAX);
	scanf_s("%d", &threshold);

	printf("\n[ �摜��2�l�� ]\n");

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