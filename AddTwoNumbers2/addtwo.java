/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {//java���boolean null��C++��Ĳ�һ��������ָ�룬����ûʲô������
        boolean addone = false;
		boolean along = false;
		boolean blong = false;
		ListNode result;
		result = new ListNode(l1.val + l2.val);
		ListNode work = result;
		while (true){
			if (l1 == null){
				blong = true;
				break;
			}
			if (l2 == null){
				along = true;
				break;
			}
			int temp;
			temp = l1.val + l2.val;
			l1 = l1.next;
			l2 = l2.next;
			if (addone) {
				temp++;
			}
			addone = false;
			if (temp >= 10){
				addone = true;
				temp = temp - 10;
			}
			if (addone == true && l1 == null&&l2 == null){
				l1 = new ListNode(1);
			}
			else if (addone == true && l1 == null){//����и��Ӱ�5+5 �������0 ��Ҫǿ���ټ�һ��
				l1 = new ListNode(0);
			}
			else if (addone == true && l2 == null){//����и��Ӱ�5+5 �������0 ��Ҫǿ���ټ�һ��
				l2 = new ListNode(0);
			}
			ListNode l3;
			l3 = new ListNode(temp);
			work.next = l3;
			work = l3;
		}
		if (along){
			work.next = l1;
		}
		else if (blong){
			work.next = l2;
		}
		result = result.next;//���Ҳ�и��ӣ�ͷָ���������һλ
		return result;
    }
}