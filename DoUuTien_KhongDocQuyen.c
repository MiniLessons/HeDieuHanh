/////////CHUONG TRINH MINH HOA GIAI THUAT DINH THOI THEO DO UU TIEN - KHONG DOC QUYEN //////////////

#include<stdio.h>
struct TienTrinh
{
    int tg_cho,tg_denRL,tg_xuly,tg_hoantat,do_uu_tien;
};

struct TienTrinh a[10];

int main()
{
    int i,sotientrinh,tam[10],t,dem=0,uu_tien_nho;
    float TongTG_cho=0,TongTG_hoantat=0,tg_cho_tb,tg_hoantat_tb;
    printf("Nhap so tien trinh: ");
    scanf("%d",&sotientrinh);
    printf("Nhap thoi gian den hang doi Ready List, thoi gian xu ly va do uu tien cua cac tien trinh (Moi tien trinh 1 dong, moi gia tri cach nhau khoang trang\n");
    printf("TG_denRL| TG_XuLy| Do_UuTien\n");
    for(i=0;i<sotientrinh;i++)
    {
        scanf("%d%d%d",&a[i].tg_denRL,&a[i].tg_xuly,&a[i].do_uu_tien);
        
        // Sao chep thoi gian xu ly vao Mang tam
        tam[i]=a[i].tg_xuly;
    }
    
    //Gia su khoi tao do uu tien cua tien trinh la MAX (gia tri lon nhat)
    a[9].do_uu_tien=5000;
    
    for(t=0;dem!=sotientrinh;t++)
    {
        uu_tien_nho=9;
        for(i=0;i<sotientrinh;i++)
        {
            if(a[uu_tien_nho].do_uu_tien>a[i].do_uu_tien && a[i].tg_denRL<=t && a[i].tg_xuly>0)
            {
                uu_tien_nho=i;
            }
        }
        
        a[uu_tien_nho].tg_xuly=a[uu_tien_nho].tg_xuly-1;
        
        // Khi tien trinh chay xong
        if(a[uu_tien_nho].tg_xuly==0)
        {
            // 1 tien trinh hoan thanh thi tang bien DEM len
            dem++;
            a[uu_tien_nho].tg_cho=t+1-a[uu_tien_nho].tg_denRL-tam[uu_tien_nho];
            a[uu_tien_nho].tg_hoantat=t+1-a[uu_tien_nho].tg_denRL;
            
            // Tinh Tong thoi gian cho vaf Tong thoi gian hoan tat
            TongTG_cho=TongTG_cho+a[uu_tien_nho].tg_cho;
            TongTG_hoantat=TongTG_hoantat+a[uu_tien_nho].tg_hoantat;
            
        }
    }
    
    tg_cho_tb=TongTG_cho/sotientrinh;
    tg_hoantat_tb=TongTG_hoantat/sotientrinh;
    
    // Thuc hien in ket qua
   void red () {        //sử dụng hàm in màu chữ cho text
   printf("\033[0;31m"); //Mã màu xanh dương. Một số mã khác: Red \033[0;31m - Green \033[0;32m - Yellow \033[0;33m - Purple \033[0;35m
      }
      red ();
    printf("Ket qua dinh thoi tien trinh theo DO UU TIEN KHONG DOC QUYEN\n");
    printf("Tien trinh\tTG cho\t\tTG hoan tat\n");
    for(i=0;i<sotientrinh;i++)
    {
        printf("P%d\t\t%d\t\t%d\n",i+1,a[i].tg_cho,a[i].tg_hoantat);
    }
    
    printf("Thoi gian cho trung binh cua cac tien trinh %f\n",tg_cho_tb);
    printf("Thoi gian hoan tat trung binh cua cac tien trinh %f\n",tg_hoantat_tb);
    
    return 0;
}
