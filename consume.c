#include <stdio.h>
#include <stdlib.h>

void remove_word(char * text, char * word);

int main(int argc, char *argv[]) {
     char cmdbuf[80];
     char * text         = (char*)malloc(sizeof(char) * 100);
//     char * wordToRemove[80] = (char*)malloc(sizeof(char) * 800);
     char text[80];
     char wordToRemove[80];
     char wordToRemove2[80];
    // Word to remove
    strcpy(wordToRemove, "Bye");
    strcpy(wordToRemove2, "Bye");
     char i, j;
     char *url = "check-pos-get-banks"; 
     char *body = "{sn : 210210933}";
     snprintf (cmdbuf, sizeof(cmdbuf), "runme.exe %s %s >> tmp.txt", url, body);
     int retcod = system(cmdbuf);
     FILE *fp = fopen("tmp.txt", "wb+");
     fread(text, sizeof(char), 100, fp);
    printf ("Readed text: '%s'\n", text);

    // Call the function to remove the word
    remove_word(text, wordToRemove);
    remove_word(text, wordToRemove2);
    printf ("New text: '%s'\n", text);

    // Write the new text
    fprintf(fp, text);
    fclose(fp);
}

void remove_word(char * text, char * word)
{
    int sizeText = strlen(text);
    int sizeWord = strlen(word);
    
    // Pointer to beginning of the word
    char * ptr = strstr(text, word);
    if(ptr)
    {
        //The position of the original text
        int pos = (ptr - text);

        // Increment the pointer to go in the end of the word to remove
        ptr = ptr + sizeWord;                
        
        // Search in the phrase and copy char per char
        int i;
        for(i = 0; i < strlen(ptr); i++)
        {
            text[pos + i] = ptr[i]; 
        }
        // Set the "new end" of the text               
        text[pos + i] = 0x00;      
    }   
}