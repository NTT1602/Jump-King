# Jump-King - NTT
- Gameplay và cách phá đảo:
# Giới thiệu game
Jump King là một tựa game thể loại jumping. Là một tựa game đơn giản tuy nhiên lại có độ khó cao, mang lại trải nghiệm có phần cay cú và khó chịu cho người chơi:). Hãy cùng cố gắng nhảy lên đỉnh và cưới công chúa nhé!
- [1. Bắt đầu game](#1-bắt-đầu-game)
- [2. Cách chơi](#2-cách-chơi)
- [3. Chiến thắng](#3-chiến-thắng)
- [Về source code game](#về-source-code-game)
- [Về đồ họa của game](#về-đồ-họa-của-game)
### 1. Bắt đầu game
- Sau khi màn hình chờ của game đã xuất hiện, hãy ấn space để bắt đầu game.
![Waiting Screen](https://github.com/NTT1602/Jump-King/blob/main/Jump%20King/waiting%20screen.jpg)
- Sau đó bạn sẽ ngay lập tức bắt đầu ở tầng thấp nhất của tựa game.
![image](https://github.com/NTT1602/Jump-King/blob/main/Jump%20King/anhmau1.png)

### 2. Cách chơi
- Sử dụng nút mũi tên để di chuyển sang trái phải
![image2](https://github.com/NTT1602/Jump-King/blob/main/Jump%20King/anhmau2.png)
- Giữ nút space để nhảy (đặc biệt giữ càng lâu sẽ nhảy càng cao)
![image3](https://github.com/NTT1602/Jump-King/blob/main/Jump%20King/anhmau3.png)
- Hãy cẩn thận đừng để bị rơi nhé(và đừng để bị đập đầu sẽ bị ngã:))

### 3. Chiến thắng
- Có một cô công chúa xinh đẹp ở trên đỉnh
![image4](https://github.com/NTT1602/Jump-King/blob/main/Jump%20King/anhmau4.png)
- Hãy cố gắng chạm được vào cô ấy và bạn sẽ giành chiến thắng
![image5](https://github.com/NTT1602/Jump-King/blob/main/Jump%20King/anhmau5.png)
### Về source code game
- Folder graphics:
  - Khởi tạo window và renderer
  - Chứa hầu hết các câu lệnh của SDL2, SDL2_image, SDL2_ttf, sử dụng để vẽ load ảnh, chữ và vẽ lên renderer, window.
- Folder defs:
  - Chứa các thông số của game
- Folder animation:
  - Tạo hoạt họa di chuyển cho nhân vật
- Folder colliding:
  - Xử lí va chạm
- Folder movements:
  - Xử lý phần di chuyển, nhảy của nhân vật
- Folder platforms:
  - Xây dựng map 
  - Chứa tọa độ của các bậc để nhảy lên
  
### Về đồ họa của game
- Nguồn tham khảo đồ họa: https://github.com/Code-Bullet/Jump-King (các level, model nhân vật)
