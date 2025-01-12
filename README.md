# cfile

This project is a simple utility that uses the `libmagic` library to determine the type of a given file. You can also provide your own custom signature file for more specific detection.

## Features

- Detects file types based on their content.
- Supports custom signature files for extended detection capabilities.

## Prerequisites

Make sure you have the `libmagic` library installed on your system.

### Installation Instructions

Debian/Ubuntu
```bash
sudo apt install libmagic-dev
```

CentOS/RHEL
```bash
sudo yum install libmagic-devel
```

Arch Linux
```bash
sudo pacman -S libmagic
```

### Build Instructions
Clone the repository or copy the source code.
Compile the code using GCC:
```bash
gcc -o cfile cfile.c -lmagic
```

### Usage
Run the program with the path to the file you want to analyze. Optionally, provide a custom magic file:
```bash
./cfile <file> [custom_magic_file]
```
Example (Standard Magic File)
```bash
./cfile someBinFile
```
Output:
```
File type: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=5508174f36ba19096e5eeee206d3f9e8a1b4926c, for GNU/Linux 3.2.0, not stripped
```

Example (Custom Magic File)
```bash
./cfile example.txt my_magic.mgc
```
Output:
```
File type: Custom format
```

### Creating a Custom Magic File
Create a plain text file with your custom signatures. For example:
```plaintext
0       string      CUSTOM_SIGNATURE   Custom format
```
- 0: Offset in bytes where the signature begins.
- string: Type of data to match.
- CUSTOM_SIGNATURE: Signature value to match.
- Custom format: Description displayed when a match is found.

### Error Handling
If the library is not properly installed or the magic database is unavailable, the program will print an error message and exit.
If the custom magic file has syntax errors or is missing, an appropriate error will be displayed.
