#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void func(int width, int height, unsigned char* data);
int main()
{

	int width, height, channels, r, g, b;
	unsigned char* data = stbi_load("AmongUsIcon.bmp", &width, &height, &channels, 0);
	
	if (data == NULL)
	{
		printf("Error in loading the image\n");
		exit(1);
	}
	func(width, height, data);
	stbi_write_bmp("AmongUsIcon(1).bmp", width, height, channels, data);

	stbi_image_free(data);
}

void func(int width, int height, unsigned char* data)
{
	for (int i = 0; i < width * height * 4; i += 4)
	{
		int r = data[i + 0];
		int g = data[i + 1];
		int b = data[i + 2];

		//printf("%i", r);
		int grey = (max(r, g, b) + min(r, g, b)) / 2;
		data[i + 0] = grey;
		data[i + 1] = grey;
		data[i + 2] = grey;
		//printf("%i", grey);
	}
	
}
