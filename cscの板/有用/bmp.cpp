#include <cstdlib>
#include <cstdio>
#include <string>
unsigned int OffSet = 0;
long width, height;
unsigned char r[10000][10000], g[10000][10000], b[10000][10000];
int gray[10000][10000];

void Change(FILE *file) {
	unsigned char *pix = NULL;
	FILE *txt;
	if ((txt = fopen("result.txt", "w+")) == NULL) {
		printf("Failed to construct file result.txt.");
		exit(1);
	}
	fseek(file, OffSet, SEEK_SET);
	int stride = ((24 * width + 31) / 8) / 4 * 4;
	pix = (unsigned char *)malloc(stride);
	for (int j = 0; j < height; ++j) {
		fread(pix, 1, stride, file);
		for (int i = 0; i < width; ++i) {
			r[height - 1 - j][i] = pix[i * 3 + 2];
			g[height - 1 - j][i] = pix[i * 3 + 1];
			b[height - 1 - j][i] = pix[i * 3];
		}
	}
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			gray[i / 16][j / 8] += (r[i][j] + g[i][j] + b[i][j]) / 3;
	std::string ch = "@WM#*B%8&ZQ0LXUYwmJkChoabdpqzcvunxrjft1?i!;:^`,  ";
	for (int i = 0; i < height/16; ++i) {
		for (int j = 0; j < width/8; ++j)
			fprintf(txt, "%c", ch[gray[i][j] * ch.length() / 16 / 8 / 256]);
		fprintf(txt, "\n");
	}
	fclose(txt);
}

void Check(FILE *file) {
	unsigned short bfType = 0;
	fseek(file, 0L, SEEK_SET);
	fread(&bfType, sizeof(char), 2, file);
	if (bfType != 19778) {
		printf("This file is not a bitmap.\n");
		exit(1);
	}
}

void HeaderWidthHeight(FILE *file) {
	fseek(file, 10L, SEEK_SET);
	fread(&OffSet, sizeof(char), 4, file);
	printf("The Header Part is of length %d.\n", OffSet);
	fseek(file, 18L, SEEK_SET);
	fread(&width, sizeof(char), 4, file);
	printf("The Width of the bmp file is %ld.\n", width);
	fseek(file, 22L, SEEK_SET);
	fread(&height, sizeof(char), 4, file);
	printf("The Height of the bmp file is %ld.\n", height);
}

int main(int argc, char *argv[]) {
	unsigned char *fp_temp;
	FILE *file;
	char name[100];
	printf("Input the name of the file (including the suffix \".bmp\") :\n");
	scanf("%s", name);
	file = fopen(name, "rb");
	if (file == NULL) {
		printf("Open bmp failed.\n");
		return 1;
	}
	Check(file);
	HeaderWidthHeight(file);
	fseek(file, 0L, SEEK_SET);
	fp_temp = (unsigned char *)malloc(OffSet);
	fread(fp_temp, 1, OffSet, file);
	Change(file);
	fclose(file);
	return 0;
}
