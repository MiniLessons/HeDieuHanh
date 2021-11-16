#include <stdio.h>
#include <string.h>

/*Hàm nhập mảng 1 chiều*/
void nhapmang(int array[], int length){
    for (short i = 0; i < length; i++)
    {
        printf("Kích thước thứ %d:",i+1);
        scanf("%d", &array[i]);
    }
}

void bestFit(int kichthuockhoi[], int m, int kichthuoctientrinh[], int n)
{
	//Mảng lưu trữ thứ tự các khối nhớ
	int khoinho[n];
    
    //Khởi tạo CHƯA có khối nhớ nào được cấp cho tiến trình
    memset(khoinho, -1, sizeof(khoinho)); 
    /*
        Hàm memset() trong C được sử dụng để lấp đầy một khối bộ nhớ với một giá trị cụ thể.
        Cú pháp của hàm memset() như sau: 
        void * memset (void * ptr, int x, size_t n);
            ptr:    Địa chỉ bắt đầu của bộ nhớ sẽ được lấp đầy
            x:      Giá trị được điền
            n:      Số byte được điền bắt đầu từ con trỏ ptr
    */

	
	//Chọn từng tiến trình và duyệt tìm khối có kích thước phù hợp với nó nhất
	for (int i=0; i<n; i++)
	{
		// Tìm khối nhớ đủ và tốt nhất cho tiến trình
		int khoitotnhat = -1;
		for (int j=0; j<m; j++)
		{
			if (kichthuockhoi[j] >= kichthuoctientrinh[i])
			{
				if (khoitotnhat == -1)
					khoitotnhat = j;
				else if (kichthuockhoi[khoitotnhat] > kichthuockhoi[j])
					khoitotnhat = j;
			}
		}

		// Khi tìm thấy khối nhớ tốt nhất cho tiến trình hiện hành
		if (khoitotnhat != -1)
		{
			// Cấp phát khối nhớ j cho tiến trình p[i]
			khoinho[i] = khoitotnhat;

			// Giảm kích thước cho khối nhớ này.
			kichthuockhoi[khoitotnhat] -= kichthuoctientrinh[i];
		}
	}

	
	printf("\nTiến trình\tKích thước\tKhối nhớ số\n");
	for (int i = 0; i < n; i++)
	{
		printf("\n%d\t\t\%d\t\t", i+1, kichthuoctientrinh[i]);
		if (khoinho[i] != -1)
			printf("%d",khoinho[i] + 1);
		else
			printf("Chưa được cấp phát\n");
		
	}
}


int main(){
    int sokhoi,sotientrinh;
    printf("Nhập số khối nhớ: ");
    scanf("%d", &sokhoi);
 
    int mang1[sokhoi];
    printf("Nhập kích thước cho mỗi khối nhớ:\n");
    nhapmang(mang1, sokhoi);
    printf("Nhập số tiến trình: ");
    scanf("%d", &sotientrinh);
 
    int mang2[sotientrinh];
    printf("Nhập kích thước cho mỗi tiến trình:\n");
    nhapmang(mang2, sotientrinh);
    
    bestFit(mang1, sokhoi, mang2, sotientrinh);
    

	return 0 ;
}
