#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


bool quick_sort(item* begin, const item* end)
{
	if (begin == NULL || end == NULL || begin > end) return false;

	if (end - begin <= 1) return true;

	int pivot = begin[(end - begin) / 2].key;

	item* left = begin;
	item* right = (item*)end - 1;
	while (left <= right)
	{
		while (left->key < pivot) left++;
		while (right->key > pivot) right--;

		if (left <= right)
		{
			item tmp = *left;
			*left = *right;
			*right = tmp;
			left++;
			right--;
		}
	}

	quick_sort(begin, right + 1);
	quick_sort(left, end);

	return true;
}
