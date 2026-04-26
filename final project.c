#include <stdio.h>
#include <string.h>

void caesarEncrypt(char text[], int shift) 
{
    for (int i = 0; text[i] != '\0'; i++) 
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A'; //Encryption formula for Capital Letters 
        }

        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a'; //Encryption formula for Lowercase Letters 
        }
    }
}

void caesarDecrypt(char text[], int shift) 
{
    for (int i = 0; text[i] != '\0'; i++) 
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A'; //Decryption formula for Capital Letters 
        }

        else if (text[i] >= 'a' && text[i] <= 'z')
        {
             text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a'; //Decryption formula for Lowercase Letters
        }
    }
}

void printPreview(char text[]) 
{
    for (int i = 0; i < 20 && text[i] != '\0'; i++)
    {
        if ((text[i] >= 32 && text[i] <= 126))  // printable ASCII
            printf("%c", text[i]);
        else
            printf(".");  
    }
    printf("...\n");
}

int main() 
{
    int choice, flag = 0;

    while (flag == 0) 
    {
        printf("\nChoose:\n");
        printf("1. Encryption\n");
        printf("2. Decryption\n");
        printf("3. Exit\n");
        printf(">> ");
        scanf("%d", &choice);
        getchar();  

        printf("\n");

        if (choice == 1) 
        {
            char text[200];
            int shift;

            printf("Enter text: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0'; //Replace \n with \0

            printf("Enter shift: ");
            scanf("%d", &shift);

            shift = shift % 26;
            caesarEncrypt(text, shift);

            printf("Encrypted: %s\n", text);
        }

        else if (choice == 2) 
        {
            char text[200];
            int subchoice;

            printf("Enter encrypted text: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0'; //Replace \n with \0

            printf("\nChoose method:\n");
            printf("1. Known Shift\n");
            printf("2. Brute Force\n");
            printf(">> ");
            scanf("%d", &subchoice);

            if (subchoice == 1) 
            {
                int shift;
                printf("Enter shift: ");
                scanf("%d", &shift);

                shift = shift % 26;
                caesarDecrypt(text, shift);

                printf("Decrypted: %s\n", text);
            }

            else if (subchoice == 2) 
            {
                char results[26][200];
                strcpy(results[0], text);
                printf("\n Original:");
                printPreview(results[0]);
                printf("\nDecrypted text Preview\nChoose the correct one:\n");

                for (int s = 1; s < 26; s++) 
                {
                    strcpy(results[s], text);
                    caesarDecrypt(results[s], s);

                    printf("%d. ", s);
                    printPreview(results[s]);
                }

                int pick;
                printf(">> ");
                scanf("%d", &pick);

                if (pick >= 1 && pick <= 25) 
                {
                    printf("Full Decrypted Message: %s\n", results[pick]);
                } 
                else 
                {
                    printf("Invalid choice.\n");
                }
            }
        }

        else if (choice == 3) 
        {
            flag = 1;  //To end the while loop
        }

        else 
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}