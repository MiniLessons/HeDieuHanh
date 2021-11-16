#include<stdio.h>
 
int main()
{
        float TG_XuLy[30], TG_Cho[30], TG_HoanTat[30];
        float TG_cho_TB = 0.0, TG_HoanTat_TB = 0.0;
        int count, j, So_TienTrinh;
        printf("Nhap so Tien trinh thuc thi:\t");
        scanf("%d", &So_TienTrinh);
        printf("\nNhap thoi gian xu ly cua moi Tien trinh:\n\n");
        for(count = 0; count < So_TienTrinh; count++)
        {
                printf("P[%d]:", count + 1);
                scanf("%f", &TG_XuLy[count]);
        }
        TG_Cho[0] = 0;   
        for(count = 1; count < So_TienTrinh; count++)
        {
                TG_Cho[count] = 0;
                for(j = 0; j < count; j++)
                {
                        TG_Cho[count] = TG_Cho[count] + TG_XuLy[j];
                }
        }
        printf("\nTien Trinh\tTG Xu ly\tTG cho\t\tTG Hoan tat\n");
        for(count = 0; count < So_TienTrinh; count++)
        {
                TG_HoanTat[count] = TG_XuLy[count] + TG_Cho[count];
                TG_cho_TB = TG_cho_TB + TG_Cho[count];
                TG_HoanTat_TB = TG_HoanTat_TB + TG_HoanTat[count];
                printf("\nP[%d]\t\t%.2f\t\t%.2f\t\t%.2f", count + 1, TG_XuLy[count], TG_Cho[count], TG_HoanTat[count]);
        }
        printf("\n");
        TG_cho_TB = TG_cho_TB / count;
        TG_HoanTat_TB = TG_HoanTat_TB / count;
        printf("\nThoi gian cho trung binh = %f", TG_cho_TB);
        printf("\nThoi gian hoan tat trung binh = %f", TG_HoanTat_TB);
        printf("\n");
	return 0;
}
