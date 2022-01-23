# Thuật toán tầm thường  
## Ý tưởng  
Thực hiện vét cạn bằng cách duyệt từng cặp a[i], b[j] trong mảng a và b để tìm abs(a[i] + b[j]) min

### Độ phức tạp thời gian: O(n * m)
### Độ phức tạp không gian: O(1)

# Thuật toán cải tiến
## Ý tưởng
Tạo 1 mảng được sắp xếp bằng **Quick Sort** tăng dần cho mảng a ở nửa đầu và mảng b ở phần sau.  
Ta thực hiện kĩ thuật 2 con trỏ để duyệt từng cặp, nếu abs == 0  thì kết thúc, nếu != 0 thì ưu tiên là tiến về gần 0 nhất bằng giảm biên phải nếu abs > 0, tăng biên trái nếu abs < 0  

### Độ phức tạp thời gian: O(nlog(n)) + O(mlog(m)) + O(m + n)  
### Độ phức tạp không gian: O(log(n)) + O(log(m)) + O(m + n)
