#include <stdio.h>
#include <stdlib.h>

#define M 100 //����ջ����󳤶�
typedef int datatype; //������������

//����ջ�ṹ
typedef struct {
    datatype data[M];
    int top;//ջ��ָ��
} seqstack;

void InitStack(seqstack *s) {  //��ʼ��˳��ջ
    s->top=-1;
}
int StackEmpty(seqstack *s) {  //�ж�ջ�Ƿ�Ϊ��
    if (s->top>=0) return 1;
    else return 0;
}
seqstack *push(seqstack *s,datatype x) { //Ԫ����ջ����
    if (s->top==M-1) return NULL;//�ж�ջ��
    else {
        s->top++;
        s->data[s->top]=x;
    }
    return s;
}
datatype pop(seqstack *s) { //Ԫ�س�ջ����
    datatype x;
    x=s->data[s->top];
    s->top--;
    return x;
}
int main() {
    char IN_Hex[] = {'A','B','C','D','E','F'};//����ṩ16����ת��
    int temp; //�����ʮ��������
    int int_temp = 0; //����Ŀ�����
    seqstack *s; //����ջ
    datatype n,e; //����ջ��Ԫ���Ҹ�ֵ��e

    printf("������ʮ����������");
    scanf("%d",&n);
    temp = n;
    n = abs(n);  //nʼ��Ϊ����whileѭ��ʹ��
    int i=0,j=0; //i���ڼ���ջԪ�ظ�����j���ڳ�ջѭ��

    s = (seqstack*)malloc(sizeof(int)); //�������ռ�
    if (s==NULL) exit(0); //����Ƿ����ɹ�

    InitStack(s); // ��ʼ��ջ
    printf("����������ת���ɵ�Ŀ����ƣ�<=16����");
    scanf("%d",&int_temp);   // ����Ǹ�ʮ��������n
    printf("ת�������");
    while(n) { // ��n������0
        push(s,n%int_temp); // ��ջn����int_temp������(int_temp���Ƶĵ�λ)
        i++;         // ͳ����ջԪ�ظ���
        n=n/int_temp;
    }
    if(temp<0){
        printf("-");
    }
    while(j<i) { // ���int_temp����
        j++;
        e=pop(s); // ����ջ��Ԫ���Ҹ�ֵ��e
        if(e>=10) {
            putchar(IN_Hex[e-10]);
        } else {
            printf("%d",e);
        }
    }
    return 0;
}