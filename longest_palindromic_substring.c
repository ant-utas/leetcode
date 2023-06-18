/*
Given a string s, return the longest palindromic substring in s.
*/
int is_palindrome(char * s, int start, int end){
    int boo = 1;
    while(end>start){
        if(s[end]!=s[start])boo = 0;
        end--;
        start++;
    }
    return boo;
}

char * longestPalindrome(char * s){
    char * longest = malloc(sizeof(char)*1000);
    char return_s[1000];
    int start = 0;
    int end = 0;
    int longest_length = 0;
    int i;
    while(s[start]!='\0'){//iterate thru string changing start char
        while(s[end]!='\0'){//iterate thru string changing end char
            if(is_palindrome(s,start,end) && (end-start+1)>longest_length){
                for(i=0; i<=end-start; i++){
                    longest[i] = s[start+i];
                    //printf("%c,%c-",s[start+i],longest[i]);
                }
                longest_length = (end-start)+1;
                longest[longest_length] = '\0';//end string
                //printf("\n");
            }
            end++;
        }
        //printf("- - - - - - - - - - - - - - - - - -\n");
        start++;
        end = start;
    }
    printf("%s",longest);
    return longest;
}
