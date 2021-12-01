#include"Header.h"
using namespace std;

int selectionSort(int Array[], int size, uint64_t& compare)
{
	int i, j, min_index;
	compare = 0;

	//duyet mang
	for (i = 0; ++compare && i < size - 1; i++)
	{

		// tim phan tu be nhat trong mang chua duoc sap xep
		min_index = i;
		for (j = i + 1; ++compare && j < size; j++) {
			// dem if o phia duoi
			if (++compare && Array[j] < Array[min_index]) {
				min_index = j;
			}
		}

		// doi phan tu min voi phan tu dau cua mang
		HoanVi(Array[min_index], Array[i]);
	}

	return 1;
}

int insertionSort(int Array[], int size, uint64_t& compare)
{
	compare = 0;

	int i, key, j;

	for (i = 1; ++compare && i < size; i++)
	{

		key = Array[i];
		j = i - 1;

		/* di chuyen phan tu trong khoang 0 den i-1
		neu phan tu do lon hon key thi dich no len vi tri phia
		truoc mot don vi*/
		while (++compare && j >= 0 && ++compare && Array[j] > key)
		{

			Array[j + 1] = Array[j];
			j = j - 1;
		}
		Array[j + 1] = key;
	}

	return 1;
}

int bubbleSort(int Array[], int size, uint64_t& compare)
{

	compare = 0;

	for (int i = 0; ++compare && i < size - 1; i++)   // vong lap size-1 lan
	{
		for (int j = size - 1; ++compare && j > i; j--)  // vong lap chay tu cuoi len
		{
			if (++compare && Array[j] < Array[j - 1])  // neu so cuoi < so truoc no  thi doi cho 2 so
			{
				HoanVi(Array[j], Array[j - 1]); // ham doi vi tri
			}

		}
	}

	return 1;
}

int shakerSort(int Array[], int size, uint64_t& compare) //tham khao mang
{

	compare = 0; // bien dem phep so sanh

	int Left = 0; // head
	int Right = size - 1; // tail
	int k = 0; // linh canh

	while (++compare&& Left < Right)  // neu vi tri dau va vi tri cuoi khac nhau
	{
		for (int i = Left; ++compare && i < Right; i++)  // bat dau tu vi tri ben trai
		{
			if (++compare && Array[i] > Array[i + 1])    // neu phan tu o ben trai > phan tu sau no
			{
				HoanVi(Array[i], Array[i + 1]); // doi gia tri 
				k = i; //  dat vi tri ma nhung so sau no khong can sap xep lai
			}

		}
		Right = k; // dat lai vi tri right 
		for (int i = Right; ++compare && i > Left; i--) // bat dau tu vi tri phai
		{
			if (++compare&& Array[i] < Array[i - 1])  // neu phan tu o ben phải < phan tu truoc no
			{
				HoanVi(Array[i], Array[i - 1]); // doi gia tri
				k = i; // dat vi tri ma nhung so truoc no khong can sap xep lai
			}

		}
		Left = k; //dat lai vi tri right
	}

	return 1;
}

int shellSort(int Array[], int size, uint64_t& compare) // tham khao mang
{


	compare = 0;// bien dem phep so sanh

	int interval, i, j, temp; // intevel: bien khoang canh
	for (interval = size / 2; ++compare && interval > 0; interval /= 2) //vong lap voi so lan log2(size)
	{
		for (i = interval; ++compare && i < size; i++)
		{
			temp = Array[i]; // gan phan tu linh canh
			for (j = i; ++compare && j >= interval && ++compare && Array[j - interval] > temp; j -= interval)   //  xet xem co phan tu o phia truoc cach temp 1 khoang = interval, neu co so sanh phan tu do vơi temp,neu phan tu > temp thi thuc hien doi cho o (1),(2) 
			{
				Array[j] = Array[j - interval]; //(1)
			}
			Array[j] = temp; //(2)
		}
	}


	return 1;
}

//Quick Sort// low=0 high = size -1
int partition(int arr[], int left, int pivot, int right, uint64_t& compare) {
	int split = left + 1, tmp;

	for (int track = left + 1; ++compare && track < right; track++) {
		if (++compare && arr[track] < pivot) {

			HoanVi(arr[track], arr[split]);
			split++;
		}

	}


	HoanVi(arr[split - 1], arr[left]);
	return split - 1;
}

int quickSort(int arr[], int left, int right, uint64_t& compare) {

	if (++compare && right <= left)
		return 0;


	int mid = (right + left - 1) / 2;

	HoanVi(arr[mid], arr[left]);
	int split = partition(arr, left, arr[mid], right, compare);

	quickSort(arr, left, split, compare);
	quickSort(arr, split + 1, right, compare);
	return 1;
}

//Merge Sort (có hai hàm , hàm chính là hàm Mergesort, khi chạy trong main chỉ cần chạy hàm này)
void merge(int Array[], int const left, int const mid, int const right, uint64_t& compare)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Tạo mảng tạm
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Sao chép dữ liệu sang mảng tạm left và right
	for (auto i = 0; ++compare && i < subArrayOne; i++)
		leftArray[i] = Array[left + i];
	for (auto j = 0; ++compare && j < subArrayTwo; j++)
		rightArray[j] = Array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Khởi tạo chỉ số của mảng phụ thứ nhất
		indexOfSubArrayTwo = 0; // Khởi tạo chỉ số của mảng phụ thứ hai
	int indexOfMergedArray = left; // Khởi tạo chỉ số của mảng gộp

	// Gộp mảng tạm trở lại mảng chính
	while ((++compare && (indexOfSubArrayOne < subArrayOne)) && (++compare && (indexOfSubArrayTwo < subArrayTwo))) {
		if (++compare && leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			Array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			Array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Sao chép các phần tử còn lại vào left[] nếu còn
	while (++compare && indexOfSubArrayOne < subArrayOne) {
		Array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Sao chép các phần tử còn lại vào right[] nếu còn
	while (++compare && indexOfSubArrayTwo < subArrayTwo) {
		Array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

void mergeSort(int Array[], int const begin, int const end, uint64_t& compare)//Hàm chính của thuật toán sắp xếp
{

	if (++compare && begin >= end)
		return; // Trả về đệ quy

	auto mid = begin + (end - begin) / 2;
	mergeSort(Array, begin, mid, compare);
	mergeSort(Array, mid + 1, end, compare);
	merge(Array, begin, mid, end, compare);


}

//HeapSort ( có hai hàm , hàm chính là heapsort, khi chạy chỉ cần chạy hàm này)
void heapify(int Array[], int n, int i, uint64_t& compare)
{
	int largest = i; // Khởi tạo phần tử lớn nhất làm gốc
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// So sánh nếu cây con bên trái lớn hơn gốc
	if (++compare && l < n && ++compare && Array[l] > Array[largest])
	{
		largest = l;
	}

	// So sánh nếu cây con bên phải lớn hơn gốc
	if (++compare && r < n && ++compare && Array[r] > Array[largest])
	{
		largest = r;
	}


	// So sánh nếu phần tử lớn hơn 
	if (++compare && largest != i) {
		HoanVi(Array[i], Array[largest]);

		// Gọi đệ quy lại hàm vun đống
		heapify(Array, n, largest, compare);
	}

}

int heapSort(int Array[], int n, uint64_t& compare)//Hàm chính thực hiện giải thuật HeapSort (khi chạy chỉ cần chạy hàm này)
{

	compare = 0;//reset biến đếm
	// Xây dựng heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(Array, n, i, compare);

	for (int i = n - 1; i > 0; i--) {
		// Di chuyển gốc hiện tại đến vị trí kết thúc
		HoanVi(Array[0], Array[i]);

		//Gọi đệ quy lại
		heapify(Array, i, 0, compare);
	}

	return 1;
}

// counting sort
void CountSort(int a[], int n, uint64_t& compare) {

	compare = 0; // dem ss là 0
	int* output = new int[n];
	//int output[n]; // in ra
	int* count = new int[n];
	//int count[n]; // khai báo dem
	int max = a[0]; // khai bao lon nhat la 0
	for (int i = 1; ++compare && i < n; i++) {
		if (a[i] > max) // so sanh voi max
			max = a[i]; // gan
	}
	for (int i = 0; ++compare && i <= max; ++i) {
		count[i] = 0; // cho dem là dau tien
	}
	for (int i = 0; ++compare && i < n; i++) {
		count[a[i]]++; // tang dem
	}
	for (int i = 1; ++compare && i <= max; i++) {
		count[i] += count[i - 1]; // giam dem
	}
	for (int i = n - 1; ++compare && i >= 0; i--) {
		output[count[a[i]] - 1] = a[i]; // in ra kq
		count[a[i]]--; // giam dan dem
	}
	for (int i = 0; ++compare && i < n; i++) {
		a[i] = output[i];// in ra 
	}

	delete[] output;
	delete[] count;

}

// radix sort
int Max(int a[], int n) {

	int max = a[0]; // max là a0
	for (int i = 1; i < n; i++)
		if (a[i] > max) // so sanh
			max = a[i]; // gan

	return max; // tra ve lon nhat
}

void RadixSort(int a[], int n, uint64_t& compare) {

	compare = 0;
	int** bucket = new int* [10];
	for (int i = 0; ++compare && i < 10; i++)
	{
		bucket[i] = new int[n];
	}
	int bucket_cnt[10]; // khai báo 
	int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
	lar = Max(a, n); // lar là ptu lon nhat cua mang
	while (++compare && lar > 0) {
		NOP++;
		lar /= 10; // tìm kiêm các ptu
	}
	for (pass = 0; ++compare && pass < NOP; pass++) {
		for (i = 0; ++compare && i < 10; i++) {
			bucket_cnt[i] = 0; // cho ve 0
		}
		for (i = 0; ++compare && i < n; i++) {
			r = (a[i] / divisor) % 10; // tim các ptu con lai
			bucket[r][bucket_cnt[r]] = a[i]; // 
			bucket_cnt[r] += 1; // tang len tìm kiem
			   //++compare; 
		}
		i = 0;
		for (k = 0; ++compare && k < 10; k++) {
			for (j = 0; ++compare && j < bucket_cnt[k]; j++) { // tìm kiem phtu ke tiep
				a[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10; // tra ve
	}
	for (int i = 0; ++compare && i < 10; i++)
		delete[] bucket[i];
	delete[] bucket;

}

// flash sort
void FlashSort(int a[], int n, uint64_t& compare)
{
	int* __L = new int[300000];

	compare = 0;
	if (++compare && n <= 1)
		return; // n phai lon hon 1
	int m = n * 0.43;

	if (++compare && m <= 2) m = 2;

	for (int i = 0; ++compare && i < m; ++i)
		__L[i] = 0; // cho bang 0
	int Mx = a[0], Mn = a[0];
	for (int i = 1; ++compare && i < n; ++i) {
		if (++compare && Mx < a[i]) Mx = a[i];  // kiem tra gia trj a 
		if (++compare && Mn > a[i]) Mn = a[i];
	}
	if (++compare && Mx == Mn)
		return;

#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
	for (int i = 0; ++compare && i < n; ++i)
		++__L[getK(a[i])]; // tang lên ptu tiep 
	for (int i = 1; ++compare && i < m; ++i)
		__L[i] += __L[i - 1]; // gan bang phtu tiep theo ngay sau
	int count = 0;
	int i = 0;
	while (++compare && count < n) { // count luon lon hon n , 
		int k = getK(a[i]);
		while (++compare && i >= __L[k])
			k = getK(a[++i]);
		int z = a[i];
		while (++compare && i != __L[k]) { // khac phtu cung dung
			k = getK(z);
			int y = a[__L[k] - 1];
			a[--__L[k]] = z;
			z = y; // gan
			++count; // tang dan phtu
		}
	}
	for (int k = 1; ++compare && k < m; ++k) {
		for (int i = __L[k] - 2; ++compare && i >= __L[k - 1]; --i)
			if (++compare && a[i] > a[i + 1]) { //  kiem tra hai ptu canh nhau
				int t = a[i], j = i;
				while (++compare && t > a[j + 1]) { a[j] = a[j + 1]; ++j; }
				a[j] = t; // doi neu k phu hop 
			}
	}

	delete[] __L;
}

// sort khong compare
int selectionSort1(int Array[], int size)
{
	int i, j, min_index;


	//duyet mang
	for (i = 0; i < size - 1; i++)
	{

		// tim phan tu be nhat trong mang chua duoc sap xep
		min_index = i;
		for (j = i + 1; j < size; j++) {
			// dem if o phia duoi
			if (Array[j] < Array[min_index]) {
				min_index = j;
			}
		}

		// doi phan tu min voi phan tu dau cua mang
		HoanVi(Array[min_index], Array[i]);
	}

	return 1;
}

int insertionSort1(int Array[], int size)
{

	int i, key, j;

	for (i = 1; i < size; i++)
	{

		key = Array[i];
		j = i - 1;

		/* di chuyen phan tu trong khoang 0 den i-1
		neu phan tu do lon hon key thi dich no len vi tri phia
		truoc mot don vi*/
		while (j >= 0 && Array[j] > key)
		{

			Array[j + 1] = Array[j];
			j = j - 1;
		}
		Array[j + 1] = key;
	}

	return 1;
}

int bubbleSort1(int Array[], int size)
{

	for (int i = 0; i < size - 1; i++)   // vong lap size-1 lan
	{
		for (int j = size - 1; j > i; j--)  // vong lap chay tu cuoi len
		{
			if (Array[j] < Array[j - 1])  // neu so cuoi < so truoc no  thi doi cho 2 so
			{
				HoanVi(Array[j], Array[j - 1]); // ham doi vi tri
			}

		}
	}

	return 1;
}

int shakerSort1(int Array[], int size) //tham khao mang
{
	int Left = 0; // head
	int Right = size - 1; // tail
	int k = 0; // linh canh

	while (Left < Right)  // neu vi tri dau va vi tri cuoi khac nhau
	{
		for (int i = Left; i < Right; i++)  // bat dau tu vi tri ben trai
		{
			if (Array[i] > Array[i + 1])    // neu phan tu o ben trai > phan tu sau no
			{
				HoanVi(Array[i], Array[i + 1]); // doi gia tri 
				k = i; //  dat vi tri ma nhung so sau no khong can sap xep lai
			}

		}
		Right = k; // dat lai vi tri right 
		for (int i = Right; i > Left; i--) // bat dau tu vi tri phai
		{
			if (Array[i] < Array[i - 1])  // neu phan tu o ben phải < phan tu truoc no
			{
				HoanVi(Array[i], Array[i - 1]); // doi gia tri
				k = i; // dat vi tri ma nhung so truoc no khong can sap xep lai
			}

		}
		Left = k; //dat lai vi tri right
	}

	return 1;
}

int shellSort1(int Array[], int size) // tham khao mang
{

	int interval, i, j, temp; // intevel: bien khoang canh
	for (interval = size / 2; interval > 0; interval /= 2) //vong lap voi so lan log2(size)
	{
		for (i = interval; i < size; i++)
		{
			temp = Array[i]; // gan phan tu linh canh
			for (j = i; j >= interval && Array[j - interval] > temp; j -= interval)   //  xet xem co phan tu o phia truoc cach temp 1 khoang = interval, neu co so sanh phan tu do vơi temp,neu phan tu > temp thi thuc hien doi cho o (1),(2) 
			{
				Array[j] = Array[j - interval]; //(1)
			}
			Array[j] = temp; //(2)
		}
	}


	return 1;
}

int partition1(int arr[], int left, int pivot, int right)
{
	int split = left + 1, tmp;

	for (int track = left + 1; track < right; track++) {
		if (arr[track] < pivot) {
			HoanVi(arr[track], arr[split]);
			split++;
		}

	}

	HoanVi(arr[split - 1], arr[left]);
	return split - 1;
}

int quickSort1(int arr[], int left, int right) {

	if (right <= left)
		return 0;


	int mid = (right + left - 1) / 2;
	HoanVi(arr[mid], arr[left]);
	int split = partition1(arr, left, arr[mid], right);

	quickSort1(arr, left, split);
	quickSort1(arr, split + 1, right);
	return 1;
}

void merge1(int Array[], int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Tạo mảng tạm
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Sao chép dữ liệu sang mảng tạm left và right
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = Array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = Array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Khởi tạo chỉ số của mảng phụ thứ nhất
		indexOfSubArrayTwo = 0; // Khởi tạo chỉ số của mảng phụ thứ hai
	int indexOfMergedArray = left; // Khởi tạo chỉ số của mảng gộp

	// Gộp mảng tạm trở lại mảng chính
	while (((indexOfSubArrayOne < subArrayOne)) && ((indexOfSubArrayTwo < subArrayTwo))) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			Array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			Array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Sao chép các phần tử còn lại vào left[] nếu còn
	while (indexOfSubArrayOne < subArrayOne) {
		Array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Sao chép các phần tử còn lại vào right[] nếu còn
	while (indexOfSubArrayTwo < subArrayTwo) {
		Array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

void mergeSort1(int Array[], int const begin, int const end)//Hàm chính của thuật toán sắp xếp
{

	if (begin >= end)
		return; // Trả về đệ quy

	auto mid = begin + (end - begin) / 2;
	mergeSort1(Array, begin, mid);
	mergeSort1(Array, mid + 1, end);
	merge1(Array, begin, mid, end);


}

void heapify1(int Array[], int n, int i)
{
	int largest = i; // Khởi tạo phần tử lớn nhất làm gốc
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// So sánh nếu cây con bên trái lớn hơn gốc
	if (l < n && Array[l] > Array[largest])
	{
		largest = l;
	}

	// So sánh nếu cây con bên phải lớn hơn gốc
	if (r < n && Array[r] > Array[largest])
	{
		largest = r;
	}


	// So sánh nếu phần tử lớn hơn 
	if (largest != i) {
		HoanVi(Array[i], Array[largest]);

		// Gọi đệ quy lại hàm vun đống
		heapify1(Array, n, largest);
	}

}

int heapSort1(int Array[], int n)//Hàm chính thực hiện giải thuật HeapSort (khi chạy chỉ cần chạy hàm này)
{


	// Xây dựng heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify1(Array, n, i);

	for (int i = n - 1; i > 0; i--) {
		// Di chuyển gốc hiện tại đến vị trí kết thúc
		HoanVi(Array[0], Array[i]);

		//Gọi đệ quy lại
		heapify1(Array, i, 0);
	}

	return 1;
}

void CountSort1(int a[], int n) {


	int* output = new int[n];
	//int output[n]; // in ra
	int* count = new int[n];
	//int count[n]; // khai báo dem
	int max = a[0]; // khai bao lon nhat la 0
	for (int i = 1; i < n; i++) {
		if (a[i] > max) // so sanh voi max
			max = a[i]; // gan
	}
	for (int i = 0; i <= max; ++i) {
		count[i] = 0; // cho dem là dau tien
	}
	for (int i = 0; i < n; i++) {
		count[a[i]]++; // tang dem
	}
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1]; // giam dem
	}
	for (int i = n - 1; i >= 0; i--) {
		output[count[a[i]] - 1] = a[i]; // in ra kq
		count[a[i]]--; // giam dan dem
	}
	for (int i = 0; i < n; i++) {
		a[i] = output[i];// in ra 
	}

	delete[] output;
	delete[] count;

}

int Max1(int a[], int n) {

	int max = a[0]; // max là a0
	for (int i = 1; i < n; i++)
		if (a[i] > max) // so sanh
			max = a[i]; // gan

	return max; // tra ve lon nhat
}

void RadixSort1(int a[], int n) {

	int** bucket = new int* [10];
	for (int i = 0; i < 10; i++)
	{
		bucket[i] = new int[n];
	}
	int bucket_cnt[10]; // khai báo 
	int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
	lar = Max1(a, n); // lar là ptu lon nhat cua mang
	while (lar > 0) {
		NOP++;
		lar /= 10; // tìm kiêm các ptu
	}
	for (pass = 0; pass < NOP; pass++) {
		for (i = 0; i < 10; i++) {
			bucket_cnt[i] = 0; // cho ve 0
		}
		for (i = 0; i < n; i++) {
			r = (a[i] / divisor) % 10; // tim các ptu con lai
			bucket[r][bucket_cnt[r]] = a[i]; // 
			bucket_cnt[r] += 1; // tang len tìm kiem
			   //++compare; 
		}
		i = 0;
		for (k = 0; k < 10; k++) {
			for (j = 0; j < bucket_cnt[k]; j++) { // tìm kiem phtu ke tiep
				a[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10; // tra ve
	}
	for (int i = 0; i < 10; i++)
		delete[] bucket[i];
	delete[] bucket;

}

void FlashSort1(int a[], int n)
{
	int* __L = new int[300000];

	if (n <= 1)
		return; // n phai lon hon 1
	int m = n * 0.43;

	if (m <= 2) m = 2;

	for (int i = 0; i < m; ++i)
		__L[i] = 0; // cho bang 0
	int Mx = a[0], Mn = a[0];
	for (int i = 1; i < n; ++i) {
		if (Mx < a[i]) Mx = a[i];  // kiem tra gia trj a 
		if (Mn > a[i]) Mn = a[i];
	}
	if (Mx == Mn)
		return;

#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
	for (int i = 0; i < n; ++i)
		++__L[getK(a[i])]; // tang lên ptu tiep 
	for (int i = 1; i < m; ++i)
		__L[i] += __L[i - 1]; // gan bang phtu tiep theo ngay sau
	int count = 0;
	int i = 0;
	while (count < n) { // count luon lon hon n , 
		int k = getK(a[i]);
		while (i >= __L[k])
			k = getK(a[++i]);
		int z = a[i];
		while (i != __L[k]) { // khac phtu cung dung
			k = getK(z);
			int y = a[__L[k] - 1];
			a[--__L[k]] = z;
			z = y; // gan
			++count; // tang dan phtu
		}
	}
	for (int k = 1; k < m; ++k) {
		for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
			if (a[i] > a[i + 1]) { //  kiem tra hai ptu canh nhau
				int t = a[i], j = i;
				while (t > a[j + 1]) { a[j] = a[j + 1]; ++j; }
				a[j] = t; // doi neu k phu hop 
			}
	}

	delete[] __L;
}
