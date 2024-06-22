// trạng thái hoàn thiện của code
1. làm hết phần nhập thông thiện:
    thông tin cá nhân: done
    thông tin y tế: done
    lịch sử tiêm chủng nếu có cái này sẽ khác so với 3 thằng còn lại: done
    lịch sử tiêm chủng tương lai
2. làm hết phần hiển thị thông thiện
    hiển thị thông tin cá nhân
    hiển thị thông tin y tế
    hiển thị thông tin lịch sử y nếu có
    hiển thị thông tin tiêm chủng tương lai
3. làm phần check điều kiện
    check điều kiện cho ngày tháng và năm: done sương sương, up sau
    
do{
		
		printf("nhap ngay-thang-nam: ");
		scanf("%d-%d-%d",&day,&month,&year);
		if(0>=day || 31<day || month<=0 || month >12 || year > 2024)
		{
			printf("khong hop le, nhap lai ngay thang nam!! \n");
		}
		else temp =1;
		
	}while(temp==0);

/*
	yêu cầu bài toán:
	nhập ngày tháng năm và kiểm tra điều kiện vào có đúng hay là không
	sử dụng do while để thực hiện vòng lặp này
	
 
	*/
	
//	check ngày tháng năm sinh dùng cho nhập ngày tiêm vaccine
//	nhập ngày bth không quá 100 tuổi là được
//	còn lịch tiêm tương lai thì nó cần phải là thời gian sau ngày hôm nay
//	sử dụng thư viện thời gian

printf("  Thoi gian tiem (dd/mm/yyyy): ");
                scanf("%d/%d/%d",&lichSuTiemChung[j].dayT,&lichSuTiemChung[j].monthT,&lichSuTiemChung[j].yearT);
                clear();