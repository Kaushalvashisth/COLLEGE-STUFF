#include <stdio.h>
#include <string.h>

char rem[100];
char fin[100];
void func(char[], char[], int);
void main()
{
  int t,n;
  char input1[100], input2[100], key1[100];
  printf("Enter Transmitted Data: ");
  gets(input1);

  t = 0;
  do {
    printf("Select the CRC type:  \n");
    printf("1. CRC-8 \t2. CRC-10 \t3. CRC-16 \t4. CRC-32 \t\n");
    printf("your choise: ");
    scanf("%d",&n);
    switch (n) {
      case 1 : strcpy(key1, "100000111");
      break;
      case 2 : strcpy(key1, "11000110101");
      break;
      case 3 : strcpy(key1, "10001000000100001");
      break;
      case 4 : strcpy(key1, "100000100110000010001110110110111");
      break;
      default : printf("INVALID SELECTION\n");
      t = 1;
      break;
    }
  } while(t);

  func(input1, key1, 0);
  printf("recived data is %s\n", fin);

  printf("enter recived data: ");
  scanf("%s\n",input2);

  func(input2, key1, 1);
  printf("reminder is %s", rem);

}

  void func(char input[], char key[], int a){
    int key_length, msg_length;
    char temp[100], quot[100], key1[100];

    key_length = strlen(key);
    msg_length = strlen(input);
    strcpy(key1, key);
    strcpy(fin, input);
    for (size_t i = 0; i < key_length-1; i++) {
      input[msg_length+i] = '0';
    }
    for (size_t i = 0; i < key_length; i++) {
      temp[i] = input[i];
    }
    for (size_t i = 0; i < msg_length; i++) {
      quot[i] = temp[0];
      if (quot[i] == '0') {
        for (size_t j = 0; j < key_length; j++) {
          key[j] = '0';
        }
      }
      else{
        for (size_t j = 0; j < key_length; j++) {
          key[j] = key1[j];
        }
      }
      for (size_t j = key_length-1; j > 0; j--) {
        if (temp[j] == key[j]) {
          rem[j-1] = '0';
        }
        else{
          rem[j-1] = '1';
        }
      }
      rem[key_length - 1] = input[i+key_length];
      strcpy(temp,rem);

    }
    strcpy(rem,temp);
    strcpy(fin,rem);

}