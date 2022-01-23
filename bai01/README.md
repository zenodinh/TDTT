# Thuật toán tầm thường:  
# Ý tưởng:  
Ta coi tại vị trí i > k thì k phần tử trước đó đã biết UCLN --> ta cần tính lại UCLN lớn của k-1 phần tử trước đó với phần tử i mới.  
Sau đó so sánh để lấy UCLN của k phần tử mà lớn nhất
# Cài đặt
Đầu tiên ta thực hiện duyệt từng vị trí (dùng 0 --> n-1)  
  Tại mỗi vị trí, ta duyệt k phần tử (i --> i+k)  
  Thực hiện tính UCLN của k phần tử và cập nhật giá tri UCLN lớn nhất so với giá trị cũ.  
   
### Độ phức tạp thời gian: O(n * k * log(max(a,b)) với a, b là 2 biến tham số cho hàm gcd tìm UCLN giữa a và b  
### Độ phức tạp không gian: O(1)

# Thuật toán cải tiến:  
## Ý tưởng:  
Ta sẽ dùng 1 mảng để lưu số lượng phần tử trong đoạn k có ước là index, qua đó khi duyệt mảng từ cao --> thấp thì nếu số lượng == k thì trả về kết quả
Trong quá trình tìm ước của phần tử a[i] thì ta sẽ double shot (vừa cập nhật cho x nếu a[i] % x == 0 đồng thời cập nhật cho a[i] / x do a[i] % x == 0 --> a[i] % (a[i] /x) == 0)
## Cài đặt
Ta sẽ thực hiện đệ quy trong việc tìm UCLN bằng cách chia mảng a[n] có left = 0 và right = n - 1 thành đoạn [left, left + k] và đoạn [left + 1, right]  
Thay vì tìm UCLN của k phần tử thì ta sẽ tìm số lượng phần tử mà có ước là index của mảng (ở đây dùng là mảng divisor)
Trong hàm UCLN cải tiến, ta sẽ nhận các tham số bao gồm mảng a, vị trí đầu left, vị trí kết thúc right.  
 * Ta sẽ tạo mảng divisor để lưu lại số lượng phần tử trong đoạn k phần tử có ước đó (là index)  
 * Đầu tiên, mảng divisor có kích thước là phần tử lớn nhất trong đoạn k
 * Với mỗi phần tử, ta sẽ duyệt từ 1 --> sqrt của a[i] vì ta nếu a[i] % x == 0 thì a[i] % (a[i] / x) == 0 nên chỉ cần duyệt tới sqrt(a[i])
 * Sau khi tính xong divisor thì ta duyệt từ cao xuống thấp, nếu tại index đó mà số lượng == k thì trả về kết quả.  

### Độ phức tạp thời gian: O(log(n) * k * sqrt(a))  
### Độ phức tạp không gian: O(max(a))
