#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{ 
    int pos;
    int start;
    int text_len=0;
    int key_len=0;

    while(text[text_len] !='\0'){

        text_len++;

    }

    while(key[key_len] !='\0'){

        key_len++;

    }

    for(start=0;text_len-key_len > start;start++){
        for(pos=0;pos<key_len;pos++) {   
            if(text[start+pos] == key[pos]){
                if(pos==(key_len-1)){
                return text+start;
            }
        }
            else{
                break;
            }
        }
    }
        return NULL;
    //  ここを実装する

}

char* BMSearch(char text[], char key[])
{
    int index;
    int text_len=0;
    int key_len=0;
    int key_index;
    int i;
    int index_record;
    int table[256];

    while(text[text_len]!='\0'){
        text_len=text_len+1;
    }

    while(key[key_len]!='\0'){
        key_len=key_len+1;
    }

    for(i=0;i<256;i++){
        table[i]=key_len;
    }

    for(i=0;i<key_len;i++){
        table[(int)key[i]]=key_len-i-1;
    }
    
    index=key_len-1;
    
    while(index<text_len){
        index_record=index;
        for(key_index=key_len-1;key_index>=0;key_index--,index--){
            if(text[index]==key[key_index]){
                if(key_index==0){
                    return text+index;
        }
            }else{
                break;
            }
        }
        index=index+table[(int)text[index]];

        if(index<=index_record){
            index=index_record+1;
        }
        index_record=index;
    }
    //  ここを実装する
    return NULL;
}
     
int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}