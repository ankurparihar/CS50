// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize factor infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    char *fact = argv[1];
    int n = 0;
    int len = strlen(fact);
    for (int i = 0; i < len; i++)
    {
        char ch = fact[i];
        if (ch < '0' || ch > '9')
        {
            fprintf(stderr, "Not valid n. reason i=%d char=%c\n", i, ch);
            return 1;
        }
        n = n * 10 + (ch - '0');
    }
    if (n == 0)
    {
        fprintf(stderr, "Not valid n.\n");
        return 1;
    }
    printf("n = %d\n", n);

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf2;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf2 = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi2;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi2 = bi;
    printf("bf.bfSize = %d\n", bf.bfSize);
    // printf("bi.biSize = %d\n", bi.biSize);
    printf("bi.biWidth = %d\n", bi.biWidth);
    printf("bi.biHeight = %d\n", bi.biHeight);
    // printf("bi.biPlanes = %d\n", bi.biPlanes);
    // printf("bi.biBitCount = %d\n", bi.biBitCount);
    // printf("bi.biCompression = %d\n", bi.biCompression);
    printf("bi.biSizeImage = %d\n", bi.biSizeImage);
    // printf("bi.biXPelsPerMeter = %d\n", bi.biXPelsPerMeter);
    // printf("bi.biYPelsPerMeter = %d\n", bi.biYPelsPerMeter);
    // printf("bi.biSize = %d\n", bi.biSize);
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    // changes in header file
    bi2.biWidth *= n;
    bi2.biHeight *= n;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding2 = (4 - (bi2.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi2.biSizeImage = (bi2.biWidth * sizeof(RGBTRIPLE) + padding2) * abs(bi2.biHeight);
    bf2.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi2.biSizeImage;
    printf("bf2.bfSize = %d\n", bf2.bfSize);
    printf("bi2.biWidth = %d\n", bi2.biWidth);
    printf("bi2.biHeight = %d\n", bi2.biHeight);
    printf("bi2.biSizeImage = %d\n", bi2.biSizeImage);
    // printf("%d\n", bf2.bfSize);
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf2, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi2, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    printf("padding = %d\n", padding);
    printf("padding2 = %d\n", padding2);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        // temporary storage
        RGBTRIPLE triple[bi2.biWidth];
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE temp;

            fread(&temp, sizeof(RGBTRIPLE), 1, inptr);
            // read RGB triple from infile
            for (int k = 0; k < n; k++)
            {
                triple[j * n + k] = temp;
            }
            // read RGB triple line from inptr
        }
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < bi2.biWidth; j++)
            {
                // write RGB triple to outfile
                fwrite(&triple[j], sizeof(RGBTRIPLE), 1, outptr);
                printf("%d%d%d ", triple[j].rgbtRed, triple[j].rgbtGreen, triple[j].rgbtBlue);
            }
            printf("\n");
            // then add it back (to demonstrate how)
            for (int p = 0; p < padding2; p++)
            {
                fputc(0x00, outptr);
            }
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfilemake
    fclose(outptr);

    // success
    return 0;
}
