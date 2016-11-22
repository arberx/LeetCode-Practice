#include<iostream>
#include<cmath>
#include<deque>
#include<stack>
#include <vector>
#include <string>
#include<unordered_map>


using namespace std;

/*Sum two numbers*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mymap;

		//fill in the map
		for (int i = 0; i < nums.size() - 1; ++i) {
			mymap[nums[i]] = i;
		}

		vector<int> solu;
		int targe;

		for (int i = 0; i < nums.size(); ++i) {
			targe = target - nums[i];
			if (!(mymap.find(targe) == mymap.end()) && (mymap[targe] != i)) {
				int data = mymap[targe];
				solu = { i,data };
				return solu;
			}
		}
		return solu;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//traverse the two lists, adding the numbers and storing them in a new list, if the value is greater than 9, use sum and carry to add to the next integer, if next is null, add to end of new list

		ListNode *dummyHead = new ListNode(0);

		ListNode *p = l1;
		ListNode *q = l2;
		ListNode *curr = dummyHead;

		int carry = 0;
		while (p != nullptr || q != nullptr) {
			int x = (p != nullptr) ? p->val : 0;
			int y = (q != nullptr) ? q->val : 0;
			int sum = carry + x + y;
			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
			if (p != nullptr) p = p->next;
			if (q != nullptr) q = q->next;
		}
		if (carry > 0) {
			curr->next = new ListNode(carry);
		}
		return dummyHead->next;
	}
	/*Sum two numbers*/
};

class MergeSort {

private:
	//merge, pass int, returns sorted vector, p->q, q+1->r, assumes A is already sorted. 
	vector<int> merge(vector<int> A, int p, int q, int r) {
		//create two vectors
		//vector B p->q
		int n1 = q - p + 1;
		int n2 = r - q;
		vector<int> C(n2);
		for (int j = 0; j < n2; ++j) {
			C[j] = A[q+1+j];
		}

		vector<int>B(n1);
		for (int k = 0; k < q+1; ++k) {
			B[k] = A[p+k];
		}

		int j = 0;
		int k = 0;

		//merging the two lists
		for (int i = 0; i < r; ++i) {

			if (B[k] <= C[j]) {
				A[i] = B[k];
				++k;
			}
			else {
				A[i] = C[j];
				++j;
			}
		}//last for loop

		return A;
	}//end merge

public:
	void mergesort(vector<int> &A, int start, int end) {

		if (start < end) {
			int mid = floor((end - start) / 2);
			 mergesort(A, start, mid);
			 mergesort(A, mid + 1, end);
			 merge(A, start, mid, end);
		}

		return;
	}

};

/*TODO*/
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

	}
};


class sum {
public:
	int reverse(int x) {
		string s = to_string(x);
		int rev_num = 0;

		

		//if negative
		if (s[0] == '-') {
			int place = pow(10,s.size()-2)*-1;
			for (int i = s.size() - 1; i >0; --i) {
				int temp = (s[i] - '0')*place;
				rev_num += temp;
				place /= 10;
			}

		}
		else {
			int place = pow(10, s.size() - 1);
			for (int i = s.size() - 1; i >= 0; --i) {
				int temp = (s[i] - '0')*place;
				rev_num += temp;
				place /= 10;
			}
		}

		return rev_num;
	}
};








int main() {
	///*
	//vector<int> i = { 3,2,4 };
	//int target = 6;

	//Solution s;
	////s.twoSum(i, target);

	///*make nodes
	////ListNode *n1 = &ListNode(5);
	////n1->next = &ListNode(4);
	////n1->next->next = &ListNode(3);
	////ListNode *n2 = &ListNode(5);
	////n2->next = &ListNode(6);
	////n2->next->next = &ListNode(4);

	////s.addTwoNumbers(n1, n2);
	//*/

	///*Merge Sort*/
	////vector<int> test = { -1,0,7,3,10,3,2,6 };
	////MergeSort m;
	////m.mergesort(test, 0, 7);
	//

	//sum s;
	//s.reverse(10);




	return 0;

}
