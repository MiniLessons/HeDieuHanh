#include<stdio.h>
 
int main()
{
      int tam, i, j, soTT, tong = 0, vitri;
      float tgchotb, tghttb; //thoi gian cho trung binh va thoi gian hoan tat trung binh
      int tgxl[20], tt[20], tgcho[20], tght[20];
      printf("\nNhap so tien trinh:\t");
      scanf("%d", &soTT); 
      for(i = 0; i < soTT; i++)
      {
            printf("Nhap thoi gian xu ly cua tien trinh[%d]:\t", i + 1);
            scanf("%d", &tgxl[i]);
            tt[i] = i + 1;
      }
      for(i = 0; i < soTT; i++)
      {
            vitri = i;
            for(j = i + 1; j < soTT; j++)
            {
                  if(tgxl[j] < tgxl[vitri])
                  {
                        vitri = j;
                  }
            }
            tam = tgxl[i];
            tgxl[i] = tgxl[vitri];
            tgxl[vitri] = tam;
            tam = tt[i];
            tt[i] = tt[vitri];
            tt[vitri] = tam;
      } 
      tgcho[0] = 0;
      for(i = 1; i < soTT; i++)
      {
            tgcho[i] = 0;
            for(j = 0; j < i; j++)
            {
                  tgcho[i] = tgcho[i] + tgxl[j];
            } 
            tong = tong + tgcho[i];
      }
      tgchotb = (float)tong / soTT;
      tong = 0;
      printf("\nTiến trình\tTG Xử lý\t TG chờ\t\t TG hoàn tất\n");
      for(i = 0; i < soTT; i++)
      {
            tght[i] = tgxl[i] + tgcho[i];
            tong = tong + tght[i];
            printf("\nP[%d]\t\t%d\t\t %d\t\t %d\n", tt[i], tgxl[i], tgcho[i], tght[i]);
      }
      tghttb = (float)tong / soTT;
      printf("\nThời gian chờ trung bình:\t%f\n", tgchotb);
      printf("\nThời gian hoàn tất trung bình:\t%f\n", tghttb);
      return 0;
}