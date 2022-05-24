#pragma once
#include <glad/glad.h> 
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <wingdi.h>

GLuint loadbitmap(const char* filename, unsigned char*& pixelBuffer, BITMAPINFOHEADER* infoHeader, BITMAPFILEHEADER* fileHeader)
{
	FILE* bitmapFile;

	errno_t err = fopen_s(&bitmapFile, filename, "rb");
	if (err != 0 || bitmapFile == NULL)
	{
		printf("loadbitmap - open failed for %s\n", filename);
		return NULL;
	}

	fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, bitmapFile);

	if (fileHeader->bfType != 0x4D42)
	{
		printf("loadbitmap - type failed \n");
		return NULL;
	}

	fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, bitmapFile);

	if (infoHeader->biBitCount < 24)
	{
		printf("loadbitmap - bitcount failed = %d\n", infoHeader->biBitCount);
		return NULL;
	}

	fseek(bitmapFile, fileHeader->bfOffBits, SEEK_SET);

	int nBytes = infoHeader->biWidth * infoHeader->biHeight * 3;
	pixelBuffer = new unsigned char[nBytes];
	fread(pixelBuffer, sizeof(unsigned char), nBytes, bitmapFile);

	fclose(bitmapFile);

	for (int i = 0; i < nBytes; i += 3)
	{
		unsigned char tmp = pixelBuffer[i];
		pixelBuffer[i] = pixelBuffer[i + 2];
		pixelBuffer[i + 2] = tmp;
	}

	printf("loadbitmap - loaded %s w=%d h=%d bits=%d\n", filename, infoHeader->biWidth, infoHeader->biHeight, infoHeader->biBitCount);
}

GLuint setup_texture(const char* filename)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	GLuint texObject;
	glGenTextures(1, &texObject);
	glBindTexture(GL_TEXTURE_2D, texObject);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	unsigned char* pxls = NULL;
	BITMAPINFOHEADER info;
	BITMAPFILEHEADER file;
	loadbitmap(filename, pxls, &info, &file);

	if (pxls != NULL)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, info.biWidth, info.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pxls);
	}

	delete[] pxls;

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	return texObject;
}

GLuint setup_mipmaps(const char* filename[], int n)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	GLuint texObject;
	glGenTextures(1, &texObject);
	glBindTexture(GL_TEXTURE_2D, texObject);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	unsigned char* pxls[16];
	BITMAPINFOHEADER info[16];
	BITMAPFILEHEADER file[16];
	for (int c = 0;c < n;c++)
	{
		loadbitmap(filename[c], pxls[c], &info[c], &file[c]);
		if (pxls != NULL)
		{
			glTexImage2D(GL_TEXTURE_2D, c, GL_RGB, info[c].biWidth, info[c].biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pxls[c]);
		}
		delete[] pxls[c];
	}


	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	return texObject;
}
