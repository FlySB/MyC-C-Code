#include <stdio.h>
#include <string.h>

#define SIZE 100
#define INF 999999999

int m[SIZE];		//��ž�������������Ϣ��m[i-1]��m[i]�ֱ�Ϊ��i��������к��У�i = 1��2��3...��
int d[SIZE][SIZE];	//��ž��������������ֵ��d[i][j]Ϊ��i�����󵽵�j������ľ�����������ֵ��i > 0

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
            int min = INF; //�����
            for (k = i; k < j; k++)
            {
                printf("i:%d j:%d k:%d\n",i,j,k);
                int count = d[i][k] + d[k+1][j] + m[i-1] * m[k] * m[j];
                printf("c:%d\n",count);
                if (count < min)
                {
                    min = count;
                    printf("m:%d\n",min);
                }
            }
            printf("k:%d\n",k);
            printf("i:%d j:%d\n",i,j);
            d[i][j] = min;
            printf("hhhh\n");
        }
        printf("pppp\n");
    }
    return d[1][n-1];
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
    return 0;
}