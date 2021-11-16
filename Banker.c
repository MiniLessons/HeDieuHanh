#include <stdio.h>
 
int main()
{
      int dem = 0, m, n, tientrinh, tam, tainguyen; 
      int bangtainguyen[5] = {0, 0, 0, 0, 0};
      int tainguyensanco[5], tainguyenhienhanh[5][5], yeucautoida[5][5];
      int tainguyentoida[5], dangchay[5], trangthaiantoan = 0;
      printf("\nNhập số tiến trình:\t");
      scanf("%d", &tientrinh);
      for(m = 0; m < tientrinh; m++) 
      {
            dangchay[m] = 1;
            dem++;
      }
      printf("\nNhập tổng số loại tài nguyên cấp phát:\t");
      scanf("%d", &tainguyen);
      printf("\nNhập tổng số tài nguyên mỗi loại (cách nhau bằng khoảng trắng):\t");
      for(m = 0; m < tainguyen; m++) 
      { 
            scanf("%d", &tainguyentoida[m]);
      }
      printf("\nNhập ma trận tài nguyên đã cấp phát (mỗi tiến trình 1 dòng, mỗi phần từ cách nhau khoảng trắng):\n");
      for(m = 0; m < tientrinh; m++) 
      {
            for(n = 0; n < tainguyen; n++) 
            {
                  scanf("%d", &tainguyenhienhanh[m][n]);
            }
      }
      printf("\nNhập ma trận tài nguyên yêu cầu tối đa của các tiến trình (mỗi tiến trình 1 dòng, mỗi phần từ cách nhau khoảng trắng):\n");
      for(m = 0; m < tientrinh; m++) 
      {
            for(n = 0; n < tainguyen; n++) 
            {
                  scanf("%d", &yeucautoida[m][n]);
            }
      }
      
      ///////////////////KẾT QUẢ///////////////////////////
      void blue () {        //sử dụng hàm in màu chữ cho text
        printf("\033[0;34m"); //Mã màu xanh dương. Một số mã khác: Red \033[0;31m - Green \033[0;32m - Yellow \033[0;33m - Purple \033[0;35m
      }
      blue ();
      printf("KẾT QUẢ GIẢI THUẬT BANKER \n");
      printf("\nTổng mỗi loại tài nguyên của hệ thống \n");
      for(m = 0; m < tainguyen; m++) 
      {
            printf("\t%d ", tainguyentoida[m]);
      }
      printf("\n Ma trận tài nguyên đã cấp phát\n");
      for(m = 0; m < tientrinh; m++) 
      {
            for(n = 0; n < tainguyen; n++) 
            {
                  printf("\t%d", tainguyenhienhanh[m][n]);
            }
            printf("\n");
      }
      printf("\nMa trận tài nguyên tối đa mà các tiến trình cần dùng \n");
      for(m = 0; m < tientrinh; m++) 
      {
            for(n = 0; n < tainguyen; n++) 
            {
                  printf("\t%d", yeucautoida[m][n]);
            }
            printf("\n");
      }
      for(m = 0; m < tientrinh; m++) 
      {
            for(n = 0; n < tainguyen; n++) 
            {
                  bangtainguyen[n] = bangtainguyen[n] + tainguyenhienhanh[m][n];
            }
      }
      printf("\nTài nguyên đã cấp phát \n");
      for(m = 0; m < tainguyen; m++) 
      {
            printf("\t%d", bangtainguyen[m]);
      }
      for(m = 0; m < tainguyen; m++) 
      {
            tainguyensanco[m] = tainguyentoida[m] - bangtainguyen[m];
      }
      printf("\nTài nguyên có sẵn của hệ thống:");
      for(m = 0; m < tainguyen; m++) 
      {
            printf("\t%d", tainguyensanco[m]);
      }
      printf("\n");
      while(dem != 0) 
      {
            trangthaiantoan = 0;
            for(m = 0; m < tientrinh; m++) 
            {
                  if(dangchay[m]) 
                  {
                        tam = 1;
                        for(n = 0; n < tainguyen; n++) 
                        {
                              if(yeucautoida[m][n] - tainguyenhienhanh[m][n] > tainguyensanco[n]) 
                              {
                                    tam = 0;
                                    break;
                              }
                        }
                        if(tam) 
                        {
                               printf("\nTiến trình %d thực thi \n", m + 1);
                               dangchay[m] = 0;
                               dem--;
                               trangthaiantoan = 1;
                               for(n = 0; n < tainguyen; n++) 
                               {
                                     tainguyensanco[n] = tainguyensanco[n] + tainguyenhienhanh[m][n];
                               }
                               break;
                        }
                  }
            }
            if(!trangthaiantoan) 
            {
                  printf("\nCác tiến trình đang ở trạng thái không an toàn \n");
                  break;
            } 
            else 
            {
                  printf("\nTiến trình ở trạng thái an toàn \n");
                  printf("\nTài nguyên sẵn có của hệ thống\n");
                  for(m = 0; m < tainguyen; m++) 
                  {
                        printf("\t%d", tainguyensanco[m]);
                  }
                  printf("\n");
            }
      }
      return 0;
}
