#include "libLab6.c"


/* �v���g�^�C�v�錾 */
void countPixels(int width, int height, unsigned char** inputImage, int histCount[]);
void calcFrequency(int size, int level, int histCount[], double histFrequency[]);


/* main() �֐� */
int main(void)
{
	/* �ϐ��錾 */
	unsigned char** inputImage = NULL;		// ��f�f�[�^�z��i���摜�p�j
	int width = 0;							// �摜�̕��i�񐔁j
	int height = 0;							// �摜�̍����i�s���j

	int histCount[LEVEL] = { 0 };			// ��f�l�̔������f�[�^�z��
	double histFrequency[LEVEL] = { 0.0 };	// ��f�l�̔����p�x�f�[�^�z��

	/* ���摜�̓��� */
	inputImage = readRaw(&width, &height);

	/* �摜����������֐����Ăяo�� */
	countPixels(width, height, inputImage, histCount);
	calcFrequency(width * height, LEVEL, histCount, histFrequency);

	/* ������摜�̏o�� */
	writeImageHistogram(LEVEL, histCount, histFrequency);

	/* �������̊J�� */
	free(inputImage);

	return 0;
}


/* ��f�l�̔��������J�E���g����֐� */
void countPixels(int width, int height, unsigned char** inputImage, int histCount[])
{
	int row = 0, col = 0;	// ���[�v�J�E���^�irow�F�s(row)�����Ccol�F��(column)�����j

	printf("\n[ ��f�l�̔��������J�E���g ]\n");

	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{
			histCount[inputImage[row][col]]++;
		}
	}
}


/* ��f�l�̔����p�x���Z�o����֐� */
void calcFrequency(int size, int level, int histCount[], double histFrequency[])
{
	int count = 0;		// ���[�v�J�E���^�i�K�����x���j

	printf("\n[ ��f�l�̔����p�x���Z�o ]\n");

	for (count = 0; count < LEVEL; count++) 
	{
		histFrequency[count] = (double)histCount[count] / size;
	}
}