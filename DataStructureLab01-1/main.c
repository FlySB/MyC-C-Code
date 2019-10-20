#include <stdio.h>
#include <stdlib.h>

#define M 100 //定义栈的最大长度
typedef int datatype; //定义数据类型

//定义栈结构
typedef struct {
    datatype data[M];
    int top;//栈顶指针
} seqstack;

void InitStack(seqstack *s) {  //初始化顺序栈
    s->top=-1;
}
int StackEmpty(seqstack *s) {  //判断栈是否为空
    if (s->top>=0) return 1;
    else return 0;
}
seqstack *push(seqstack *s,datatype x) { //元素入栈函数
    if (s->top==M-1) return NULL;//判断栈满
    else {
        s->top++;
        s->data[s->top]=x;
    }
    return s;
}
datatype pop(seqstack *s) { //元素出栈函数
    datatype x;
    x=s->data[s->top];
    s->top--;
    return x;
}
int main() {
    char IN_Hex[] = {'A','B','C','D','E','F'};//最高提供16进制转换
    int temp; //输入的十进制整数
    int int_temp = 0; //输入目标进制
    seqstack *s; //定义栈
    datatype n,e; //弹出栈顶元素且赋值给e

    printf("请输入十进制整数：");
    scanf("%d",&n);
    temp = n;
    n = abs(n);  //n始终为正，while循环使用
    int i=0,j=0; //i用于计量栈元素个数，j用于出栈循环

    s = (seqstack*)malloc(sizeof(int)); //必须分配空间
    if (s==NULL) exit(0); //检查是否分配成功

    InitStack(s); // 初始化栈
    printf("请输入您想转换成的目标进制（<=16）：");
    scanf("%d",&int_temp);   // 输入非负十进制整数n
    printf("转换结果：");
    while(n) { // 当n不等于0
        push(s,n%int_temp); // 入栈n除以int_temp的余数(int_temp进制的低位)
        i++;         // 统计入栈元素个数
        n=n/int_temp;
    }
    if(temp<0){
        printf("-");
    }
    while(j<i) { // 输出int_temp进制
        j++;
        e=pop(s); // 弹出栈顶元素且赋值给e
        if(e>=10) {
            putchar(IN_Hex[e-10]);
        } else {
            printf("%d",e);
        }
    }
    return 0;
}