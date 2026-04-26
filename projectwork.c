#include <stdio.h>

int main() {
    char text[200];
    int shift;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter shift: ");
    scanf("%d", &shift);
    printf("\n");

    shift = shift % 26;

    for (int i = 0; text[i] != '\0'; i++) 
    {
        if (text[i] >= 'A' && text[i] <= 'Z') 
        {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') 
        {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
    }

    printf("Encrypted text: %s", text);

    return 0;
}