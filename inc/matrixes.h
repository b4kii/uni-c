#ifndef MATRIXES_H
#define MATRIXES_H

int **initializeMatrix(int, int);
void completeMatrix(int **, int, int);
void showMatrix(int **, int, int);
void freeMatrix(int **, int);
void matrixes();
void renderMatrixesMenu(int **, int, int);
void switchRows(int **);
void reverse(int **, int **);

#endif // MATRIXES_H
