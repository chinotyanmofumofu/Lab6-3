#include "libLab6.c"


/* �v���g�^�C�v�錾 */
void linearConversion(int width, int height, unsigned char** inputImage, unsigned char** outputImage);


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
	linearConversion(width, height, inputImage, outputImage);

	/* ������摜�̏o�� */
	writeRaw(width, height, outputImage);

	/* �������̊J�� */
	free(inputImage);
	free(outputImage);

	return 0;
}


/* �܂���^�g�[���J�[�u�ɂ��R���g���X�g�ϊ����s���֐� */
void linearConversion(int width, int height, unsigned char** inputImage, unsigned char** outputImage)
{
	int inMin = 0, inMax = 0;		// ���͌��z�����͈̔́i�ŏ��l�C�ő�l�j
	int outMin = 0, outMax = 0;		// �o�͌��z�����͈̔́i�ŏ��l�C�ő�l�j
	int row = 0, col = 0;			// ���[�v�J�E���^�irow�F�s(row)�����Ccol�F��(column)�����j

	/* ���z�����͈̔͂�ݒ肷�� */
	printf("\n[ ���z�����͈̔͂���́i�󔒂ŋ�؂�j ]\n");
	printf("���́i�ŏ��l�C�ő�l�j: ");
	scanf_s("%d%d", &inMin, &inMax);
	printf("�o�́i�ŏ��l�C�ő�l�j: ");
	scanf_s("%d%d", &outMin, &outMax);

	printf("\n[ �q�X�g�O�����ϊ� ]\n");

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