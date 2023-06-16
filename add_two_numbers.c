/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry_over = 0;
    int sum;
    struct ListNode* result = malloc(sizeof(struct ListNode));
    struct ListNode* result_holder = result;
    struct ListNode* result_ender = result;
    int quit = 0;
    while(!quit){
        sum = 0;
        if(l1!=NULL && l2!=NULL){
            sum = (l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;

        }
        else if(l1==NULL && l2!=NULL){
            sum = l2->val;
            l2 = l2->next;
        }
        else if(l1!=NULL && l2==NULL){
            sum = l1->val;
            l1 = l1->next;
        }
        result->val = (sum + carry_over)%10;


        if(sum+carry_over >= 10){
            carry_over = 1;
        }
        else{
            carry_over = 0;
        }
        printf("%d\n",result->val);
        struct ListNode* new_node = malloc(sizeof(struct ListNode));
        new_node->next = NULL;
        result->next = new_node;
        result_ender = result;
        result = result->next;
        if(l1==NULL && l2== NULL && carry_over==0){
            quit = 1;
        }
    }
    result_ender->next = NULL;
    return result_holder;
}
