# 03.29.2022 - Docker/Tutorial nào!!!!
Sắp tới mình sẽ học môn Cơ sở dữ liệu, nghe nói sẽ được tiếp xúc với MySQL các thứ các thứ :v. Thực ra đến giờ mình vẫn chả biết gì đâu, nhưng hiện tại mình đang dùng `OS` chính là `Arch Linux` (yeah, I use Arch btw), trong khi MySql chỉ chạy được trên `win` thôi, mà mình lại từng nghe qua [Docker](https://www.docker.com/) sẽ giải quyết được vấn đề này. Nên mình tiện đây sẽ tìm hiểu về Docker luôn!

Hôm nay sẽ chỉ nói về cách download Docker và setup chuẩn chỉ thôi nhỉ (vì chưa tìm hiểu được j nhiều :v). 

Dùng package manager của Os linux mà tải thôi. Như trên Arch thì: `sudo pacman -S docker` hoặc chơi bản dev thì tải bản git qua AUR `yay -S docker-git`. 

Chạy docker và autostartup:
```bash
$ systemctl start docker.service
$ systemctl enable docker.service
```
Check version và xem có ok không bằng `docker info` nào!!
Docker cần chạy với quyền `root`, nên nếu run ngay `docker info` thì sẽ bị permission denied. 
```bash
$ docker info
Client:
 Context:    default
 Debug Mode: false
 Plugins:
  buildx: Docker Buildx (Docker Inc., v0.8.1-docker)

Server:
ERROR: Got permission denied while trying to connect to the Docker daemon socket at unix:///var/run/docker.sock: Get "http://%2Fvar%2Frun%2Fdocker.sock/v1.24/info": dial unix /var/run/docker.sock: connect: permission denied
errors pretty printing info
```
Đơn giản nhất thì tạo 1 cái group docker rồi add nó vào cho user thôi. 
```bash
$ groupadd docker 
$ gpasswd -a %USERNAME docker
```
Done! và như bao thứ khác từ khi mình dấn thân vào con đường gõ phím này, xác nhận bắt đầu tìm hiểu 1 tools mới bằng super project `hello-world`:
```bash
$ docker run hello-world
Unable to find image 'hello-world:latest' locally
latest: Pulling from library/hello-world
2db29710123e: Pull complete
Digest: sha256:bfea6278a0a267fad2634554f4f0c6f31981eea41c553fdf5a83e95a41d40c38
Status: Downloaded newer image for hello-world:latest

Hello from Docker!
This message shows that your installation appears to be working correctly.

To generate this message, Docker took the following steps:
 1. The Docker client contacted the Docker daemon.
 2. The Docker daemon pulled the "hello-world" image from the Docker Hub.
    (amd64)
 3. The Docker daemon created a new container from that image which runs the
    executable that produces the output you are currently reading.
 4. The Docker daemon streamed that output to the Docker client, which sent it
    to your terminal.

To try something more ambitious, you can run an Ubuntu container with:
 $ docker run -it ubuntu bash

Share images, automate workflows, and more with a free Docker ID:
 https://hub.docker.com/

For more examples and ideas, visit:
 https://docs.docker.com/get-started/

```

### Ref
* https://hub.docker.com/
* https://linuxhint.com/arch-linux-docker-tutorial/

# 03.28.2022 - Kiến trúc máy tính/Little endian và Big endian.
## Về cái tiêu đề 
* Cả Little endian và Big endian là các cách mà máy tính hiểu và cách thức đọc dữ liệu tư `input` của chúng ta. Bình thường ta hay đọc theo thứ tự từ trái sang phải, nhưng không phải máy tính nào cũng đọc giống thế cả, mà chúng cũng thích tự có cách đọc riêng cơ 🤣.
* Little endian hay Little-end, là cách đọc mà các byte ở vị trí nhỏ nhất (nôm na là lại đọc số  từ hàng đơn vị) sẽ được đọc trước. Điều ngược lại với Big endian - đọc các byte giống với con người.
* Lưu ý rằng sự khác biệt chỉ đến từ vị trí của các byte, còn thứ tự các bit trong 1 byte thì vẫn không đổi. Nên nếu dữ liệu chỉ gồm 1 byte, thì 2 kiến trúc này không có sự khác biệt. 
* Mình tìm hiểu được thì các chip [intel](https://en.wikipedia.org/wiki/Endianness#:~:text=However%2C%20as%20Intel%20was%20unable%20to%20deliver%20the%208008%20in%20time%2C%20Datapoint%20used%20a%20medium%20scale%20integration%20equivalent%2C%20but%20the%20little%2Dendianness%20was%20retained%20in%20most%20Intel%20designs%2C%20including%20the%20MCS%2D48%20and%20the%208086%20and%20its%20x86%20successors.) theo kiến trúc Little endian này. 

### Yeah! 
Hôm nay là ngày đầu tiên quay lại trường học sau gần 11 tháng học off. Có khá nhiều cảm xúc đan xen :v, vui có mà buồn cũng có.
Nhưng giờ không phải là lúc để than thở bạn ơi! Từ giờ sẽ cố gắng rèn luyện thêm 1 thói quen nữa là viết blog về mỗi ngày nhé :v. 

## References 
*  https://en.wikipedia.org/wiki/Endianness
*  https://viblo.asia/p/little-endian-vs-big-endian-E375z0pWZGW



