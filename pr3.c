#include <stdio.h> 
#include <math.h> 
#include <string.h> 
#include <stdlib.h> 
#include <math.h>

  // Raymond Valdez
  // this code was tested using the cssgate server


//Prints the output string after multiplication has been executed.
//pre: 'atoz' implemented, String 'User1' assigned, String 'User2' assigned, int array 'arr' assigned, int array 'arr2' assigned, int array 'arr3' assigned.
//post: dynamic array 'arr2' created.
void multiplication(char * , char * , char * , int * , char * , int * );
//Prints the output string after addition has been executed.
//pre: 'atoz' implemented, String 'User1' assigned, String 'User2' assigned, int array 'arr' assigned, int array 'arr2' assigned, int array 'arr3' assigned.
//post: dynamic array 'arr2' created.
void addition(char * , char * , char * , int * , char * , int * );
//Prints the output string after subtraction has been executed.
//pre: 'atoz' implemented, String 'User1' assigned, String 'User2' assigned, int array 'arr' assigned, int array 'arr2' assigned, int array 'arr3' assigned.
//post: dynamic array 'arr2' created.
void subtraction(char * , char * , char * , int * , char * , int * );
int main(int argc, char * argv[]) {

 //The code will only run if the user initially passes 3 inputs into ./a.out.
 //otherwise the code will echo 'invalid number of operands'.
  if (argc == 4) {

    int length1;
    int length2;
    int i;
    int j;
    int input1 = 0;
    int count1 = 0;
    int input2 = 0;
    int count2 = 0;
    int onOff = 0;
    //'atoz' is a helper array of valid letters to be used in this program.
    //initial occurance of the letters in an equation will be stored in 'arr'.
    //we will dynamically allocate memory to 'arr2' once appropriate.
    //the final occurance of letters in the simplified string(after arithmetic has been executed) will be stored in 'arr3'.
    //user input will be stored as arrays for ease of use.
    char atoz[52] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };	
    int arr[52] = {0}; 
    char * arr2;
    int arr3[52] = {0}; 
    
    
    char * User1 = argv[1];
    char * User2 = argv[3];
    char * Op = argv[2];

    length1 = strlen(User1);
    length2 = strlen(User2);

// this piece of code tests if the first string inputted is valid by running the string through the 'atoz' array above. If any letter in the string is not a lowercase a-z, or an uppercase A-Z, it is an invalid input. 
    for (i = 0; i < length1; i++) {
      for (j = 0; j < 52; j++) {
        if (User1[i] == atoz[j]) {
          count1++;
        }
      }
    }
    if (count1 == length1) {
      input1++;
    }

    // this piece of code tests if the second string inputted is valid by running the string through the 'atoz' array above. If any letter in the string is not a lowercase a-z, or an uppercase A-Z, it is an invalid input.
    for (i = 0; i < length2; i++) {
      for (j = 0; j < 52; j++) {
        if (User2[i] == atoz[j]) {
          count2++;
        }
      }
    }
    if (count2 == length2) {
      input2++;
    }

    // this code tests the operators.
    //if the operator '+' is entered and both strings that the user has inpputed are valid, the addition method will run.
    //if the operator 'x' is entered and both strings that the user has inpputed are valid, the multiplication method will run.
    //if the operator is invalid yet the user typed in two valid input strings, the code will echo "invalid operand".
    //the else statement will only run if the user does not input the valid number of arguments.
    
    if(strlen(Op) >= 2){
    printf("invalid input operator \n");
    onOff = 1;
    }
    else if ( * Op != 'x' && * Op != '+' && * Op != '-') {
      printf("invalid input operator \n");
    }
    if ( * Op == '+' && input1 == 1 && input2 == 1 && onOff == 0) {
      addition(atoz, User1, User2, arr, arr2, arr3);
    }
    if ( * Op == 'x' && input1 == 1 && input2 == 1 && onOff == 0) {
      multiplication(atoz, User1, User2, arr, arr2, arr3);
    }
    if( * Op == '-' && input1 == 1 && input2 == 1 && onOff == 0){
      subtraction(atoz, User1, User2, arr, arr2, arr3);
    }
    if (input1 == 0 || input2 == 0) {
      printf("invalid operand");
    }
  } 
  else {
    printf("invalid number of arguments");
  }
  return 0;
}

//this addition code counts the number of occurances for each letter appearing in both operands.
//each letter has an assigned Napier number and the total numbers for each string will be added together and stored in an int 'Num'.
//'num' will then calculate the simplest string possible and store the number of occurances for each letter into array 'arr3'. 
//the simplified string will be stored in dynamic array 'arr2' and then will be printed.
void addition(char * atoz, char * User1, char * User2, int * arr, char * arr2, int * arr3) { 
  int i = 0;
  int j = 0;
  int count = 0;
  int count2 = 0;
  unsigned long long Num = 0;

  //with the help of the 'atoz' array, this code converts the 1st string of letters into its numeric value 'Num' and stores the occurance of the letter into the empty array 'arr'.
  for (i = 0; i < strlen(User1); i++) {
    for (j = 0; j < 52; j++) {
      if (User1[i] == atoz[j]) {
        arr[j]++;
        Num = Num + pow(2, j);
      }
    }
  }
  //with the help of the 'atoz' array, this code converts the 2nd string of letters into its numeric value 'Num' and stores the occurance of the letter into the empty array 'arr'.
  for (i = 0; i < strlen(User2); i++) {
    for (j = 0; j < 52; j++) {
      if (User2[i] == atoz[j]) {
        arr[j]++;
        Num = Num + pow(2, j);
      }
    }
  }

  //code to run the addition of the two operands.
  //We are able to find the simplified string using 'Num', we store its occurance into the array 'arr3'.
  //we count the amount of times a number has been stored in 'arr3'.
  //the number counted + 1 is the amount of bytes we will allocate to 'arr2' to be the exact size we need to store the simplified string.
  for (i = 51; i >= 0; i--) {
    while (Num - pow(2, i) >= 0) {
      arr3[i]++;
      Num = Num - pow(2, i);
      count++;
    }
  }


  arr2 = (char * ) malloc(sizeof(char) * count + 1);

  //this code gives 'arr2' chars corresponding to the number of occurances in 'arr3'.
  for (i = 0; i <= 51; i++) {
    while (arr3[i] >= 1) {
      arr2[count2] = atoz[i];
      count2++;
      arr3[i]--;
    }
  }

  //loop to finally print the value held in dynamic array 'arr2'.
  printf("%s + %s => ", User1, User2);
  for (i = 0; i < strlen(arr2); i++) {
    printf("%c", arr2[i]);
  }

  printf("\n");
}

//code to run multiplication starts here
//each letter contains a napier number. 
//each napier number stored in the second operand will multiply into each napier number stored in the first operand.
//that number will then be added and stored in 'num'.
//'num' will then calculate the simplest string possible and store the number of occurances for each letter into array 'arr3'. 
//the simplified string will be stored in dynamic array arr2 and then will be printed.   
void multiplication(char * atoz, char * User1, char * User2, int * arr, char * arr2, int * arr3) {
  int i = 0;
  int Q = 0;
  int j = 0;
  int count2 = 0;
  int count = 0;
  long long int num = 0;
  long long int num1 = 0;
  long long int num2 = 0;
  long long int numf = 0;
  int onOff = 0;

  //this code converts each letter for each operand into their corresponding Napier number, and then multiplies them together storing them in an int 'num'.
  //after each multiplication, the resulting napier number's corresponding letter's occurance will be stored in 'arr'.
  //the "if" statement in line 203 checks if there is a valid Napier letter corresponding to the multiplication of the two letters. If there isn't, the system will tell the user.
  for (i = 0; i < strlen(User2); i++) {
    for (j = 0; j < strlen(User1); j++) {
      for (Q = 0; Q <= 51; Q++) {
        if (User1[j] == atoz[Q]) {
          num1 = pow(2, Q);
        }
      }
      for (Q = 0; Q <= 51; Q++) {
        if (User2[i] == atoz[Q]) {
          num2 = pow(2, Q);
        }
      }
      num = num1 * num2;
     if(num > pow(2,51)){
     onOff = 1;
     }
      for (Q = 51; Q >= 0; Q--) {
        if (num - pow(2, Q) == 0) {
          arr[Q]++;
        }
      }
    }
    num1 = 0;
    num2 = 0;
  }
  
  //the letters corresponding to each number of occurances are then converted to its Napier number and stored in an int 'numf'.
  for (i = 0; i <= 51; i++) {
    while (arr[i] > 0) {
      numf = numf + pow(2, i);
      arr[i]--;
    }
  }

  //using 'numf', the simplified string is then found and each occurance of each letter is stored in an array 'arr3'.
  //we count the number of times a number is stored in 'arr3'.
  for (i = 51; i >= 0; i--) {
    while (numf - pow(2, i) >= 0) {
      arr3[i]++;
      numf = numf - pow(2, i);
      count++;
    }
  }

  //we use the number we have counted above and allocate that many bytes + 1 into a dynamic array 'arr2'
  arr2 = (char * ) malloc(sizeof(char) * count + 1); 
  
  
  if(onOff !=1 ){
  printf("%s x %s => ", User1, User2);
  for (i = 0; i <= 51; i++) {
    while (arr3[i] >= 1) {
      arr2[count2] = atoz[i];
      count2++;
      arr3[i]--;
    }
  }

  //loop to finally print the value held in dynamic array 'arr2'
  for (i = 0; i < strlen(arr2); i++) {
    printf("%c", arr2[i]);
  }
  printf("\n");
  }
  if(onOff == 1){
  printf("the expression does not have a corresponding Napier output.");
  }
  }
  
  
  void subtraction(char * atoz, char * User1, char * User2, int * arr, char * arr2, int * arr3){
  int i = 0;
  int j = 0;
  int count = 0;
  int count2 = 0;
  long long int Num = 0;
  int onOff = 0;
  
  
  //with the help of the 'atoz' array, this code converts the 1st string of letters into its numeric value 'Num' and stores the occurance of the letter into the empty array 'arr'.
  for (i = 0; i < strlen(User1); i++) {
    for (j = 0; j < 52; j++) {
      if (User1[i] == atoz[j]) {
        arr[j]++;
        Num = Num + pow(2, j);
      }
    }
  }
  
  //with the help of the 'atoz' array, this code converts the 2nd string of letters into its numeric value 'Num' and subtracts the occurance of the letter in the array 'arr'.
  for (i = 0; i < strlen(User2); i++) {
    for (j = 0; j < 52; j++) {
      if (User2[i] == atoz[j]) {
        arr[j]--;
        Num = Num - pow(2, j);
      }
    }
  }
  
  if(Num <= 0){
  printf("The Napier notation for that expression cannot be determined");
  onOff = 1;
  }
  
  
  
  //code to run the subtraction of the two operands.
  //We are able to find the simplified string using 'Num', we store its occurance into the array 'arr3'.
  //we count the amount of times a number has been stored in 'arr3'.
  //the number counted + 1 is the amount of bytes we will allocate to 'arr2' to be the exact size we need to store the simplified string.
 if(onOff == 0){
  for (i = 51; i >= 0; i--) {
    while (Num - pow(2, i) >= 0) {
      arr3[i]++;
      Num = Num - pow(2, i);
      count++;
    }
  }

  arr2 = (char * ) malloc(sizeof(char) * count + 1);

  //this code gives 'arr2' chars corresponding to the number of occurances in 'arr3'.
  for (i = 0; i <= 51; i++) {
    while (arr3[i] >= 1) {
      arr2[count2] = atoz[i];
      count2++;
      arr3[i]--;
    }
  }

  //loop to finally print the value held in dynamic array 'arr2'.
  printf("%s - %s => ", User1, User2);
  for (i = 0; i < strlen(arr2); i++) {
    printf("%c", arr2[i]);
  }
  }
  printf("\n");
  
  }