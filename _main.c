#include "header.h"

int main() {
  int init = 0;

  char string[1000][100];

  do {
    scanf("%s", string[init]);
    init++;
  } while(string[init - 1][strlen(string[init - 1]) - 1] != '.');

  if(string[init - 1][strlen(string[init - 1]) - 1] == '.')
    string[init - 1][strlen(string[init - 1]) - 1] = '\0';

  int a[1000];
  int init2 = 0;

  for(int i = 0; i < init; i++) {
    a[i] = 0;
    for(int j = 0; j < strlen(string[i]); j++) 
      if(string[i][j] == 'a')
        a[i]++;

      if(a[i] > 0)
        init2++;
  }

//   for(int i = 0; i < init - 1; i++) {
//     int maxIndex = i;

//     for(int j = i + 1; j < init; j++)
//       if(a[j] > a[maxIndex])
//         maxIndex = j;

//     int temp = a[i];
//     a[i] = a[maxIndex];
//     a[maxIndex] = temp;

//     char tempName[100];
//     strcpy(tempName, string[i]);
//     strcpy(string[i], string[maxIndex]);
//     strcpy(string[maxIndex], tempName);
// }

for(int i = 1; i < init; i++) {
    int currentA = a[i];
    char currentName[100]; 
    strcpy(currentName, string[i]);

    int j = i - 1; // Inisialisasi nilai J

    // Pindahkan karakter ke posisi yang benar dalam array
    while(j >= 0 && (currentA > a[j])) {
      a[j + 1] = a[j];
      strcpy(string[j + 1], string[j]);
      j--;
    }

    // Tempatkan karakter pada posisi yang benar
    a[j + 1] = currentA;
    strcpy(string[j + 1], currentName);
  }

  for(int i = 0; i < init2; i++) {
    printf("%s", string[i]);
    if(i < init2 - 1)
      printf(" ");
  }

  printf("\n");
  
  return 0;
}