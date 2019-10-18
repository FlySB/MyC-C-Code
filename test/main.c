#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <math.h>
#define M 100 //定义栈的最大长度
typedef int datatype; //定义数据类型

//定义栈结构
typedef struct {
    datatype data[M];
    int top;//栈顶指针
} seqstack;

int main(){
    seqstack *s;
    s = (seqstack*)malloc(sizeof(int));
    printf("%d\n",s->data[0]);
    printf("%d", sizeof(int));
    return 0;
}