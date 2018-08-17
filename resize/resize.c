// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{

    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    int n = atoi(argv[1]);
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
    BITMAPFILEHEADER bf, bf_r;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_r = bf;
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_r;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_r = bi;
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    bi_r.biWidth  = bi.biWidth * n;
    bi_r.biHeight = bi.biHeight * n;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int res_padding = (4 - (bi_r.biWidth * sizeof(RGBTRIPLE)) %4) % 4;
    bi_r.biSizeImage = (bi_r.biWidth * sizeof(RGBTRIPLE) + res_padding) * abs(bi_r.biHeight);
    bf_r.bfSize = bf.bfSize - bi.biSizeImage + bi_r.biSizeImage;
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_r, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_r, sizeof(BITMAPINFOHEADER), 1, outptr);



    // determine padding for scanlines

    // iterate over infile's scanlines

    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for(int l = 0; l < n; l++){
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for(int g = 0; g < n; g++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
        for(int k = 0; k < res_padding; k++){
                fputc(0x00, outptr);
        }
        if (l < n- 1)
            fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            // then add it back (to demonstrate how)
        }
        fseek(inptr, padding, SEEK_CUR);
    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
