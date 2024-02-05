#include <stdio.h>
#include <stdlib.h>

int cambiarDecimal(char hex);

unsigned char hexadecimalDecimal(const char *hexadecimal) {
    int k[2];
    unsigned char emaitza = 0;

    for (int i = 0; i < 2; i++) {
        k[i] = cambiarDecimal(hexadecimal[i]);
    }

    emaitza = k[0] * 16 + k[1];
    return emaitza;
}

char* decimalToBinary(unsigned char decimal) {
    char *binary = malloc(9); 

    for (int i = 7; i >= 0; i--) {
        binary[7 - i] = ((decimal >> i) & 1) + '0';
    }

    binary[8] = '\0';

    return binary;
}

int cambiarDecimal(char hex) {
    int dec;
    if (hex >= '0' && hex <= '9') {
        dec = hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        dec = hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        dec = hex - 'a' + 10;
    }
    return dec;
}

char* xorCadenas(const char *cadena1, const char *cadena2) {
    unsigned char dec1 = hexadecimalDecimal(cadena1);
    unsigned char dec2 = hexadecimalDecimal(cadena2);

    int longitud = 2; 
    unsigned char *resultado = malloc(longitud + 1);

    printf("Cadena 1 en decimal: %d\n", dec1);
    printf("Cadena 1 en binario: %s\n", decimalToBinary(dec1));

    printf("Cadena 2 en decimal: %d\n", dec2);
    printf("Cadena 2 en binario: %s\n", decimalToBinary(dec2));


    resultado[0] = dec1 ^ dec2;
    resultado[1] = '\0';

    printf("Resultado en decimal: %d\n", resultado[0]);
    printf("\n");

    char asciiChars[3];
    asciiChars[0] = resultado[0];
    asciiChars[1] = 'O';  
    asciiChars[2] = '\0';

    printf("ASCII values: %c%c\n", asciiChars[0], asciiChars[1]);

    char *resultString = malloc(5);  // Adjust the size based on your needs
    sprintf(resultString, "%c%s", asciiChars[0], asciiChars + 1);

    printf("Result as a string: %s\n", resultString);

    printf("\n");

    return resultado;
}


int main() {
    const char *hexValue = "65"; 
    const char *hexValue2 = "20";
    unsigned char *xorChar = xorCadenas(hexValue, hexValue2);
   int ascii = (int)xorChar[0];
    
    printf ("%c\t", xorChar[0]);


    free(xorChar);

    return 0;
}
