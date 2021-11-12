//IT2 08 氏名：蝦名海
//行列式を行列の基本変形を用いて一番外の列に0を増やすやり方で解くプログラム

#include <stdio.h>

int main(void) {
    int i,j,current,adjust,order=11;
    float matrix[10][10],determinant;
    int k,l;

    //入力部分
    while(order>10 || order<=0){
        printf("order > ");
        scanf("%d",&order);
    }

    for(i=0;i<order;i++){
        for(j=0;j<order;j++){
            scanf("%f",&matrix[i][j]);
        }
    }

    //処理部分
    determinant = 1;

    for (current=order-1;current>=0;current--){
        //基準部分が0の時の調整
        adjust = 1;
        if (matrix[current][current] == 0){
            while (adjust != current+1){
                if (matrix[current-adjust][current] == 0){
                    adjust ++;
                    continue;
                }
                for(i=0;i<=current;i++){
                    matrix[current][i] += matrix[current-adjust][i];
                }
                break;
            }
        }
        //メイン処理
        for(i=current-1;i>=0;i--){
            for(j=0;j<current;j++){
                matrix[i][j] -= matrix[current][j] * matrix[i][current] / (matrix[current][current] + 1e-10);
            }
        }
        
        determinant *= matrix[current][current];
    }

    // 出力部分
    printf("ans:%.3f\n",determinant);
    
    return 0;
}