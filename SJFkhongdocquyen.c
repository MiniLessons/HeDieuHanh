#include <stdio.h>
 
int main() 
{
      int tgdenRL[10], tgxl[10], tam[10];
      int i, nhonhat, dem = 0, thoigian, soTT;
      double tgcho = 0, tght = 0, ketthuc;
      float tgchotb, tghttb;
      printf("\nNhap so tien trinh:\t");
      scanf("%d", &soTT); 
      printf("\nNhap du lieu chi tiet cho %d tien trinh\n", soTT);
      for(i = 0; i < soTT; i++)
      {
            printf("\nNhap thoi gian den hang doi Ready cua tien trinh thu %d :", i+1);
            scanf("%d", &tgdenRL[i]);
            printf("Nhap thoi gian xu ly cua tien trinh thu %d :", i+1);
            scanf("%d", &tgxl[i]); 
            tam[i] = tgxl[i];
      }
      tgxl[9] = 60;  //Gia su thoi gian xu ly cua tien trinh cuoi cung la 60 giay
      for(thoigian = 0; dem != soTT; thoigian++)
      {
            nhonhat = 9; //Xet tien trinh co thoi gian nho nhat (tien trinh sau cung)
            for(i = 0; i < soTT; i++)
            {
                  if(tgdenRL[i] <= thoigian && tgxl[i] < tgxl[nhonhat] && tgxl[i] > 0)
                  {
                        nhonhat = i;
                  }
            }
            tgxl[nhonhat]--;
            if(tgxl[nhonhat] == 0)
            {
                  dem++;
                  ketthuc = thoigian + 1;
                  tgcho = tgcho + ketthuc - tgdenRL[nhonhat] - tam[nhonhat];
                  tght = tght + ketthuc - tgdenRL[nhonhat];
            }
      }
      tgchotb = tgcho / soTT; 
      tghttb = tght / soTT;
      printf("\n\nThoi gian cho trung binh:\t%lf\n", tgchotb);
      printf("Thoi gian hoan tat trung binh:\t%lf\n", tghttb);
      return 0;
}