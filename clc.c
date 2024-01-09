/// importing required libraries
#include <stdio.h>
#include <math.h>
#include <ctype.h>

char displayMenu(); //prototype to display menu
double binaryCalculator(double num1, double num2, int operator); 
//prototype to complete binary operation
double unaryCalculator(double num1, int operator); //prototype to complete 
unary operation
void exitCalc(); //prototype to exit calculator

//main function with all the code
int main(void){

  double num1; //first number
  double num2; //second number
  double result; //the result of the operation
  int operator; //the operator
  int option; // the option selected by the user
  int valid=0; // validates the input
  int error=0; // prints error message

  int advancesOption; // the option selected within advances
  int advancesOperator; // the operator selected within advances
  char variable1; // the first variable chosen in advances
  char variable2; // the second variable chosen in advances
  double vf1; //the first number chosen in advances
  double vf2; // the second number chosen in advances

  double a = 0; // variable a
  double b = 0; // variable b
  double c = 0; // variable c
  double d = 0; // variable d
  double e = 0; // variable e

  // prints the welcome and version message
  printf("Welcome to my Command-Line Calculator (CLC) \nDeveloper: Nabiha 
Mahboob \nVersion: Assignment 1 \nDate: October 22, 2023 
\n---------------------------------------\n\n");

option = displayMenu(); // prints the menu 

  while (option != 'E'){ // runs the loop for the calculator to execute 
until the user wants to exit

    switch(option){ // checks which operation option the user selcted

      case 'B': // executes if the user chose Binary Operations

        do{ // gets the first number and validates input
          if (error !=0){
            printf("Invalid Input\n");
          }
          printf("Please enter the first number:\n"); 
          valid = scanf("%lf", &num1); // gets the first number
          while ((getchar()) != '\n'); //dissolves new line character
          error += 1;
        }while(valid ==0); // checks if the input is valid 
        error=0;

        valid = 0;

        do{ // gets the operator and validates input
          if (error !=0){
            printf("Invalid Input\n");
          }
          printf("Please enter the operation ( + , - , * , / , %% , P , X 
, I ):\n");
          operator = getchar(); // gets the operator
          operator = toupper(operator);
          while ((getchar()) != '\n');
          error += 1;
        }while(operator==EOF);// checks if the input is a valid type
        error=0;
        valid = 0;

        do{ // gets the second number and validates input
          if (error !=0){
            printf("Invalid Input\n");
          }
          printf("Please enter the second number: \n");
          valid = scanf("%lf", &num2); // gets the second number
          while ((getchar()) != '\n'); //dissolves new line character
          error += 1;
        }while(valid==0);// checks if the input is valid 
        valid=0;
        error=0;
        
        result = binaryCalculator(num1,num2, operator); //runs the binary 
operation

        //prints the result of the operation
        if (result==INFINITY){
          printf("The result is undefined or imaginary\n");
        }
        else {
          printf("The result is %f\n", result);
        }
        break;

      case 'U': // executes if the user selects unary Operations

        do{ // gets the operation and validates input 
          if (error !=0){
            printf("Invalid Input\n");
          }
          printf("Please enter the operation you would like to complete ( 
S , L , E , C , F )\n");
          operator=getchar();
          operator = toupper(operator);
          while ((getchar()) != '\n');
          error += 1;
        }while(operator==EOF); // checks if the input is a valid type
        error=0;
        valid=0;

        do{ // gets the number and validates input
          if (error !=0){
            printf("Invalid Input\n");
          }
          printf("Please enter the number you would like to complete the 
operation with\n");
          valid = scanf("%lf", &num1);
          while ((getchar()) != '\n');
          error += 1;
        }while(valid==0); // checks if the input is valid 
        valid=0;
        error=0;

        result = unaryCalculator(num1, operator); //runs the unary 
operation

        // prints the calculated result
        if (result==INFINITY){
          printf("The result is undefined or imaginary\n");
        }
        else {
          printf("The result is %f\n", result);
        }
        
        break;

      case 'A': // executes if the user selects Advances
        do{ // prints the advances menu and validates input
          if (error !=0){
            printf("Invalid Input\n");
          }
          printf("Select one of the following items: \n");
          printf("B) - Binary Mathematical Operations, such as addition 
and subtraction. \n");
          printf("U) - Unary Mathematical Operations, such as square root, 
and log. \n");
          printf("E) - Exit to Main Menu \n");
          advancesOption = getchar();
          while ((getchar()) != '\n');
          advancesOption = toupper(advancesOption);
          error += 1;
        }while(advancesOption!='B' && advancesOption!='U' && 
advancesOption!='E');
        error=0;

        while (advancesOption != 'E'){ // runs the loop for advances to 
execute until the user wants to exit to the main menu

          switch(advancesOption){	//checks which advances operation 
the user selected

            case 'B': // runs if the user selects binary

              do{ // gets the first number or variable, sets the number 
and validates input	 
                if (error !=0){
                  printf("Invalid Input\n");
                  }
                printf("Please enter the first variable (a, b, c, d, e) or 
number:\n");
                if (scanf("%lf", &vf1)==1){ // checks if the input is a 
number and gets the number
                  while ((getchar()) != '\n');
                  num1=vf1;
                  valid= 1;
                }
                else if (scanf("%c", &variable1)==1){ // checks if the 
input is a variable and gets the number from the variable
                  if (variable1=='\n'){
                    error=1;
                    continue;
                  }
                  while ((getchar()) != '\n');
                  variable1 = tolower(variable1);
                  if (variable1=='a'){
                    num1 = a;
                    valid = 1;
                  }
                  else if (variable1=='b'){
                    num1 = b ;
                    valid = 1;
                  }
                  else if (variable1=='c'){
                    num1 = c ;
                    valid = 1;
                  }
                  else if (variable1=='d'){
                    num1 = d ;
                    valid = 1;
                  }
                  else if (variable1=='e'){
                    num1 = e ;
                    valid = 1;
                  }
                  else{
                    valid=0;
                  }
                }
                error=1;
              }while(valid==0);
              valid=0;
              error=0;


              do{ // gets the operation from the user and validates it
                if (error !=0){
                  printf("Invalid Input\n");
                 }
                printf("Please enter the operation ( + , - , * , / , %% , 
P , X , I ):\n");
                //valid = scanf("%1d", &advancesOperator);
                advancesOperator = getchar(); // gets the operator
                while ((getchar()) != '\n');
                advancesOperator = toupper(advancesOperator);
                error += 1;
              }while(advancesOperator==EOF);// checks if the input is a 
valid type
              error=0;
              valid=0;

              do{ // gets the second number or variable, sets the number 
and validates input
                if (error !=0){
                    printf("Invalid Input\n");
                  }
                printf("Please enter the second variable (a, b, c, d, e) 
or number: \n");
                if (scanf("%lf", &vf2)==1){ // checks if the input is a 
number and gets the number
                  while ((getchar()) != '\n');
                  num2=vf2;
                  valid=1;
                  error += 1;
                }
                else if (scanf("%c", &variable2)==1){ // checks if the 
input is a variable and gets the number from the variable
                  if (variable2=='\n'){
                    error=1;
                    continue;
                  }
                  while ((getchar()) != '\n');
                  variable2 = tolower(variable2);
                  if (variable2=='a'){
                    num2 = a;
                    valid=1;
                  }
                  else if (variable2=='b'){
                    num2 = b ;
                    valid=1;
                  }
                  else if (variable2=='c'){
                    num2 = c ;
                    valid=1;
                  }
                  else if (variable2=='d'){
                    num2 = d ;
                    valid=1;
                  }
                  else if (variable2=='e'){
                    num2 = e ;
                    valid=1;
                  }
                  error += 1;
                }
              }while(valid==0);
              valid=0;
              error=0;

              result = binaryCalculator( num1, num2, advancesOperator); // 
runs the binary  and stores the result

              //prints the calculated result
              if (result==INFINITY){
                printf("The result is undefined or imaginary\n");
              }
              else {
                printf("The result is %2f\n", result);
              }
              break;

            case 'U': // if the user selects unary operation
              do{ // gets the operation and validates input
                if (error !=0){
                printf("Invalid Input\n");
                }
                printf("Please enter the operation you would like to 
complete ( S , L , E , C , F )\n");
                //valid = scanf("%1d", &operator);
                advancesOperator = getchar();
                while ((getchar()) != '\n');
                advancesOperator = toupper(advancesOperator);
                error += 1;
              }while(advancesOperator==EOF); // checks if the input is a 
valid type
              error=0;
              valid=0;

              do{ // gets the number or variable, sets the number and 
validates input
                if (error !=0){
                    printf("Invalid Input\n");
                  }
                printf("Please enter the number or variable (a, b, c, d, 
e) you would like to complete the operation with\n"); 
                if (scanf("%lf", &vf1)==1){ // checks if the input is a 
number and gets the number
                  while ((getchar()) != '\n');
                  num1=vf1;
                  valid=1;
                  error += 1;
                }
                else if (scanf("%c", &variable1)==1){ // checks if the 
input is a variable and gets the number from the variable
                  if (variable1=='\n'){
                    error=1;
                    continue;
                  }
                  while ((getchar()) != '\n');
                  variable1 = tolower(variable1);
                  if (variable1=='a'){
                    num1 = a;
                    valid=1;
                  }
                  else if (variable1=='b'){
                    num1 = b ;
                    valid=1;
                  }
                  else if (variable1=='c'){
                    num1 = c ;
                    valid=1;
                  }
                  else if (variable1=='d'){
                    num1 = d ;
                    valid=1;
                  }
                  else if (variable1=='e'){
                    num1 = e ;
                    valid=1;
                  }
                  error += 1;
                }
              }while(valid==0);
              valid=0;
              error=0;

              result = unaryCalculator( num1, advancesOperator); // runs 
the unary operation
              //prints the calculated resuly
            if (result==INFINITY){
              printf("The result is undefined or imaginary\n");
            }
            else {
              printf("The result is %f\n", result);
            }
            case 'E':
              break;
            default:
              printf("Not a valid option\n");
            }

          do{ // asks the user for a new option input and validates the 
input
            if (error !=0){
              printf("Invalid Input\n");
            }
            printf("Please select your option (B, U, E)\n");
            advancesOption = getchar();
            advancesOption = toupper(advancesOption);
            while ((getchar()) != '\n');
            error += 1;
          }while(advancesOption!='B' && advancesOption != 'U' && 
advancesOption != 'E');
          error=0;
        }
        break;

      case 'V': // executes if the user selects Variable

        do{ // asks the user for a variable to set and validates the input
          if (error !=0){
            printf("Invalid Input\n");
          }
          printf("Enter the variable you would like to set (a, b, c, d, 
e)\n");
          operator = getchar();
          while ((getchar()) != '\n');
          operator = tolower(operator);
          error += 1;
        }while(operator!='a' && operator!='b' && operator!='c' && 
operator!='d' && operator!='e');
        error=0;
        valid=0;

        do{ // asks the user the number to set the chosen variable to and 
validates it
          if (error !=0){
            printf("Invalid Input\n");
          }
          printf("Please enter the number you would like to set this 
variable as\n");
          valid=scanf("%lf", &num1);
          while ((getchar()) != '\n');
          error += 1;
        }while(valid==0);
        valid=0;
        error=0;

        switch(operator){ //sets the selected variable to the chosen 
number

          case 'a': 
            a = num1;
            break;

          case 'b':
            b = num1;
            break;

          case 'c':
            c = num1;
            break;

          case 'd':
            d = num1;
            break;

          case 'e':
            e = num1;
            break;

          default:
            printf("You did not enter a valid variable\n");

          }
        break;

      default: // executes if the user selects an Invalid option
        printf("Invalid option. Please select your option (B, U, A, V, 
E)\n");
    }

    option = displayMenu();

  }
  exitCalc(); // exits and prints goodbye statement
}	

//prints the user menu, takes iput and returns the option picked
char displayMenu(){
  char option; // declares option variable
  int error=0; //used to print error message
  do{ // prints the menu for the user, gets an input and validates it
    if (error !=0){
      printf("Invalid Input\n");
      printf("%d", error);
    }
    printf("Select one of the following items: \n");
    printf("B) - Binary Mathematical Operations, such as addition and 
subtraction. \n");
    printf("U) - Unary Mathematical Operations, such as square root, and 
log. \n");
    printf("A) - Advances Mathematical Operations, using variables and 
arrays. \n");
    printf("V) - Define variables and assign them values. \n");
    printf("E) - Exit \n");
    option = getchar(); // gets the option selected by the user
    option = toupper(option);
    while ((getchar()) != '\n');
    error = 1;
  }while(option != 'B' && option != 'U' && option != 'A' && option != 'V' 
&& option != 'E');
  error=0;
  return option;
}

//runs the binary option, checks operator validity, calculates the result 
and returns it
double binaryCalculator(double num1, double num2, int operator){
  double result; // declares result variable
  int valid=0; //checks input validity

  //checks whether the operator is a valid operator
  while(operator != '+'&& operator != '-'&& operator != '*'&& operator != 
'/'&& operator != '%'&& operator != 'P'&& operator != 'X' && operator != 
'I'){
    printf("Invalid Operator Input\n");
    printf("Please enter the operation ( + , - , * , / , %% , P , X , I 
):\n");
    operator = getchar();
    operator = toupper(operator);
    while ((getchar()) != '\n');
  }
  
  switch(operator){ // checks which operator the user selected

    case '+': // does the addition and prints it
      result = num1 + num2;
      break;

    case '-': // does the subtraction and prints it
      result = num1 - num2;
      break;

    case '*': // does the multiplication and prints it
      result = num1 * num2;
      break;

    case '/': // does the division, checks for math error and prints it
      if (num2==0){
        result = INFINITY;
      }
      else{
        result = num1 / num2;
      }
      break;

    case '%': // does the modulo and prints it
      result = (int) num1 % (int)num2;
      break;

    case 'P': // does the power calculation and prints it
      result = pow(num1, num2);
      break;

    case 'X': // does the maximum calculation and prints it
      if (num1>num2){
        result = num1;
      }
      else if (num2>num1){
        result = num2;
      }
      else{
        result = num1;
      }
      break;

    case 'I'://does the minimum calculation and prints it
      if (num1<num2){
        result = num1;
      }
      else if (num2<num1){
        result = num2;
      }
      else{
        result = num1;
      }
      break;

    default: //if the input is not valid
      printf("You did not enter a valid operator. \n");
  }
  return result;
}

//runs the unary option, checks operator validity, calculates the result 
and returns it
double unaryCalculator(double num1, int operator){
  double result; 

  // checks the if the operator is valid
  while(operator != 'S'&& operator != 'L' && operator != 'E' && operator 
!= 'C' && operator != 'F'){
    printf("Invalid Operator Input\n");
    printf("Please enter the operation you would like to complete ( S , L 
, E , C , F )\n");
    operator = getchar();
    operator = toupper(operator);
    while ((getchar()) != '\n');
  }
  
  switch(operator){ //checks which operator the user selected
    
  case 'S': //performs square root operation and prints the result
    if (num1<0){
      result = INFINITY;
    }
    else{
      result = sqrt(num1);
    }
    break;

  case 'L': //performs logarithm operation and prints the result
    if (num1 <= 0){
      result = INFINITY;
    }
    else{
      result = log(num1);
    }
    break;

  case 'E': // performs exponential operation and prints the result
    result = exp(num1);
    break;

  case 'C': // performs ceiling operation and prints the result
    result = ceil(num1);
    break;

  case 'F': // performs floor operation and prints the result
    result = floor(num1);
    break;

  default: //if the input is invalid this executes 
    printf("Not a valid Operator\n");
    break;
}
  return result;
}

//exits the calculator and prints goodbye message
void exitCalc(){
  printf("Thanks for using my Simple Calculator. Hope to see you again 
soon. Goodbye!");
}


