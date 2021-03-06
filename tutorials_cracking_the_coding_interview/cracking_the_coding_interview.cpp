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


//Hash Tables: Ransom Note
//Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
	unordered_map<string, int> hashed_magazine;
	for (auto & it : magazine)
		hashed_magazine[it]++;
	for (auto& it : ransom)
	{
		if (hashed_magazine[it] > 0)
			hashed_magazine[it]--;
		else
			return false;
	}
	return true;
}

int main_hashtable(){
	int m;
	int n;
	cin >> m >> n;
	vector<string> magazine(m);
	for (int magazine_i = 0; magazine_i < m; magazine_i++){
		cin >> magazine[magazine_i];
	}
	vector<string> ransom(n);
	for (int ransom_i = 0; ransom_i < n; ransom_i++){
		cin >> ransom[ransom_i];
	}
	if (ransom_note(magazine, ransom))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}

//Tries:Contacts
//We're going to make our own Contacts application! The application must perform two types of operations:

//1.add name, where is a string denoting a contact name.This must store as a new contact in the application.
//2.find partial, where is a string denoting a partial name to search the application for.It must count the number of contacts starting with and print the count on a new line.

//Given sequential add and find operations, perform each operation in order.
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main_Tries(){
	int n;
	cin >> n;
	for (int a0 = 0; a0 < n; a0++){
		string op;
		string contact;
		cin >> op >> contact;
	}
	return 0;
}

//Linked Lists: Detect a Cycle
//A linked list is said to contain a cycle if any node is visited more than once while traversing the list.
//bool has_cycle(Node* head) {
//	if (head == NULL)return false;
//
//	Node *slow = head;
//	Node *fast = head->next;
//	while (slow != fast){
//		if (fast == NULL || fast->next == NULL)return false;
//
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return true;
//}

//Stacks: Balanced Brackets
//Given strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, print YES on a new line; otherwise, print NO on a new line.

bool is_balanced(string expression) {
	stack<char> s;
	for (char c : expression) {
		if (c == '{') s.push('}');
		else if (c == '[') s.push(']');
		else if (c == '(') s.push(')');
		else {
			if (s.empty() || c != s.top())
				return false;
			s.pop();
		}
	}
	return s.empty();
}

int main_stacks(){
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++){
		string expression;
		cin >> expression;
		bool answer = is_balanced(expression);
		if (answer)
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

//Heaps Find the Running Median
/*To prevent timeout the algorithm needs to be run in O(logn).
The solution is using two heaps or two priority queues, 
one max the other min, and always balanced.By balanced, 
it means the difference of the length of each data structure should be less than or equal to 1. 
And the min data structure should store the highest half of the sorted list and the max structure needs to store the lowest of the sorted list.
In this way the insersion will take place in O(logn) and finding the median in O(1) as access time to top element of heap or priority queue is O(1).*/

#include <functional>
priority_queue<int, vector<int>, less<int>> lower = priority_queue<int, vector<int>, less<int>>();
priority_queue<int, vector<int>, greater<int>> higher = priority_queue<int, vector<int>, greater<int>>();

void add(int i){
	if (lower.empty())
		lower.push(i);
	else{
		if (lower.size() > higher.size()){
			if (lower.top() > i){
				higher.push(lower.top());
				lower.pop();
				lower.push(i);
			}
			else
				higher.push(i);
		}
		else{
			if (higher.top() >= i)
				lower.push(i);
			else {
				lower.push(higher.top());
				higher.pop();
				higher.push(i);
			}
		}
	}
}

double find(){
	int n = lower.size() + higher.size();
	return (n % 2 == 0) ? (higher.top() + lower.top()) / 2.0 : (double)(lower.top());
}
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++){
		cin >> a[a_i];
		add(a[a_i]);
		printf("%.1f\n", find());// << endl;
	}
	return 0;
}