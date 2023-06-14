/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = malloc(sizeof(struct ListNode));
    result->next = NULL;
    struct ListNode* result_holder = result;
    int over = 0;//when sum is greater than 10, carry the 1 to next node
    int sum;
    while(l1!=NULL || l2!=NULL || over){//continue until both l1 and l2 are NULL
        if(l1 != NULL && l2 != NULL){
            sum = l1->val+l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if(l1 == NULL){
            sum = l2->val;
            l2 = l2->next;
        }
        else {
            sum = l1->val;
            l1 = l1->next;
        }
        result->val = over + sum%10;
        printf("%d\n",sum);
        over = 0;
        if(sum >= 10){
            over = 1;
        }
        //printf("%d",result->val);
        struct ListNode* new_node = malloc(sizeof(struct ListNode));
        new_node->next = NULL;
        result->next = new_node;
        result = result->next;
        
        printf("waaaah\n");
    }
    printf("- - - - - - - - - - - - - - - - - -\n");
    return result_holder;
}
