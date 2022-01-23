# Thuật toán tầm thường  
## Ý tưởng  
Thực hiện vét cạn bằng cách duyệt từng vị trí trong mảng a, sau đó so sánh chuỗi được trích ra từ a tại i với độ dài là b.size() và trả kết quả

### Độ phức tạp thời gian: O(b.size()^2)
### Độ phức tạp không gian: O(b.size())

# Thuật toán cải tiến
## Ý tưởng
Ta thực hiện đệ quy với việc chia mảng thành 2 đoạn, đoạn đầu là i + b.size() và đoạn sau là i + 1 --> a.size()  
Đoạn đầu sẽ dùng substr để kiểm còn đoạn sau ta gọi lại hàm cha

### Độ phức tạp thời gian: O(log(a.size()) * b.size())  
### Độ phức tạp không gian: O(log(a.size() * b.size())
