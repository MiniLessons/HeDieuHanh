#include<stdio.h>
 
int main()
{
      static int khoinho[10], tientrinh[10];
      int phanmanh[10], kichthuockhoi[10], kichthuoctientrinh[10];
      int m, n, sokhoi, sotientrinh, temp;
      printf("\nNhập tổng số khối nhớ:");
      scanf("%d", &sokhoi);
      printf("Nhập tổng số tiến trình:");
      scanf("%d", &sotientrinh);
      printf("\nNhập kích thước (dung lượng) của mỗi khối nhớ:\n");
      for(m = 0; m < sokhoi; m++) 
      {
            printf("Khối.[%d]:", m+1);
            scanf("%d", &kichthuockhoi[m]);
      }
      printf("Nhập kích thước của mỗi tiến trình:\n");
      for(m = 0; m < sotientrinh; m++) 
      {
            printf("Tiến trình.[%d]:", m+1);
            scanf("%d", &kichthuoctientrinh[m]);
      }
      for(m = 0; m < sotientrinh; m++)
      {
            for(n = 0; n < sokhoi; n++)
            {
                  if(kichthuockhoi[n] >= kichthuoctientrinh[m])
                  {
                        khoinho[m]=n;
                        kichthuockhoi[n]=kichthuockhoi[n] - kichthuoctientrinh[m];
                        temp=kichthuockhoi[n];
                        tientrinh[m] = n;
                        
                        break;
                        
                  }
            }
            phanmanh[m] = temp;
            
            
      }
      printf("\nTiến trình\t\tKích thước tiến trình\t\tKhối nhớ\t\tPhân mảnh");
      for(m = 0; m < sotientrinh; m++)
      {
            printf("\n%d\t\t\t%d\t\t\t\t%d\t\t\t%d", m+1, kichthuoctientrinh[m],tientrinh[m]+1, phanmanh[m]);
      }
      printf("\n");
      return 0;
}