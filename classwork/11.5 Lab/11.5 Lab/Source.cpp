#include <iostream>
#include <cstring>
using namespace std;

// Return a newly allocated copy of original
// with the first occurrence of each vowel capitalized
char* CapVowels(char* original) {
   /*
      A new string must be allocated because
      a statically declared array (char result[50]) cannot be returned.
   */

    int length = strlen(original) + 1;
    char* newString = new char[length];
    strcpy(newString, original);
    char Vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    for (int index = 0; index < length; ++index)
    {
        newString[index] = original[index];
    }


   /* Type your code here. */

    for (int index = 0; index < length; ++index)
    {
        for (int index2 = 0; index2 < length; ++index2)
        {
            if (Vowels[index2] == newString[index2])
            {
                newString[index2] = toupper(Vowels[index]);
                    break;
            }
        }
    }

    return newString;

}

int main() {

    char userCaption[50];
    char* resultStr;
    cin >> userCaption;

    resultStr = CapVowels(userCaption);

    printf("Original: %s\n", userCaption);
    printf("Modified: %s\n", resultStr);

    // Always free dynamically allocated memory when no longer needed
    delete(resultStr);

    return 0;
}
