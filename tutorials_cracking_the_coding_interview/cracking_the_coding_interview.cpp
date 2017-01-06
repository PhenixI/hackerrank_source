//1. Arrays:Left Rotation
//A left rotation operation on an array of size shifts each of the array's elements unit to the left. 

/*Sample Input

5 4
1 2 3 4 5

Sample Output

5 1 2 3 4*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void rotate(int* a, int start, int end)
{
	int i = start, j = end;
	int tmp;
	while (i < j){
		tmp = a[j];
		a[j] = a[i];
		a[i] = tmp;
		i++;
		j--;
	}
}

int main_rotation(){
	int n;
	int k;
	scanf("%d %d", &n, &k);
	int *a = (int*)malloc(sizeof(int) * n);
	for (int a_i = 0; a_i < n; a_i++){
		scanf("%d", &a[a_i]);
	}
	rotate(a, 0, k - 1);
	rotate(a, k, n - 1);
	rotate(a, 0, n - 1);

	for (int a_i = 0; a_i < n; a_i++){
		printf("%d ", a[a_i]);
	}
	return 0;
}

//2. Strings: Making anagrams
/*Given two strings, and, that may or may not be of the same length, determine the minimum number of 
character deletions required to make and anagrams.Any characters can be deleted from either of the strings.*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void hist(char* a, int *hista){
	int s_len = strlen(a);
	int i = 0;
	for (i = 0; i < s_len; i++){
		hista[a[i] - 'a']++;
	}
}

int main_making_anagrams(){
	int hista[26] = { 0 };
	int histb[26] = { 0 };
	int i = 0;
	int sum = 0;
	char* a = (char *)malloc(512000 * sizeof(char));
	scanf("%s", a);
	hist(a, hista);
	char* b = (char *)malloc(512000 * sizeof(char));
	scanf("%s", b);
	hist(b, histb);

	for (i = 0; i < 26; i++)
	{
		sum += abs(hista[i] - histb[i]);
	}
	printf("%d", sum);
	return 0;
}

//3.Trees: Is This a Binary Search Tree
//Given the root node of a binary tree, can you determine if it's also a binary search tree? 
//The Node struct is defined as follows :
struct Node {
	int data;
	Node* left;
	Node* right;
};

bool check(Node* root, int minValue, int maxValue)
{
	if (root == NULL)
		return true;
	if (root->data <= minValue || root->data >= maxValue)
		return false;
	return check(root->left, minValue, root->data) && check(root->right, root->data, maxValue);
}

bool checkBST(Node* root) {
	return check(root, INT_MIN, INT_MAX);
}
