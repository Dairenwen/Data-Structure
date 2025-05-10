#include"Sort.h"
#include"Stack.h"
#include"Queue.h"
//最坏：o(N^2);
//最好：o(N);
void InsertSort(int arr[], int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int youxu = i;
		int tmp = arr[youxu + 1];
		while (youxu >= 0)
		{
			//一直找到小于youxu为止
			if (tmp < arr[youxu])
			{
				arr[youxu + 1] = arr[youxu];
				youxu--;
			}
			else
			{
				break;
			}
		}
		arr[youxu + 1] = tmp;
	}
}

void ShellSort(int* arr, int n)
{
	int gap = n;
	//gap可以改变，不停变化，本质还是插入
	while (gap > 1)
	{
		gap /= 2;
		int j = 0;
		for (j = 0; j < gap; j++)
		{
			int i = 0;
			for (i = j; i < n - gap; i += gap)
			{
				int youxu = i;
				int tmp = arr[youxu + gap];
				while (youxu >= 0)
				{
					if (tmp < arr[youxu])
					{
						arr[youxu + gap] = arr[youxu];
						youxu -= gap;
					}
					else
					{
						break;
					}
				}
				arr[youxu + gap] = tmp;
			}
		}
		//或者
		/*int i = 0;
		for (i = j; i < n - gap; i++)
		{
			int youxu = i;
			int tmp = arr[youxu + gap];
			while (youxu >= 0)
			{
				if (tmp < arr[youxu])
				{
					arr[youxu + gap] = arr[youxu];
					youxu -= gap;
				}
				else
				{
					break;
				}
			}
			arr[youxu + gap] = tmp;
		}*/
	}
}
//最坏：oN^2
//最好：oN^2
void SelectSort1(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int min = i;
		int j = 0;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
		}
	}
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort2(int* arr, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int min = left;
		int max = left;
		int i = 0;
		for (i = left + 1; i <= right; i++)
		{
			if (arr[i] > arr[max])
			{
				max = i;
			}
			if (arr[i] < arr[min])
			{
				min = i;
			}
		}
		swap(&arr[left], &arr[min]);
		if (max == left)
		{
			max = min;
		}
		swap(&arr[right], &arr[max]);
		left++;
		right--;
	}
}
void AdjustUp(int* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(int* arr, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//最坏：o（nlogn）
void HeapSort(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		AdjustUp(arr, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		//将最大值与最后一个交换一下，end--，继续排前面的元素
		swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}

//最坏on^2
//最好on
void BubbleSort(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int j = 0;
		bool judge = false;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
				judge = true;
			}
		}
		if (judge == false)
		{
			break;
		}
	}
}
int GetMidNumi(int* arr, int left, int right)
{
	int mid = (left + right) / 2;
	if (arr[mid] > arr[left])
	{
		if (arr[right] > arr[mid])
		{
			return mid;
		}
		else if (arr[right] < arr[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (arr[right] < arr[mid])
		{
			return mid;
		}
		else if (arr[left] < arr[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//这里其实是两路划分，当数组接近有序时，就会退化成n方
void QuickSort1(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int begin = left;
	int end = right;
	//随机数取数
	/*int randi = left + (rand() % (right - left));
	swap(&arr[randi], &arr[left]);*/
	//三路取中
	int midi = GetMidNumi(arr, left, right);
	swap(&arr[midi], &arr[left]);
	int key = left;
	while (left < right)
	{
		//左边做key让右边先走，相遇位置比key要小，或者就是key的位置
		//右边做key让左边先走，相遇位置比key要大
		while (left < right && arr[right] >= arr[key])
		{
			right--;
		}
		while (left < right && arr[left] <= arr[key])
		{
			left++;
		}
		swap(&arr[right], &arr[left]);
	}
	swap(&arr[key], &arr[left]);
	key = left;
	QuickSort1(arr, begin, key - 1);
	QuickSort1(arr, key + 1, end);
}
//挖坑法：将key设为坑，找到值后将数丢到坑里
void QuickSort2(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int begin = left;
	int end = right;
	int hole = left;
	int key = arr[left];
	while (left < right)
	{
		//左边做key让右边先走，相遇位置比key要小，或者就是key的位置
		//右边做key让左边先走，相遇位置比key要大
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		arr[hole] = arr[right];
		hole = right;
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[hole] = arr[left];
		hole = left;
	}
	arr[hole] = key;
	key = left;
	QuickSort2(arr, begin, key - 1);
	QuickSort2(arr, key + 1, end);
}
//前后指针版本的快速排序
void QuickSort3(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int begin = left;
	int end = right;
	int prev = left;
	int cur = left + 1;
	int key = left;
	while (cur <= right)
	{
		if (cur <= right && arr[cur] < arr[key])
		{
			//找到比key小的就先让prev往前走，再交换，cur最后++
			prev++;
			swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	swap(&arr[key], &arr[prev]);
	key = prev;
	QuickSort3(arr, begin, key - 1);
	QuickSort3(arr, key + 1, end);
}

//对快速排序进行小区间优化
void QuickSort4(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if (right - left + 1 > 5)
	{
		int begin = left;
		int end = right;
		int key = left;
		while (left < right)
		{

			while (left < right && arr[right] >= arr[key])
			{
				right--;
			}
			while (left < right && arr[left] <= arr[key])
			{
				left++;
			}
			swap(&arr[right], &arr[left]);
		}
		swap(&arr[key], &arr[left]);
		key = left;
		QuickSort1(arr, begin, key - 1);
		QuickSort1(arr, key + 1, end);
	}
	else
	{
		InsertSort(arr + left, right - left + 1);
	}
	//但其实这样的优化影响没有非常大，并且对冒泡排序进行优化并不会影响它的时间复杂度
}
//三路划分，大大提高快排的效率
void QuickSort5(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int begin = left;
	int end = right;
	int key = arr[left];
	int cur = left + 1;
	while (cur <= right)
	{
		if (arr[cur] < key)
		{
			swap(&arr[cur], &arr[left]);
			left++;
			cur++;
		}
		else if (arr[cur] == key)
		{
			cur++;
		}
		else
		{
			swap(&arr[right], &arr[cur]);
			right--;
		}
	}
	QuickSort5(arr, begin, left - 1);
	QuickSort5(arr, left + 1, end);
}
int GetKey(int* arr, int left, int right)
{
	int begin = left;
	int end = right;
	int key = left;
	while (left < right)
	{
		if (left < right && arr[right] >= arr[key])
		{
			right--;
		}
		if (left < right && arr[left] <= arr[key])
		{
			left++;
		}
		swap(&arr[right], &arr[left]);
	}
	swap(&arr[key], &arr[left]);
	key = left;
	return key;
}
void QuickSortNonR(int* arr, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int key = GetKey(arr, begin, end);
		//在获得key的时候其实就在排序
		if (key + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, key + 1);
		}
		if (begin < key - 1)
		{
			StackPush(&st, key - 1);
			StackPush(&st, begin);
		}
	}
	StackDestroy(&st);
}

void _MergeSort(int* arr, int left,int right,int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	//类似于后序遍历
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[i++] = arr[begin1++];
		}
		else if (arr[begin1] > arr[begin2])
		{
			tmp[i++] = arr[begin2++];
		}
		else
		{
			tmp[i++] = arr[begin1++];
			tmp[i++] = arr[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}
	memcpy(arr + left, tmp + left, sizeof(int) * (right - left + 1));
}
//N*logN
void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc failed");
		return;
	}
	_MergeSort(arr, 0, n - 1,tmp);
	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc failed");
		return; 
	}
	int gap = 1;
	while (gap < n)
	{
		int i = 0;
		for (i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			int j = i;
			//画图理解，边界值的处理
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (arr[begin1] < arr[begin2])
				{
					tmp[j++] = arr[begin1++];
				}
				else if (arr[begin1] > arr[begin2])
				{
					tmp[j++] = arr[begin2++];
				}
				else
				{
					tmp[j++] = arr[begin1++];
					tmp[j++] = arr[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = arr[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = arr[begin2++];
			}
			memcpy(arr + i , tmp + i, sizeof(int) * (end2-i+1));
			//这里排完数据就拷贝，不要到时候一把梭哈
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}

void CountSort(int* arr, int n)
{
	int max = arr[0];
	int min = arr[0];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	int range = max - min + 1;
	int* countA = (int*)calloc(1,sizeof(int) * (range));
	if (countA == NULL)
	{
		perror("malloc failed");
		return;
	}
	for (i = 0; i < n; i++)
	{
		countA[(arr[i] - min)]++;
	}
	int j = 0;
	for (i = 0; i < range; i++)
	{
		while (countA[i] > 0)
		{
			arr[j++] = i + min;
			countA[i]--;
		}
	}
	free(countA);
	countA = NULL;
}

int Getkey(int num, int index)
{
	int ret = 0;
	while (index > 0)
	{
		ret = num % 10;
		num /= 10;
		index--;
	}
	return ret;
}
void Collect(Queue* quarr, int* arr, int index, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int judge = Getkey(arr[i], index);
		QueuePush(&(quarr[judge]), arr[i]);
	}
}
void Destribute(Queue* quarr, int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		int put = 0;
		for (j = 0; j < 10; j++)
		{
			if (!QueueEmpty(&quarr[j]))
			{
				put = QueueFront(&quarr[j]);
				QueuePop(&quarr[j]);
				break;
			}
		}
		arr[i] = put;
	}
}
//基数排序，按个位十位百位分别入队列，出队列循环排序
void RadixSort(int* arr, int n)
{
	Queue quarr[10];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		QueueInit(&quarr[i]);
	}
	for (i = 1; i <= 3; i++)
	{
		Collect(quarr, arr, i, n);//统计数据，分别入队列
		Destribute(quarr, arr, n);//按照队列标号从小到大依次出队列，直到队列为空
	}
	for (i = 0; i < 10; i++)
	{
		QueueDestroy(&quarr[i]);
	}
}

//文件排序仅作了解，理解即可！：

void _MergeFile(const char* file1, const char* file2, const char* mfile)
{//把两个小文件归并为一个文件(mfile)，因为已知这两个小文件是有序的，所以才可以归并
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);//fscanf返回值是所读入的数据个数或EOF，即返回值为整形
	int ret2 = fscanf(fout2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{//如果两个中有一个文件读完了，则循环终止

		//谁小就先写入mfile文件中
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d\n", &num1);//如果是小的需再读一次
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}
	//看两个文件中哪个文件中还有数据，就写入fin文件中
	// 但下面的代码不行，假设上面ret1读到EOF了，ret2可能就是一个数
	// 然后你又fscanf读了一次放入num1（2）中，这就导致原来ret1和ret2
	// 中保存的数据丢失了，所以还要用ret1和ret2继续实现
	//while (fscanf(fout1, "%d\n", &num1) != EOF)
	//{ fscanf返回值为0时，表示未成功匹配到任何数据项
	//  返回值为-1时，表示在读取过程中出现了错误
	//  返回值为正整数：表示成功匹配并读取的数据项数
	//	fprintf(fin, "%d\n", num1);
	//}
	//while (fscanf(fout2, "%d\n", &num2) != EOF)
	//{
	//	fprintf(fin, "%d\n", num2);
	//}
	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}
	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}
	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}

//假设要排序的文件中都是一行放一个数据
//内存中排好序并放入文件
void MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	//分割成一段一段数据，内存排序后写到小文件中
	int n = 10;//切10份
	int a[10];//每份都10个数据
	int i = 0;
	int num = 0;
	char subfile[20];//文件名
	int filei = 1;//假设从第一个文件开始
	while (fscanf(fout, "%d\n", &num) != EOF)
	{
		if (i < n - 1)
		{//如果写为i<n，确实读了n(10)个数据，但是最后读完了还要一次while循环
		//fscanf又读了一次，放入num，可是此时直接开始排序了，排完i=0了，然后又while
		//循环一次，放入num中，可之前那个num你还没用，就又读了一个，导致数据丢失
		//故这里用i<n-1，先读n-1(9)个数据，然后走else把读到的num给a[i]，然后排序完
		//i再置为0再完成下一个文件的，这里就符合了
			a[i++] = num;
		}
		else
		{
			a[i] = num;
			//读满了10个数据
			QuickSort1(a, 0, n - 1);//快速排序，自己写的函数，只要能排成升序即可
			sprintf(subfile, "%d", filei++);//输出文件名到subfile
			FILE* fin = fopen(subfile, "w");
			if (fin == NULL)
			{
				perror("fopen");
				exit(-1);
			}
			for (int i = 0; i < n; i++)
			{
				fprintf(fin, "%d\n", a[i]);
			}
			fclose(fin);
			i = 0;//i=0，以便写入下一个文件
		}
	}

	//利用互相归并到文件，实现整体有序
	char mfile[100] = "12";//归并出的文件
	char file1[100] = "1";
	char file2[100] = "2";
	//要归并n个文件
	for (int i = 2; i <= n; i++)
	{

		//读取file1和file2，进行归并出mfile
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);//将mfile文件名拷贝给file1，以便下一次的归并
		sprintf(file2, "%d", i + 1);//同时file2文件名向后一位
		sprintf(mfile, "%s%d", mfile, i + 1);//赋予新的文件名
	}
	fclose(fout);
}