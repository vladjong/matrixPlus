FROM alpine 
WORKDIR /home_adough/
COPY . /home_adough/
RUN apk add; apk add make musl-dev g++ valgrind gtest bash gtest-dev

ENTRYPOINT [ "/bin/bash" ]
