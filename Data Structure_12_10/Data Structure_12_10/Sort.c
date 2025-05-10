#include"Sort.h"
#include"Stack.h"
#include"Queue.h"
//���o(N^2);
//��ã�o(N);
void InsertSort(int arr[], int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int youxu = i;
		int tmp = arr[youxu + 1];
		while (youxu >= 0)
		{
			//һֱ�ҵ�С��youxuΪֹ
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
	//gap���Ըı䣬��ͣ�仯�����ʻ��ǲ���
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
		//����
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
//���oN^2
//��ã�oN^2
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
//���o��nlogn��
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
		//�����ֵ�����һ������һ�£�end--��������ǰ���Ԫ��
		swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}

//�on^2
//���on
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
//������ʵ����·���֣�������ӽ�����ʱ���ͻ��˻���n��
void QuickSort1(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int begin = left;
	int end = right;
	//�����ȡ��
	/*int randi = left + (rand() % (right - left));
	swap(&arr[randi], &arr[left]);*/
	//��·ȡ��
	int midi = GetMidNumi(arr, left, right);
	swap(&arr[midi], &arr[left]);
	int key = left;
	while (left < right)
	{
		//�����key���ұ����ߣ�����λ�ñ�keyҪС�����߾���key��λ��
		//�ұ���key��������ߣ�����λ�ñ�keyҪ��
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
//�ڿӷ�����key��Ϊ�ӣ��ҵ�ֵ������������
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
		//�����key���ұ����ߣ�����λ�ñ�keyҪС�����߾���key��λ��
		//�ұ���key��������ߣ�����λ�ñ�keyҪ��
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
//ǰ��ָ��汾�Ŀ�������
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
			//�ҵ���keyС�ľ�����prev��ǰ�ߣ��ٽ�����cur���++
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

//�Կ����������С�����Ż�
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
	//����ʵ�������Ż�Ӱ��û�зǳ��󣬲��Ҷ�ð����������Ż�������Ӱ������ʱ�临�Ӷ�
}
//��·���֣������߿��ŵ�Ч��
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
		//�ڻ��key��ʱ����ʵ��������
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
	//�����ں������
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
			//��ͼ��⣬�߽�ֵ�Ĵ���
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
			//�����������ݾͿ�������Ҫ��ʱ��һ�����
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
//�������򣬰���λʮλ��λ�ֱ�����У�������ѭ������
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
		Collect(quarr, arr, i, n);//ͳ�����ݣ��ֱ������
		Destribute(quarr, arr, n);//���ն��б�Ŵ�С�������γ����У�ֱ������Ϊ��
	}
	for (i = 0; i < 10; i++)
	{
		QueueDestroy(&quarr[i]);
	}
}

//�ļ���������˽⣬��⼴�ɣ���

void _MergeFile(const char* file1, const char* file2, const char* mfile)
{//������С�ļ��鲢Ϊһ���ļ�(mfile)����Ϊ��֪������С�ļ�������ģ����Բſ��Թ鲢
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);//fscanf����ֵ������������ݸ�����EOF��������ֵΪ����
	int ret2 = fscanf(fout2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{//�����������һ���ļ������ˣ���ѭ����ֹ

		//˭С����д��mfile�ļ���
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d\n", &num1);//�����С�����ٶ�һ��
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}
	//�������ļ����ĸ��ļ��л������ݣ���д��fin�ļ���
	// ������Ĵ��벻�У���������ret1����EOF�ˣ�ret2���ܾ���һ����
	// Ȼ������fscanf����һ�η���num1��2���У���͵���ԭ��ret1��ret2
	// �б�������ݶ�ʧ�ˣ����Ի�Ҫ��ret1��ret2����ʵ��
	//while (fscanf(fout1, "%d\n", &num1) != EOF)
	//{ fscanf����ֵΪ0ʱ����ʾδ�ɹ�ƥ�䵽�κ�������
	//  ����ֵΪ-1ʱ����ʾ�ڶ�ȡ�����г����˴���
	//  ����ֵΪ����������ʾ�ɹ�ƥ�䲢��ȡ����������
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

//����Ҫ������ļ��ж���һ�з�һ������
//�ڴ����ź��򲢷����ļ�
void MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	//�ָ��һ��һ�����ݣ��ڴ������д��С�ļ���
	int n = 10;//��10��
	int a[10];//ÿ�ݶ�10������
	int i = 0;
	int num = 0;
	char subfile[20];//�ļ���
	int filei = 1;//����ӵ�һ���ļ���ʼ
	while (fscanf(fout, "%d\n", &num) != EOF)
	{
		if (i < n - 1)
		{//���дΪi<n��ȷʵ����n(10)�����ݣ������������˻�Ҫһ��whileѭ��
		//fscanf�ֶ���һ�Σ�����num�����Ǵ�ʱֱ�ӿ�ʼ�����ˣ�����i=0�ˣ�Ȼ����while
		//ѭ��һ�Σ�����num�У���֮ǰ�Ǹ�num�㻹û�ã����ֶ���һ�����������ݶ�ʧ
		//��������i<n-1���ȶ�n-1(9)�����ݣ�Ȼ����else�Ѷ�����num��a[i]��Ȼ��������
		//i����Ϊ0�������һ���ļ��ģ�����ͷ�����
			a[i++] = num;
		}
		else
		{
			a[i] = num;
			//������10������
			QuickSort1(a, 0, n - 1);//���������Լ�д�ĺ�����ֻҪ���ų����򼴿�
			sprintf(subfile, "%d", filei++);//����ļ�����subfile
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
			i = 0;//i=0���Ա�д����һ���ļ�
		}
	}

	//���û���鲢���ļ���ʵ����������
	char mfile[100] = "12";//�鲢�����ļ�
	char file1[100] = "1";
	char file2[100] = "2";
	//Ҫ�鲢n���ļ�
	for (int i = 2; i <= n; i++)
	{

		//��ȡfile1��file2�����й鲢��mfile
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);//��mfile�ļ���������file1���Ա���һ�εĹ鲢
		sprintf(file2, "%d", i + 1);//ͬʱfile2�ļ������һλ
		sprintf(mfile, "%s%d", mfile, i + 1);//�����µ��ļ���
	}
	fclose(fout);
}