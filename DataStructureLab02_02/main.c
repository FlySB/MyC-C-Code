#include <stdio.h>
#include <string.h>

#define SIZE 100
#define INF 999999999

int m[SIZE];		//��ž�������������Ϣ��m[i-1]��m[i]�ֱ�Ϊ��i��������к��У�i = 1��2��3...��
int d[SIZE][SIZE];	//��ž��������������ֵ��d[i][j]Ϊ��i�����󵽵�j������ľ�����������ֵ��i > 0
int s[SIZE][SIZE];

int Best_DP(int n)
{
    //��d[i][i]��Ϊ0��1 <= i < n
    memset(d, 0, sizeof(d));

    int len;
    //�ݹ�������������������ֵ
    //len = 1��������������������󹹳�
    for (len = 1; len < n; len++)
    {
        int i, j, k;
        for (i = 1, j = i+len; j < n; i++, j++)
        {
            s[i][j] = i;
            int min = INF;
            for (k = i; k < j; k++)
            {
                int count = d[i][k] + d[k+1][j] + m[i-1] * m[k] * m[j];
                if (count < min)
                {
                    s[i][j] = k;
                    min = count;
                }
            }
            d[i][j] = min;
        }
    }
    return d[1][n-1];
}

void MatOut(int size,int n[SIZE][SIZE]){

    for(int i = 1; i < size; i++){
        for(int j = 1; j < size; j++){
            printf("%d\t",n[i][j]);
        }
        printf("\n");
    }
}

void FormatOut(int i, int j){
    if(i == j){
        printf("A%d", i);
        return;
    }
    printf("(");
    FormatOut(i,s[i][j]);
    printf(" x ");
    FormatOut(s[i][j] + 1, j);
    printf(")");
}

int main()
{
    int n;

    while (1) {
        printf("���������鳤��:");
        scanf("%d",&n);
        if (n >= 1) {
            int i;
            for (i = 0; i < n; i++) {
                scanf("%d", &m[i]);
            }

            printf("���ٳ˷�����Ϊ��%d\n", Best_DP(n));
            break;
        } else{
            printf("���������0������\n");
        }
    }
    MatOut(n,d);
    MatOut(n,s);
    FormatOut(1,n-1);
    return 0;
}