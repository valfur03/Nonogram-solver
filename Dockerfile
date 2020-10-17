FROM ubuntu:20.04

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get install -y gcc make

COPY . .

RUN make

ENTRYPOINT ["./nosolve"]
