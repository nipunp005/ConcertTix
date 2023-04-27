FROM ubuntu:latest

RUN apt-get update && apt-get install -y build-essential

RUN apt-get install -y git

RUN git clone https://github.com/cpputest/cpputest.git

WORKDIR /cpputest/cpputest_build

RUN apt-get install -y autoconf && apt-get install -y libtool

RUN autoreconf .. -i

RUN ../configure

RUN make && make install

RUN mkdir docker-app/

WORKDIR docker-app/

COPY inc/ ./inc/

COPY src/ ./src/

COPY test/ ./test/

COPY Makefile .

RUN ls

RUN make all

CMD ["./build/booking_app"]

