# Thuật toán tầm thường  
## Ý tưởng  
Thực hiện vét cạn bằng cách duyệt từng vị trí.  
Tại vị trí đó, thực hiện tìm và xác nhận vị trí hiện tại
 1. Vị trí kế tiếp phải nhỏ hơn vị trí hiện --> mới có đọng mưa
 2. Phải tồn tại vị trí cao hơn hoặc bằng hiện tại --> không tràn nước mưa

### Độ phức tạp thời gian: O(n ^ 2)
### Độ phức tạp không gian: O(1)

# Thuật toán cải tiến
## Ý tưởng
Dùng kĩ thuật 1 con trỏ, dùng các biến để lưu vết và lưu các lưu lượng mưa đọng lại.  
Nếu vị trí đó > 0 và tồn tại vị trí thấp hơn kế tiếp và vị trí end (vị trí >= hiện tại) thì chọn làm start
Thực hiện duyệt tiếp nếu gặp end thì cập nhật lượng mưa.
### Độ phức tạp thời gian: O(n)  
### Độ phức tạp không gian: O(1)
