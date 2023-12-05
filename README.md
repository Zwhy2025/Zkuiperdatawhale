#  docker operation
```
- 创建容器
-- windows 
docker run -it -p 7860:22 registry.cn-hangzhou.aliyuncs.com/hellofss/kuiperinfer:datawhale /bin/bash
-- linux
sudo docker run -it registry.cn-hangzhou.aliyuncs.com/hellofss/kuiperinfer:datawhale /bin/bash

- 进入容器
-- all
docker start admiring_diffie
docker exec -it admiring_diffie /bin/bash



```