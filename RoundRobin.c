#include<stdio.h> 

float  tg_cho[100], tg_hoantat[100], tg_cho_tb, tg_ht_tb, tamTT[100], tamDen[100];
int tgxl[100], tg_den[100], tgchomoidoan[100], tien_trinh_nghi[100], tt[100], vtcu[100], sl_tt, quantum, sl;

void NhapTienTrinh()
{
      int i;
      printf("Nhap so tien trinh:\t"); 
      scanf("%d", &sl_tt); 
      for(i = 0; i < sl_tt; i++) 
      {
            printf("\nNhap du lieu chi tiet cho tien trinh thu %d\n", i + 1);
            printf("Thoi gian den hang doi:\t");
            scanf("%d", &tg_den[i]);
            printf("Thoi gian xu ly:\t");
            scanf("%d", &tgxl[i]); 
            tamTT[i] = tgxl[i];
	    tg_cho[i]=0;
	    tg_hoantat[i]=0;
	    tt[i]=i+1;
	    tamDen[i]=tg_den[i];
      } 
      printf("\nNhap thoi gian xoay vong (Time Quantum):\t"); 
      scanf("%d", &quantum); 
}

void XuatTienTrinh()
{
	printf("Tien trinh\tTG den RL\tTG xu ly\tTG cho\tTG hoan tat\n");
	int i;
	for(i=0; i<sl_tt; i++)
		printf("P[%d]\t\t%2d\t\t%2d\t\t%.2f\t%.2f\n", tt[i], tg_den[i], tgxl[i], tg_cho[i], tg_hoantat[i]);
	printf("\nThoi gian cho trung binh: %.2f", tg_cho_tb);
	printf("\nThoi gian hoan tat trung binh: %.2f", tg_ht_tb);
	printf("\n");
}

//Hàm ngắt tiến trình khi hết thời gian xoay vòng (quantum) mà vẫn chưa chạy xong
void xoa(int vt)
{
    int i=vt;
    for(;i<sl;i++)
    {
        tamTT[i]=tamTT[i+1];
        tamDen[i]=tamDen[i+1];
        vtcu[i]=vtcu[i+1];
    }
    sl--;
}

//Hàm xoay vòng của 1 tiến trình
void chen(int vt, int gt, int gtden, int gtvtcu)
{
    int i;
    for(i=sl; i>vt; i--)
    {
        tamTT[i]=tamTT[i-1];
        tamDen[i]=tamDen[i-1];
        vtcu[i]=vtcu[i-1];
    }
    
    tamTT[vt]=gt;
    tamDen[vt]=gtden;
    vtcu[vt]=gtvtcu;
    sl++;
}

//Hàm giải thuật định thời Round Robin
void RoundRobin()
{
    tg_ht_tb=0;
    tg_cho_tb=0;
    tg_cho[0]=0;
    int i, tong_tg_chay=0;
    for(i=0; i<sl_tt; i++)
    {
        int j=i+1;
        for( ; j<sl_tt; j++)
            if(tg_den[i]>tg_den[j])
            {
                int t=tg_den[i];
                tg_den[i]=tg_den[j];
                tg_den[j]=t;
                t=tgxl[i];
                tgxl[i]=tgxl[j];
                tgxl[j]=t;
                t=tt[i];
                tt[i]=tt[j];
                tt[j]=t;
                tien_trinh_nghi[i]=0;
            }
            
            vtcu[i]=i;
            tamTT[i]=tgxl[i];
            tamDen[i]=tg_den[i];
            
    }
    
    sl=sl_tt;
    int j=0;
    //vòng lặp sẽ duyệt qua số lần xoay vòng của tiến trình
    while(sl>0)
    {
        tg_cho[vtcu[0]] += tong_tg_chay - tamDen[0] - tien_trinh_nghi[vtcu[0]];
        tamDen[0]=0;
        
        //trường hợp tiến trình có thời gian xử lý lớn hơn thời gian xoay vòng (quantum)
        if(tamTT[0]>quantum)
        {
            tong_tg_chay += quantum;
            tien_trinh_nghi[vtcu[0]] = tong_tg_chay;
            tamTT[0] -= quantum;
            j=1;
            while(tamDen[j] < tong_tg_chay && j<sl)
            j++;
            if(tamDen[j] != tong_tg_chay)
            {
                j=sl;
            }
            chen(j, tamTT[0], tamDen[0], vtcu[0]);
            xoa(0);
        }
        else    //trường hợp tiến trình có thời gian xử lý nhỏ hơn thời gian xoay vòng (quantum)
        {
            tong_tg_chay += tamTT[0];
            tg_cho_tb += tg_cho[vtcu[0]];
            tg_hoantat[vtcu[0]] = tong_tg_chay - tg_den[vtcu[0]];
            tg_ht_tb += tg_hoantat[vtcu[0]];
            xoa(0);
        }
        
        //tính thời gian chờ trung bình và thời gian hoàn tất trung bình của các tiến trình
        tg_cho_tb /= sl_tt;
        tg_ht_tb /= sl_tt;
    }
}



int main() 
{ 
	NhapTienTrinh();
	RoundRobin();
	XuatTienTrinh();	
}
