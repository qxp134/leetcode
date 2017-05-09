#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
	struct chain
	{
		char value;
		int index;
		chain* next;
		chain(char i){ this->value = i; next = NULL; }
	};
public:
	int lengthOfLongestSubstring(string s) {
		int length = 0, max = 1;
		bool move = true;
		bool isfrist = true;
		if (s == ""){
			return length;
		}
		length = 1;
		int count = 0;
		chain *list, *work, *work1;//全部加在链表里，反正只砍头
		list = new chain(0);
		work = list;
		for (int i = 0; i < s.length(); i++){
			chain *list1;
			list1 = new chain(s[i]);
			list1->index = i;
			if (isfrist){ list = list1; isfrist = false; }
			work->next = list1;
			work = work->next;
		}
		work1 = work = list;
		while (true){
			if (work->next == NULL)break;
			if (move)
				work = work->next;
			move = true;
			work1 = list;
			while (work != work1){
				if (work->value != work1->value){
					work1 = work1->next;
				}
				else
				{
					length = work->index - list->index;
					work1 = list = work1->next;
					move = false;
					if (length > max){
						max = length;
					}
				}
			}
		}
		length = work->index - list->index;
		if (length > max - 1){
			max = length + 1;
		}
		return max;
	}
};