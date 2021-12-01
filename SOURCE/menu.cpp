#include"Header.h"

int RunMenu(int argc, const char* argv[])
{
    // argc la so luong phan tu truyen vao ham
    // argv[0] la ten chuong trinh
    if (argc >= 5 && argc <= 8)
    {
        if (strcmp(argv[1], "-a") == 0)
        {
            // thuat toan sap xep
            uint64_t compare = 0;
            double times = 0;
            // xu li ten thuat toan
            int name = SortName(argv[2]);
            int size = Input_Size(argv[3]);// kiem tra xem do la file hay la input size
            int inputorder = Input_Order(argv[4]); // kiem tra kieu du lieu

            switch (name)
            {
            case 1:// selection sort

                if (size != 0)
                {
                    if (inputorder == -1)// cmd 3
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(1, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(1, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(1, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(1, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //

                        break;
                    }
                    else
                    {
                        // 2
                        int* A = new int[size];
                        data(argv[4], A, size);
                        WriteFile("input.txt", size, A);
                        sort(1, A, size, compare, times);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);
                        break;
                    }

                }
                else {
                    //1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(1, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            case 2:// insertion sort
                if (size != 0)
                {
                    if (inputorder == -1)
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(2, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(2, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(2, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(2, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //

                        break;
                    }
                    else
                    {
                        //cmd 2 
                        int* A = new int[size];
                        data(argv[4], A, size);
                        WriteFile("input.txt", size, A);
                        sort(2, A, size, compare, times);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);

                        break;
                    }
                }
                else
                {
                    //cmd 1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(2, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            case 3:// bubble sort
                if (size != 0)
                {
                    if (inputorder == -1)
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(3, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(3, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(3, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(3, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //

                        break;
                    }
                    else
                    {
                        //cmd 2 
                        int* A = new int[size];
                        data(argv[4], A, size);
                        WriteFile("input.txt", size, A);
                        sort(3, A, size, compare, times);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);

                        break;
                    }
                }
                else
                {
                    //cmd 1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(3, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            case 4:// shaker sort
                if (size != 0)
                {
                    if (inputorder == -1)
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(4, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(4, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(4, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(4, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //

                        break;
                    }
                    else
                    {
                        //cmd 2 
                        int* A = new int[size];
                        data(argv[4], A, size);
                        sort(4, A, size, compare, times);
                        WriteFile("input.txt", size, A);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);
                        break;
                    }
                }
                else
                {
                    //cmd 1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(4, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            case 5:// shell sort
                if (size != 0)
                {
                    if (inputorder == -1)
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(5, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(5, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(5, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(5, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //

                        break;
                    }
                    else
                    {
                        //cmd 2 
                        int* A = new int[size];
                        data(argv[4], A, size);
                        WriteFile("input.txt", size, A);
                        sort(5, A, size, compare, times);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);
                        break;
                    }
                }
                else
                {
                    //cmd 1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(5, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            case 6:// heap sort
                if (size != 0)
                {
                    if (inputorder == -1)
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(6, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(6, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(6, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(6, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //

                        break;
                    }
                    else
                    {
                        //cmd 2 
                        int* A = new int[size];
                        data(argv[4], A, size);
                        WriteFile("input.txt", size, A);
                        sort(6, A, size, compare, times);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);
                        break;
                    }
                }
                else
                {
                    //cmd 1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(6, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            case 7:// merge xem lai
                if (size != 0)
                {
                    if (inputorder == -1)
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(7, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(7, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(7, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(7, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //

                        break;
                    }
                    else
                    {
                        //cmd 2 
                        int* A = new int[size];
                        data(argv[4], A, size);
                        WriteFile("input.txt", size, A);
                        sort(7, A, size, compare, times);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);
                        break;
                    }
                }
                else
                {
                    //cmd 1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(7, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            case 8:// quick xem lai
                if (size != 0)
                {
                    if (inputorder == -1)
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(8, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(8, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(8, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(8, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //

                        break;
                    }
                    else
                    {
                        //cmd 2 
                        int* A = new int[size];
                        data(argv[4], A, size);
                        WriteFile("input.txt", size, A);
                        sort(8, A, size, compare, times);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);

                        break;
                    }
                }
                else
                {
                    //cmd 1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(8, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            case 9:// counting
                if (size != 0)
                {
                    if (inputorder == -1)
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(9, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(9, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(9, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(9, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //

                        break;
                    }
                    else
                    {
                        //cmd 2 
                        int* A = new int[size];
                        data(argv[4], A, size);
                        WriteFile("input.txt", size, A);
                        sort(9, A, size, compare, times);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);

                        break;
                    }
                }
                else
                {
                    //cmd 1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(9, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            case 10:// radix
                if (size != 0)
                {
                    if (inputorder == -1)
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(10, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(10, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(10, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(10, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //

                        break;
                    }
                    else
                    {
                        //cmd 2
                        int* A = new int[size];
                        data(argv[4], A, size);
                        WriteFile("input.txt", size, A);
                        sort(10, A, size, compare, times);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);
                        break;
                    }
                }
                else
                {
                    //cmd 1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(10, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            case 11: //flash sort
                if (size != 0)
                {
                    if (inputorder == -1)
                    {
                        //cmd 3
                        command3(argv[2], argv[3]);
                        int outputparam = Output_Parameters(argv[4]);
                        int* A = new int[size];
                        GenerateRandomData(A, size);
                        WriteFile("input_1.txt", size, A);
                        sort(11, A, size, compare, times);
                        cout << "Input order: Random" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]A;
                        //
                        int* B = new int[size];
                        GenerateNearlySortedData(B, size);
                        WriteFile("input_2.txt", size, B);
                        sort(11, B, size, compare, times);
                        cout << "Input order: Nearly Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]B;
                        //
                        int* C = new int[size];
                        GenerateSortedData(C, size);
                        WriteFile("input_3.txt", size, C);
                        sort(11, C, size, compare, times);
                        cout << "Input order: Sorted" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]C;
                        //
                        int* D = new int[size];
                        GenerateReverseData(D, size);
                        WriteFile("input_4.txt", size, D);
                        sort(11, D, size, compare, times);
                        cout << "Input order: Reveresd" << endl;
                        cout << "------------------------------" << endl;
                        print(outputparam, compare, times);
                        delete[]D;
                        //
                        break;
                    }
                    else
                    {
                        //cmd 2 
                        int* A = new int[size];
                        data(argv[4], A, size);
                        WriteFile("input.txt", size, A);
                        sort(11, A, size, compare, times);
                        int outputparam = Output_Parameters(argv[5]);
                        command2(argv[2], argv[3], argv[4]);
                        print(outputparam, compare, times);

                        break;
                    }
                }
                else
                {
                    //cmd 1
                    int* A;
                    int _size = 0;
                    int outputparam = Output_Parameters(argv[4]);
                    ReadFile(argv[3], A, _size);
                    sort(11, A, _size, compare, times);
                    WriteFile("output.txt", _size, A);
                    command1(argv[2], argv[3], _size);
                    print(outputparam, compare, times);
                    delete[]A;
                    break;
                }
                break;
            default:
                break;
            }

        }
        else if (strcmp(argv[1], "-c") == 0)
        {
            int name1 = SortName(argv[2]);
            int name2 = SortName(argv[3]);

            int size = Input_Size(argv[4]);
            if (size != 0)// 5
            {
                uint64_t compare1 = 0, compare2 = 0;
                double time1 = 0, time2 = 0;
                int* A = new int[size];
                int* B = new int[size];
                data(argv[5], A, size);
                WriteFile("input.txt", size, A);
                copyarray(A, B, size);
                sort(name1, A, size, compare1, time1);
                delete[]A;
                sort(name2, B, size, compare2, time2);
                delete[]B;
                command5(argv[2], argv[3], argv[4], argv[5]);
                cout << "Running time: " << setw(20) << left << time1 << "  |  " << time2 << endl;
                cout << "Comparisions: " << setw(20) << left << compare1 << "  |  " << compare2 << endl;
            }
            else// 4
            {
                int* A;
                int* B;
                int _size = 0;
                uint64_t compare1 = 0;
                uint64_t compare2 = 0;
                double time1 = 0;
                double time2 = 0;
                ReadFile(argv[4], A, _size);
                ReadFile(argv[4], B, _size);
                int name1 = SortName(argv[2]);
                int name2 = SortName(argv[3]);
                sort(name1, A, _size, compare1, time1);
                delete[]A;
                sort(name2, B, _size, compare2, time2);
                WriteFile("output.txt", _size, B);
                delete[]B;
                command4(argv[2], argv[3], argv[4], _size);
                cout << "Running time: " << setw(20) << left << time1 << "  |  " << time2 << endl;
                cout << "Comparisions: " << setw(20) << left << compare1 << "  |  " << compare2 << endl;
            }
        }
        else
            return -1;
        return 1;
    }
    else
    {
        cout << "Nhap sai vui long nhap lai !!!" << endl;
        return -1;
    }
}