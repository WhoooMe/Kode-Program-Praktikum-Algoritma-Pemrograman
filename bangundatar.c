#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#ifndef phi
#define phi 3.1416
#endif 

void clearScreen();
void start();
void menuOption();
double getNumbers(const char* word);
void Scalene_triangle();
void Rhombus();
void Parallelogram();
void Trapezoid();
void Circle();


int main (void) {
    int option;
    int repeat;

      do {
        clearScreen();
        start();
        menuOption();

        option = (int)getNumbers("Enter Menu Options (1-6): ");

        switch (option) {
          case 1:
              Scalene_triangle();
              break;
          case 2:
              Rhombus();
              break;
          case 3:
              Parallelogram();
              break;
          case 4:
              Trapezoid();
              break;
          case 5:
              Circle();
              break;
          case 6:
              printf ("\nThank you For Using This Program!. From: Group 10\n");
              return 0;
          default:
              printf ("\n[ERROR] => Invalid Input. Please Select The Available Menu (1-6).\n");
              break;
        }

        printf ("\n=================================================\n");
        printf ("Wanna do Another Calculation? (1 = yes | 0 = no): ");

        while (scanf(" %d", &repeat) != 1 || (repeat != 1) && (repeat != 0)) {
          printf("Invalid Input. Only Input 1 and 0: ");
          while (getchar() != '\n');
        }

  } while (repeat == 1);
  printf ("\nThank you For Using This Program!. From: Group 10\n");
  return 0;
}

void clearScreen () {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* #ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void Delay(int milidetik) {
    #ifdef _WIN32
        Sleep(milidetik);
    #else
        usleep(milidetik * 1000);
    #endif
} */

void start() {
  int border = 61, i = 0;
  while (i < border) {
    printf ("=");
    i++;
  }
  i = 0;
  printf ("\n==>                   WELCOME TO PROGRAM                  <==\n");
  printf ("==>  CALCULATING THE AREA AND PERIMETER OF PLANE FIGURES  <==\n");
  printf ("==>            by GROUP 10. All rights reserved           <==\n");

  while (i < border) {
    printf ("=");
    i++;
  }
}

void menuOption() {
  for (int j = 0; j < 1; j++) {
    printf ("\n");
  }
  printf ("\n=> PLEASE SELECT ONE MENU TO CALCULATE <=\n");
  printf ("1. Scalene triangle\n");
  printf ("2. Rhombus\n");
  printf ("3. Parallelogram\n");
  printf ("4. Trapezoid\n");
  printf ("5. Circle\n");
  printf ("6. EXIT!\n");
}

double getNumbers (const char* word) {
  char buffer[100];
  char* endptr;
  double value;
    
    while (1) {
      printf ("%s", word);

      if (fgets(buffer, sizeof(buffer), stdin) != NULL) {

        if (buffer[0] == '\n' || strspn (buffer, " \n\t") == strlen(buffer)) {
          printf ("[ERROR] => Input Must Not be Empty. Try Again!.\n");
          continue;
        }
        value = strtod(buffer, &endptr);

        if (endptr == buffer || *endptr != '\n' && *endptr != '\0' && !isspace(*endptr)) {
          printf ("[ERROR] => Input Must be Numbers. Try Again!.\n");
        } else if (value <= 0) {
          printf ("[ERROR] => Menu Not Found 404!\n");
        }
        else {
          return value;
        }
      }
    }
}

void Scalene_triangle() {
  clearScreen();
  printf ("--- CALCULATE SCALENE TRIANGLE ---\n");
  double a, b, c, setP, area, perimeter;

    while (1) {
      a = getNumbers ("Enter The Length of Side a : ");
      b = getNumbers ("Enter The Lenght of Side b : ");
      c = getNumbers ("Enter The Lenght of Side c : ");
        if ((a + b > c) && (a + c > b) && (b + c > a)) {
          break;
        } else {
          printf ("\n[ERROR] => Not a Valid Triangle!\n\n");
        }
    }

    perimeter = a + b + c;
    setP = perimeter / 2.00;
    area = sqrt(setP * (setP - a) * (setP - b) * (setP - c));

    printf ("\n--- RESULTS ---\n");
    printf ("Area of Scalene Triangle       : %.2f\n", area);
    printf ("Perimeter of Scalene Triangle  : %.2f\n", perimeter);
}

void Rhombus() {
  clearScreen();
  printf ("--- CALCULATE RHOMBUS ---\n");
  double d1, d2, s, perimeter, area;

    while (1) {
      d1 = getNumbers ("Enter The First Diagonals of Rhombus   : ");
      d2 = getNumbers ("Enter The Second Diagonals of Rhombus  : ");
      s = getNumbers ("Enter The Side of Rhombus              : ");
        if (d1 >= 0 && d2 >= 0 && s >= 0) {
          break;
        } else {
          printf ("\n[ERROR] => The Value Must be Positive!\n\n");
        }
    }

    perimeter = 4 * s;
    area = 0.5 * d1 * d2;

    printf ("\n--- RESULTS ---\n");
    printf ("Areao of Rhombus      : %.2f\n", area);
    printf ("Perimeter of Rhombus  : %.2f\n", perimeter);
}

void Parallelogram () {
  clearScreen();
  printf ("--- CALCULATE PARALLELOGRAM ---\n");
  double a, b, h, area, perimeter;

  a = getNumbers ("Enter Length of The Base           : ");
  b = getNumbers ("Enter Length of The Slanted Side   : ");
  h = getNumbers ("Enter The Height of Parallelogram  : ");

  perimeter = 2 * (a + b);
  area = a * h;

  printf ("\n--- RESULTS ---\n");
  printf ("Area of Parallelogram       : %.2f\n", area);
  printf ("Perimeter of Parallelogram  : %.2f\n", perimeter);
}

void Trapezoid() {
  clearScreen();
  printf ("--- CALCULATE TRAPEZOID ---\n");
  double a, b, c, d, h, area, perimeter;

  a = getNumbers ("Enter Length of The Top Parallel Side     : ");
  b = getNumbers ("Enter Length of The Bottom Parallel Side  : ");
  c = getNumbers ("Enter The Lenght of Side c                : ");
  d = getNumbers ("Enter The Lenght of Side d                : ");
  h = getNumbers ("Enter The Height of Trapezoid             : ");

  area = 0.5 * (a + b) * h;
  perimeter = a + b + c + d;

  printf ("\n--- RESULTS ---\n");
  printf ("Area of Trapezoid       : %.2f\n");
  printf ("Perimeter of Trapezoid  : %.2f\n");
}

void Circle() {
  clearScreen();
  printf ("--- CALCULATE CIRCLE ---\n");
  double r, area, perimeter;

  r = getNumbers ("Enter The Radius Value: ");

  area = phi * pow(r, 2);
  perimeter = 2 * phi * r;

  printf ("\n--- RESULTS ---\n");
  printf ("Area of Circle       : %.2f\n", area);
  printf ("Perimeter of Circle  : %.2f\n", perimeter);
}

/* if (scanf("%d", &repeat) != 1) {
          printf("Input invalid! Please enter only 1 or 0.\n");

          while (getchar() != '\n');
          repeat = -1;
          continue;
        }

        if (repeat == 1) {
          printf ("You Chose YES. Continuing Calculation...\n");
        } else if (option == 0) {
          printf ("\nThank you For Using This Program!. From: Group 10\n");
        } else {
          printf("Input invalid! Please enter only 1 or 0.\n");
          repeat = -1;
        } */