/////////CHUONG TRINH MINH HOA GIAI THUAT DINH THOI THEO DO UU TIEN - DOC QUYEN //////////////

#include<stdio.h>
struct TienTrinh
{
    int ma_tt,tg_cho,tg_denRL,tg_xuly,tg_hoantat,do_uu_tien;
};
struct TienTrinh a[10];

// Ham hoan doi
void hoandoi(int *b,int *c)
{
    int tem;
    tem=*c;
    *c=*b;
    *b=tem;
}


int main()
{
    int i,j;
    int sotientrinh,kiemtra_tg_denRL=0;
    int tg_tra_CPU=0;
    float TongTG_cho=0,TongTG_hoantat=0,tg_cho_tb,tg_hoantat_tb;
    printf("Nhap so tien trinh \n");
    scanf("%d",&sotientrinh);
    printf("Nhap thoi gian den hang doi, thoi gian xu ly va do uu tien cho moi tien trinh (moi tien trinh nhap 1 dong; moi gia tri cach nhau khoang trang)\n");
    printf("TG-den|TG-xu ly|Do-uu tien\n");
    for(i=0;i<sotientrinh;i++)
    {
        scanf("%d%d%d",&a[i].tg_denRL,&a[i].tg_xuly,&a[i].do_uu_tien);
        a[i].ma_tt=i+1;
        // Kiem tra thoi gian den hang doi cua tien trinh: cung nhau hoac khac nhau 
        if(i==0)
         kiemtra_tg_denRL=a[i].tg_denRL;
         
        if(kiemtra_tg_denRL!=a[i].tg_denRL )
         kiemtra_tg_denRL=1;
        
    }
    // Neu tien trinh den hang doi voi thoi gian khac nhau thi sap xep cac tien trinh dua tren thoi gian den
    if(kiemtra_tg_denRL!=0)
    {
        for(i=0;i<sotientrinh;i++)
        {
            for(j=0;j<sotientrinh-i-1;j++)
            {
                if(a[j].tg_denRL>a[j+1].tg_denRL)
                {
                      hoandoi(&a[j].ma_tt,&a[j+1].ma_tt);
                      hoandoi(&a[j].tg_denRL,&a[j+1].tg_denRL);
                      hoandoi(&a[j].tg_xuly,&a[j+1].tg_xuly);
                      hoandoi(&a[j].do_uu_tien,&a[j+1].do_uu_tien);
                }
            }
        }
    }
    
    
    // Neu tat ca tien trinh den Ready List voi thoi gian khac nhau
    if(kiemtra_tg_denRL!=0)
    {
        a[0].tg_cho=a[0].tg_denRL;
        a[0].tg_hoantat=a[0].tg_xuly-a[0].tg_denRL;
        // cmp_time for completion time
        tg_tra_CPU=a[0].tg_hoantat;
        TongTG_cho=TongTG_cho+a[0].tg_cho;
        TongTG_hoantat=TongTG_hoantat+a[0].tg_hoantat;
        for(i=1;i<sotientrinh;i++)
        {
            int min=a[i].do_uu_tien;
            for(j=i+1;j<sotientrinh;j++)
            {
                if(min>a[j].do_uu_tien && a[j].tg_denRL<=tg_tra_CPU)
                {
                      min=a[j].do_uu_tien;
                      hoandoi(&a[i].ma_tt,&a[j].ma_tt);
                      hoandoi(&a[i].tg_denRL,&a[j].tg_denRL);
                      hoandoi(&a[i].tg_xuly,&a[j].tg_xuly);
                      hoandoi(&a[i].do_uu_tien,&a[j].do_uu_tien);
                      
                }
                
            }
            a[i].tg_cho=tg_tra_CPU-a[i].tg_denRL;
            TongTG_cho=TongTG_cho+a[i].tg_cho;
            // Thoi gian hoan thanh cua tien trinh
            tg_tra_CPU=tg_tra_CPU+a[i].tg_xuly;
            
            // Thoi gian hoan tat cua tien trinh (hoan thanh - thoi gian den Ready List)
            a[i].tg_hoantat=tg_tra_CPU-a[i].tg_denRL;
            TongTG_hoantat=TongTG_hoantat+a[i].tg_hoantat;
            
        }
    }
    
    // Neu tat ca tien trinh den cung thoi gian
    else
    {
        for(i=0;i<sotientrinh;i++)
        {
            int min=a[i].do_uu_tien;
            for(j=i+1;j<sotientrinh;j++)
            {
                if(min>a[j].do_uu_tien && a[j].tg_denRL<=tg_tra_CPU)
                {
                    min=a[j].do_uu_tien;
                      hoandoi(&a[i].ma_tt,&a[j].ma_tt);
                      hoandoi(&a[i].tg_denRL,&a[j].tg_denRL);
                      hoandoi(&a[i].tg_xuly,&a[j].tg_xuly);
                      hoandoi(&a[i].do_uu_tien,&a[j].do_uu_tien);
                }
                
            }
            a[i].tg_cho=tg_tra_CPU-a[i].tg_denRL;
            
             // Thoi gian hoan thanh cua tien trinh
            tg_tra_CPU=tg_tra_CPU+a[i].tg_xuly;
            
            // Thoi gian hoan tat cua tien trinh
           
            a[i].tg_hoantat=tg_tra_CPU-a[i].tg_denRL;
            TongTG_cho=TongTG_cho+a[i].tg_cho;
            TongTG_hoantat=TongTG_hoantat+a[i].tg_hoantat;
            
        }
        
    }
    
   

    // Thuc hien in ket qua
   void red () {        //sử dụng hàm in màu chữ cho text
   printf("\033[0;31m"); //Mã màu xanh dương. Một số mã khác: Red \033[0;31m - Green \033[0;32m - Yellow \033[0;33m - Purple \033[0;35m
      }
      red ();
    printf("Ket qua dinh thoi tien trinh theo DO UU TIEN DOC QUYEN\n");
    printf("Tien trinh\tTG cho\t\tTG hoan tat\n");
    for(i=0;i<sotientrinh;i++)
    {
        printf("%d\t\t%d\t\t%d\n",a[i].ma_tt,a[i].tg_cho,a[i].tg_hoantat);
    }
    
    
    return 0;
}
