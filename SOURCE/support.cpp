#include"Header.h"
using namespace std;

// ham xu li ten thuat toan
int SortName(const char* name)
{
    // bang luu giu ten cac bien sort
    char sortname[11][30] = { "selection-sort","insertion-sort","bubble-sort","shaker-sort","shell-sort"
    ,"heap-sort","merge-sort","quick-sort","counting-sort","radix-sort","flash-sort" };
    for (int i = 0; i < 11; i++)
        if (strcmp(name, sortname[i]) == 0)
            return i + 1;
    return -1;
}
// tra ra size hoac la file input
int Input_Size(const char* a)
{
    int size = atoi(a);
    return size;// size = 0 thi doc file
}
// chon che do in ra gi khi ma thuc hien thuat toan sap xep
int Output_Parameters(const char* A)
{
    if (strcmp(A, "-both") == 0)
    {
        return 3;// 3 la ca 2 che do
    }
    if (strcmp(A, "-comp") == 0)
        return 2;// in ra compare
    if (strcmp(A, "-time") == 0)
        return 1;// in ra time

    return -1;// -1 la nhap sai
}
// thuc hien xem la dua vao kieu mang nao trong 4 kieu
int Input_Order(const char* a)
{
    if (strcmp(a, "-rand") == 0)
        return 1;//1 la random
    if (strcmp(a, "-nsorted") == 0)
        return 2;// 2 la nearly sorted
    if (strcmp(a, "-sorted") == 0)
        return 3;// 3 la sorted
    if (strcmp(a, "-rev") == 0)
        return 4;// 4 la rever
    return -1;// - 1 la nhap sai
}
// display
void print(int a, int compare, float times)// in theo yeu cau cua de cho
{
    if (a == 2) {
        cout << "Comparisions: " << compare << endl;
        cout << endl;
    }
    if (a == 1) {
        cout << "Running time: " << times << endl;
        cout << endl;
    }
    if (a == 3)
    {
        cout << "Running time: " << times << endl;
        cout << "Comparisions: " << compare << endl;
        cout << endl;
    }
}
void command2(const char* ar2, const char* ar3, const char* ar4)
{
    cout << "ALGORITHM MODE: " << endl;
    cout << "Algorithm: " << ar2 << endl;
    cout << "Input size: " << ar3 << endl;
    int i = Input_Order(ar4);
    string a;
    if (i == 1)
        a = "randomized data";
    else if (i == 2)
        a = " nearly sorted data";
    else if (i == 3)
        a = "sorted data";
    else
        a = "reverse sorted data";
    cout << "Input order:" << a << endl;
    cout << "------------------------------" << endl;
}
void command1(const char* ar2, const char* ar3, int size)
{
    cout << "ALGORITHM MODE: " << endl;
    cout << "Algorithm: " << ar2 << endl;
    cout << "Input file: " << ar3 << endl;
    cout << "Input size:" << size << endl;
    cout << "------------------------------" << endl;
}
void command4(const char* ar2, const char* ar3, const char* ar4, int size)
{

    cout << "COMPARE MODE: " << endl;
    cout << "Algorithm: " << setw(23) << left << ar2 << "  |  " << ar3 << endl;
    cout << "Input file: " << ar4 << endl;
    cout << "Input size:" << size << endl;
    cout << "------------------------------" << endl;
}
void command5(const char* ar2, const char* ar3, const char* ar4, const char* ar5)
{

    cout << "COMPARE MODE: " << endl;
    cout << "Algorithm: " << setw(23) << left << ar2 << "  |  " << ar3 << endl;
    cout << "Input size: " << ar4 << endl;
    int i = Input_Order(ar5);
    string a;
    if (i == 1)
        a = "randomized data";
    else if (i == 2)
        a = " nearly sorted data";
    else if (i == 3)
        a = "sorted data";
    else
        cout << "Input order:" << a << endl;
    cout << "------------------------------" << endl;
}
void command3(const char* ar2, const char* ar3)
{
    cout << "ALGORITHM MODE: " << endl;
    cout << "Algorithm: " << ar2 << endl;
    cout << "Input size: " << ar3 << endl;

}
// doc file
bool ReadFile(const char* filename, int*& array, int& size)
{
    size = 0;
    array = NULL;
    ifstream f(filename);
    if (f.is_open())
    {
        f >> size;
        array = new int[size];
        for (int i = 0; i < size; i++)
            f >> array[i];
        f.close();
        return true;
    }
    return false;

}
bool WriteFile(const char* filename, int size, int* A)
{
    ofstream output;
    output.open(filename, ios::out);
    output << size << endl;
    for (int i = 0; i < size; i++)
    {
        output << A[i] << " ";
    }
    output.close();
    return true;
}

// in mang

// goi ham sort
void sort(int sortname, int*& Array, int size, uint64_t& compare, double& times)
{
    clock_t begin, end;
    int* temp = new int[size];
    copyarray(Array, temp, size);
    switch (sortname)
    {
    case 1:
        selectionSort(Array, size, compare);
        begin = clock();
        selectionSort1(temp, size);
        end = clock();
        times = (double)((end - begin) * 1000 / CLOCKS_PER_SEC);
        delete[]temp;
        break;
    case 2:
        insertionSort(Array, size, compare);
        begin = clock();
        insertionSort1(temp, size);
        end = clock();
        times = (double)((end - begin) * 1000 / CLOCKS_PER_SEC);
        delete[]temp;
        break;
    case 3:
        bubbleSort(Array, size, compare);
        begin = clock();
        bubbleSort1(temp, size);
        end = clock();
        times = (double)((end - begin) * 1000 / CLOCKS_PER_SEC);
        delete[]temp;
        break;
    case 4:
        shakerSort(Array, size, compare);
        begin = clock();
        shakerSort1(temp, size);
        end = clock();
        times = (double)((end - begin) * 1000 / CLOCKS_PER_SEC);
        delete[]temp;
        break;
    case 5:
        shellSort(Array, size, compare);
        begin = clock();
        shellSort1(temp, size);
        end = clock();
        times = (double)((end - begin) * 1000 / CLOCKS_PER_SEC);
        delete[]temp;
        break;
    case 6:
        heapSort(Array, size, compare);
        break;
    case 7:
        mergeSort(Array, 0, size - 1, compare);
        begin = clock();
        mergeSort1(temp, 0, size - 1);
        end = clock();
        times = (double)((end - begin) * 1000 / CLOCKS_PER_SEC);
        delete[]temp;
        break;
    case 8:
        quickSort(Array, 0, size - 1, compare);
        begin = clock();
        quickSort1(temp, 0, size - 1);
        end = clock();
        times = (double)((end - begin) * 1000 / CLOCKS_PER_SEC);
        delete[]temp;
        break;
    case 9:
        CountSort(Array, size, compare);
        begin = clock();
        CountSort1(temp, size);
        end = clock();
        times = (double)((end - begin) * 1000 / CLOCKS_PER_SEC);
        delete[]temp;
        break;
    case 10:
        RadixSort(Array, size, compare);
        begin = clock();
        RadixSort1(temp, size);
        end = clock();
        times = (double)((end - begin) * 1000 / CLOCKS_PER_SEC);
        delete[]temp;
        break;
    case 11:
        FlashSort(Array, size, compare);
        begin = clock();
        FlashSort1(temp, size);
        end = clock();
        times = (double)((end - begin) * 1000 / CLOCKS_PER_SEC);
        delete[]temp;
        break;

    default:
        cout << "xin moi nhap lai";
        break;
    }
}
// in
void printArray(int* Array, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << Array[i] << " ";
    cout << endl;
}
void copyarray(int*& A, int*& B, int size)
{
    for (int i = 0; i < size; i++)
        B[i] = A[i];
}
