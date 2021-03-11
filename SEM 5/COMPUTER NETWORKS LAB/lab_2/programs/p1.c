#include <stdio.h>
#include <string.h>
void getCrc(char *input,char *key,char sr);
void main() {
    int dataSize,gSize,ch;
    char data[100],generator[100],data1[100];

    printf("Enter binary bits:- ");
    gets(data);

    printf("Select the GP \n1)CRC-8 \n 2)CRC-10 \n 3)CRC-16 \n 4)CRC-32 \n");
    printf("Enter Choice:- ");
    scanf(" %d",&ch);
    switch (ch)
    {
    case 1:
        strcpy(generator,"101011000");
        gSize=9;
        /* code */
        break;
    case 2:
        strcpy(generator,"10110101001");
        gSize=11;
        break;
    case 3:
        strcpy(generator,"10010110101001101");
        gSize=17;
        break;
    case 4:
        strcpy(generator,"100101101010011011001011010100110");
        gSize=33;
        break;
    default:
        printf("Enter Valid Input");
        break;
    }
    printf("\n The GP is %s ",generator);
    printf("\n The size of the GP is %d \n",gSize);
    
    // sender side
    getCrc(data,generator,'s');

    //reciever side
    printf("\n Enter Recieved Data:-");
    char data2[100];
    scanf(" %s",data2);

    getCrc(data2,generator,'r');

    // return 0;
}

void getCrc(char *input,char *key,char sr){
    int i, j, keylen, msglen;
    char temp[30], quot[100], rem[30], key1[30];
    keylen = strlen(key);
    msglen = strlen(input);
    strcpy(key1, key);
    // division
    for (i = 0; i < keylen - 1; i++)
    {
        input[msglen + i] = '0';
    }
    for (i = 0; i < keylen; i++)
        temp[i] = input[i];
    for (i = 0; i < msglen; i++)
    {
        quot[i] = temp[0];
        if (quot[i] == '0')
            for (j = 0; j < keylen; j++)
                key[j] = '0';
        else
            for (j = 0; j < keylen; j++)
                key[j] = key1[j];
        for (j = keylen - 1; j > 0; j--)
        {
            if (temp[j] == key[j])
                rem[j - 1] = '0';
            else
                rem[j - 1] = '1';
        }
        rem[keylen - 1] = input[i + keylen];
        strcpy(temp, rem);
    }
    strcpy(rem, temp);
    printf("\n Remainder is ");
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);

    // check if reciver or sender
    // if sender then print the data 
    // if reciever than check if remainder is 0 or not
    if (sr=='s')
    {
        printf("\n Transmitted data is: ");
        for (i = 0; i < msglen; i++)
            printf("%c", input[i]);
        for (i = 0; i < keylen - 1; i++)
            printf("%c", rem[i]);
    }
    if (sr=='r')
    {
        for (i = 0; i < keylen - 1; i++){
            if(rem[i]!='0'){
                break;
            }
        }
        (i==(keylen-1))
        ?printf("\n Since Remainder is 0\n Recieved data is  correct")
        :printf("\n Since Remainder is not 0\n Recieved data is not correct ");
    }
}