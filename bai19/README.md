# Thuật toán tầm thường
## Ý tưởng: thử và sai  
Bước 1: Thực hiện thử đào vị trí thấp nhất (giảm đi 1 đơn vị)  
Bước 2: Thực hiện cân bằng lại vùng đất đó  
Bước 3:  
      + Nếu quá trình cân bằng kết thúc mà T == 0  thì không đào thêm được nữa --> trả về vị trí đào  
      + Nếu T > 0 thì ta quay lại bước 1  
      + Nếu T < 0 thì việc đào trước đó không thể được --> hoàn lại bước 1 --> trả về vị trí đào + 1
### Độ phức tạp thời gian: O(T * n)
### Độ phức tạp không gian: O(1)

# Thuật toán cải tiến
## Ý tưởng: cân bằng trước rồi đào sau  
Bước 1: điều kiện để đào vị trí min là các vị trí kế nó phải bằng nó  
Bước 2: Ta thực hiện cập nhật các vị trí trong vùng đất trừ vị trí min theo phương pháp:  
    + Vị trí p chỉ bị giảm nếu khoảng cách so với vị trí kế bên lớn hơn 1  
    + Nếu p là vị trí kế min thì kiểm tra có bằng hay không? Nếu không thì tìm cách hạ xuống  
Bước 3: Sau khi đã đưa vào vị trí cân bằng thì nếu T > 0 thì hạ min  
**Với thuật toán này ta chỉ cần 1 con trỏ để di chuyển trên toàn mảng**
### Độ phức tạp thời gian: O(n)
### Độ phức tạp không gian: O(1)
