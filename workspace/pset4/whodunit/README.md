# Questions

## What's `stdint.h`?

Standard header for predefined data sizes which makes code easier and portable.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To get a fixed sized data. It will then be constant for any machine which runs C.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII - BM, decimal - 16973, hexadecimal - 424d

## What's the difference between `bfSize` and `biSize`?

bfSize = file size; biSize = Structure size; `bfSize = biSize + bfSizeImage`

## What does it mean if `biHeight` is negative?

It means that it is top-down structure where origin is top-left.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCounter

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If there is no such file location i.e. file address = NULL

## Why is the third argument to `fread` always `1` in our code?

The third argument in fread specifies to read first n elements of an array.
So 1 tells fread to read 1 element of inputstream at a time.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

Skips over padding

## What is `SEEK_CUR`?

Current position of file pointer
