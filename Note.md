https://tinhte.vn/thread/vi-xu-li-64-bit-la-gi-va-no-giup-ich-nhu-the-nao-cho-cac-thiet-bi-dien-toan.2173158/

RAM là bộ nhớ, lại có thêm register và cache (L1, L2, L3) để làm gì? Register và cache ra đời để khắc phục hiện tượng nghẽn cổ chai khi mà tốc độ CPU quá nhanh, trong khi tốc độ RAM thì không bằng nên gây ra "thời gian chết" vì RAM không kịp đưa dữ liệu cho CPU xử lí. Như đã nói ở trên, register có tốc độ họa động cực nhanh, gần như bằng với CPU, cache thì có tốc độ thấp hơn một chút nhưng vẫn nhanh hơn nhiều so với RAM. Nếu trong register không có dữ liệu CPU cần, nó sẽ tìm trong cache. Nếu có thì xử lí, nếu không thì tiếp tục lấy từ RAM. Tương tự, nếu trong RAM vẫn chưa có dữ liệu mà CPU cần, nó sẽ tìm trong ổ lưu trữ vĩnh viễn, chính là HDD, SSD, thẻ nhớ, chip eMMC,... Càng tìm nhiều thì mất thời gian càng nhiều. Kim tự tháp ở trên chính là cấu trúc bộ nhớ máy tính và CPU sẽ tìm lần lượt từ trên xuống dưới.

Về con số 32-bit hay 64-bit, những CPU 32-bit sẽ có bộ ALU và register với độ rộng là 32-bit, còn CPU 64-bit thì sẽ có độ rộng của những thành phần này là 64-bit.

_**Mình sẽ miêu tả hoạt động của CPU qua 1 phép tính rất đơn giản:**_ **c=a+b**  
  
Để thực hiện phép toán trên thực ra cần rất nhiều bước:  
  
**Bước 1:** CPU cần biết địa chỉ, nơi cất giữ giá trị của biến a trong bộ nhớ (RAM). CPU sau đó sẽ chuyển địa chỉ đó cho 1 chiếc xe buýt, và chiếc xe buýt đó sẽ chở dữ liệu của biến a đến thanh ghi **registerA** trên CPU.

  
  
**Bước 2:** Điều tương tự sẽ diễn ra với b, dữ liệu của biến b được ghi vào thanh ghi **registerB**.  
  
**Bước 3:** ALU sẽ thực hiện phép cộng và ghi kết quả vào thanh ghi **registerC**.  
  
**Bước 4:** CPU lại gọi bus và chuyển kết quả từ **registerC** đến gán cho biến c. Khi đó giá trị của biến c sẽ được lưu trên RAM và phần mềm yêu cầu thực hiện phép tính sẽ biết được kết quả phép tính là bao nhiêu.

