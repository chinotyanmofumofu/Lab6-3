#include "libLab6.c"


/* �v���g�^�C�v�錾 */
void flattening(int width, int height, unsigned char** inputImage, unsigned char** outputImage, unsigned char lookuptable[]);
void makeLookupTable(int size, int histCount[], unsigned char lookupTable[]);
void countPixels(int width, int height, unsigned char** inputImage, int histCount[]);


/* main() �֐� */
int main(void)
{
	/* �ϐ��錾 */
	unsigned char** inputImage = NULL;		// ��f�f�[�^�z��i���摜�p�j
	unsigned char** outputImage = NULL;		// ��f�f�[�^�z��i������摜�p�j
	int width = 0;							// �摜�̕��i�񐔁j
	int height = 0;							// �摜�̍����i�s���j

	int histCount[LEVEL] = { 0 };				// ��f�l�������f�[�^�z��
	unsigned char lookupTable[LEVEL] = { 0 };	// �q�X�g�O�����ϊ��e�[�u���z��

	/* ���摜�̓��� */
	inputImage = readRaw(&width, &height);

	/* �o�͉摜�p�z��𐶐� */
	outputImage = makeRawArray(width, height);

	/* �摜����������֐����Ăяo�� */
	countPixels(width, height, inputImage, histCount);
	makeLookupTable(width * height, histCount, lookupTable);
	flattening(width, height, inputImage, outputImage, lookupTable);

	/* ������摜�̏o�� */
	writeRaw(width, height, outputImage);

	/* �������̊J�� */
	free(inputImage);
	free(outputImage);

	return 0;
}


/* �q�X�g�O�����̕��R�� */
void flattening(int width, int height, unsigned char** inputImage, unsigned char** outputImage, unsigned char lookupTable[])
{
	int row = 0, col = 0;	// ���[�v�J�E���^�irow�F�s(row)�����Ccol�F��(column)�����j

	printf("\n[ �q�X�g�O�����̕��R�� ]\n");

	for (row = 0; row < height; row++) 
	{
		for (col = 0; col < width; col++) 
		{
			outputImage[row][col] = lookupTable[inputImage[row][col]];
		}
	}
}


/* �q�X�g�O�����̕ϊ��e�[�u�����쐬 */
void makeLookupTable(int size, int histCount[], unsigned char lookupTable[])
{
	int count = 0;		// ���[�v�J�E���^�i�K�����x���j
	int target = 0;		// ���[�v�J�E���^�i�J�E���g�����f�l�j
	int sum = 0;		// �ݐϓx��

	printf("\n[ �q�X�g�O�����̕ϊ��e�[�u�����쐬 ]\n");

	for (target = 0; target < 255; target++)
	{
		sum +=  histCount[target];
		lookupTable[target] = (double)(sum*(255/size));
		printf("%lf ",lookupTable[target]);
	}
}



/* �e�[�}3�ō쐬����GenerateHistogram���ɂ���countPixels()�֐��̓��e�����̂܂ܓ\��t���� */

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