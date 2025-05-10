#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<errno.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

void InsertSort(int arr, int n);
void ShellSort(int* arr, int n);
void SelectSort1(int* arr, int n);
void SelectSort2(int* arr, int n);
void HeapSort(int* arr, int n);
void BubbleSort(int* arr, int n);
void QuickSort(int* arr, int left, int right);
void RadixSort(int* arr, int n);
void MergeSortFile();
