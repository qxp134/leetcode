#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {	
		bool addone = false;
		bool along = false;
		bool blong = false;
		ListNode* result;
		result = new ListNode(l1->val + l2->val);
		ListNode* work = result;
		while (true){
			if (l1 == NULL){
				blong = true;
				break;
			}
			if (l2 == NULL){
				along = true;
				break;
			}
			int temp;
			temp = l1->val + l2->val;
			l1 = l1->next;
			l2 = l2->next;
			if (addone) {
				temp++;
			}
			addone = false;
			if (temp >= 10){
				addone = true;
				temp = temp - 10;
			}
			if (addone == true && l1 == NULL&&l2 == NULL){
				l1 = new ListNode(1);
			}
			else if (addone == true && l1 == NULL){//这儿有个坑啊5+5 输出就是0 需要强行再加一链
				l1 = new ListNode(0);
			}
			else if (addone == true && l2 == NULL){//这儿有个坑啊5+5 输出就是0 需要强行再加一链
				l2 = new ListNode(0);
			}
			ListNode *l3;
			l3 = new ListNode(temp);
			work->next = l3;
			work = l3;
		}
		if (along){
			work->next = l1;
		}
		else if (blong){
			work->next = l2;
		}
		result = result->next;//这儿也有个坑，头指针得往后移一位
		return result;
	}
};