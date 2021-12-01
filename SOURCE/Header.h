#ifndef HEADER_H
#define HEADER_H
// cac ham duoc khai bao o day
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include<iomanip>

using namespace std;
template <class T>
void HoanVi(T& a, T& b);

//CAC HAM PHAT SINH DU LIEU

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n);
// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n);
// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n);
// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
//
void data(const char* dataname, int*& array, int& size);
// CAC THUAT TOAN SAP XEP

int selectionSort(int Array[], int size, uint64_t& compare);
int insertionSort(int Array[], int size, uint64_t& compare);
int bubbleSort(int Array[], int size, uint64_t& compare);
int shakerSort(int Array[], int size, uint64_t& compare);
int shellSort(int Array[], int size, uint64_t& compare);
int partition(int arr[], int left, int pivot, int right, uint64_t& compare);// 
int quickSort(int arr[], int low, int high, uint64_t& compare);
void heapify(int Array[], int n, int i, uint64_t& compare);// 
int heapSort(int Array[], int n, uint64_t& compare);
void CountSort(int a[], int n, uint64_t& compare);
int Max(int a[], int n);// 
void RadixSort(int a[], int n, uint64_t& compare);
void FlashSort(int a[], int n, uint64_t& compare);
void merge(int Array[], int const left, int const mid, int const right, uint64_t& compare);
void mergeSort(int Array[], int const begin, int const end, uint64_t& compare);
//
int selectionSort1(int Array[], int size);
int insertionSort1(int Array[], int size);
int bubbleSort1(int Array[], int size);
int shakerSort1(int Array[], int size);
int shellSort1(int Array[], int size);
int partition1(int arr[], int left, int pivot, int right);// 
int quickSort1(int arr[], int low, int high);
void heapify1(int Array[], int n, int i);// 
int heapSort1(int Array[], int n);
void CountSort1(int a[], int n);
int Max1(int a[], int n);// bo tro
void RadixSort1(int a[], int n);
void FlashSort1(int a[], int n);
void merge1(int Array[], int const left, int const mid, int const right);
void mergeSort1(int Array[], int const begin, int const end);
//CAC HAM BO TRO XU LI CODE
//CAC HAM BO TRO XU LI CODE

int SortName(const char* name);
// tra ra size hoac la file input
int Input_Size(const char* a);
// chon che do in ra gi khi ma thuc hien thuat toan sap xep
int Output_Parameters(const char* A);
// thuc hien xem la dua vao kieu mang nao trong 4 kieu
int Input_Order(const char* a);
// ham in ra theo yeu cau de
void print(int a, int compare, float times);
//HAM RUN TRONG CONSOLE
int RunMenu(int argc, const char* argv[]);
// ham goi thuat toan sort
void sort(int sortname, int*& Array, int size, uint64_t& compare, double& times);
// doc file
bool ReadFile(const char* filename, int*& array, int& size);
bool WriteFile(const char* filename, int size, int* A);
//
void printArray(int* Array, int n);
//

void copyarray(int*& A, int*& B, int size);
// command display
void command1(const char* ar2, const char* ar3, int size);
void command2(const char* ar2, const char* ar3, const char* ar4);
void command3(const char* ar2, const char* ar3);
void command4(const char* ar2, const char* ar3, const char* ar4, int size);
void command5(const char* ar2, const char* ar3, const char* ar4, const char* ar5);
#endif // HEADER_H
